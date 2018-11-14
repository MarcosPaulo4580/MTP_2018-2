/* P6.c */
/* Marcos Paulo Arruda Freitas */
/* 11811EEL011 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	float x, y;
}Ponto;

Ponto * gera(int N)
{
	Ponto * p = (Ponto *) calloc(N, sizeof(Ponto));
	int i;
	for(i = 0; i < N; i++)
	{
		p[i].x = cos(i * 2.0 * M_PI / (N - 1));
		p[i].y = sin(i * 2.0 * M_PI / (N - 1));
	}
	return p;
}

void mostrar_pontos(Ponto * p_inicio, Ponto * p_fim)
{
	if(p_inicio < p_fim)
	{
		printf("(%.3lf, %.3lf)", p_inicio -> x, p_inicio -> y);
		mostrar_pontos(p_inicio + 1, p_fim);
	}
}

int main()
{
	unsigned int N;
	Ponto * p;
	printf("Quantos pontos voce quer? ");
	scanf("%u", &N);	getchar();
	p = gera(N);
	mostrar_pontos(p, p + N);
	free(p);
	return 0;
}

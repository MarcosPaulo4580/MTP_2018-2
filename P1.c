#include <stdio.h>
int main ()
{
	int estado = 0, i, x;
	char bits [256];
	printf ("Digite um numero binario qualquer: ");
	scanf("%s", bits);
	for (i = 0; bits[i] != '\0'; i++)
	{
		if(estado == 0)
		{
			if(bits[i] == '0')
				x = 0;
			else
				x = 1;
		}	
		if(estado == 1)
		{
			if(bits[i] == '0')
				x = 2;
			else
				x = 0;
		}
		if(estado == 2)
		{
			if(bits[i] == '0')
				x = 1;
			else
				x = 2;
		}
		estado = x;
	}
	if(estado == 0)
		printf("Numero binario digitado: %s. Este numero eh multiplo de 3.", bits);
	else
		printf("Numero binario digitado: %s. Este numero nao eh multiplo de 3.", bits);
	return 0;
}

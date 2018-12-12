/*P3.c*/
/*Marcos Paulo Arruda Freitas*/
/*11811EEL011*/
#include <stdio.h>
int main ()
{
	char bits[256];
	int i = 0, cum = 0;
	scanf("%s", bits);
	for(i = 0; bits[i] != '\0'; i++)
	{
		if(bits[i] >= '0' && bits[i] <= '9')
			cum = cum*10 + (bits[i] - '0');
	}
	printf("\n%d", cum);
}

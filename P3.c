/*P3.c/
/Marcos Paulo Arruda Freitas/
/11811EEL011*/
#include <stdio.h>
int main ()
{
	char bits[256];
	int i, cum = 0;
	fflush(stdin);
	gets(bits);
	for(i = 0; bits[i] != '\0'; i++)
	{
		if(bits[i] > 47 && bits[i] < 58)
			cum = cum*10 + (bits[i] - 48);
	}
	printf("\n%d", cum);
	return 0;
}

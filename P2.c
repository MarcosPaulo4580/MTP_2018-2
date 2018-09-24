/*P2.c*/
/*Marcos Paulo Arruda Freitas*/
/*11811EEL011*/
#include <stdio.h>
void binario_decimal(char num[])
{
	int len, i, decimal=0, parcela, j;
	for(len=0;num[len]!='\0';len++);
	for(i=0;i<=len;i++)
	{
		if(num[len-i]=='1')
		{
			parcela=1;
			for(j=1;j<i;j++)
			parcela*=2;
			decimal+=parcela;
		}
	}
	printf("%d",decimal);
}
void binario_hexadecimal(char bin[]){
	int caractere, len, posbin, poshex=0,q,parcela,j;
	for(len=0;bin[len]!='\0';len++);
	char hex[len/4];
	
	for(posbin=0;bin[posbin]!='\0';posbin+=4){
		caractere=0;
		for(q=posbin;q<posbin+4;q++)
		{
			parcela = 1;
			if(bin[q]=='1'){
			for(j=0;j<3-(q-posbin);j++)
			parcela*=2;
			caractere+=parcela;
			}
		}
		if(caractere<10)
		hex[poshex]=caractere+48;
		else
		hex[poshex]=caractere+55;
		poshex=q/4;

	}
	printf("%s",hex);
}
void hexadecimal_decimal(char shex[]){
	int len, dec=0, i, parcela, pot;
	for(len=0;shex[len]!='\0';len++);
	int hex[len];
	for(i=0;i<len;i++)
	{
		if(shex[i]>=48 && shex[i]<=57)
		hex[i]=shex[i]-48;
		if(shex[i]>=65 && shex[i]<=70)
		hex[i]=shex[i]-55;
		if(shex[i]>=97 && shex[i]<=102)
		hex[i] = shex[i]-87;
	}
	for(i=0;i<len;i++)
	{
		parcela=1;
		for(pot=0;pot<len-i-1;pot++)
		parcela*=16;
		dec+=parcela*hex[i];
	}
	printf("%d",dec);
}
void hexadecimal_binario(char shex[256]){
	int len, primeiro;
	for(len=0;shex[len]!='\0';len++);
	int hex[len], i, j;
	int bin[len][4];
	for(i=0;i<len;i++)
	{
		if(shex[i]>=48 && shex[i]<=57)
		hex[i]=shex[i]-48;
		if(shex[i]>=65&&shex[i]<=70)
		hex[i]=shex[i]-55;
		if(shex[i]>=97 && shex[i]<=102)
		hex[i]=shex[i]-87;
	}
	for(i=0;i<len;i++)
	{
		for(j=0;j<4;j++)
		{
			bin[i][3-j] = hex[i]%2;
			hex[i]/=2;
		}
	}
	for(j=0;j<4;j++)
	{
		if(bin[0][j]==1)
		{
			primeiro = j;
			break;
		}
	}
	for(j=primeiro;j<4;j++)
	printf("%d",bin[0][j]);
	for(i=1;i<len;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d",bin[i][j]);
		}
	}
}
void decimal_binario(int dec){
	int nb, i;
	for(nb=0;dec>=(1<<nb);nb++);
	int bin[nb];
	for(i=0;nb-1-i>=0;i++)
	{
		bin[nb-1-i]=dec%2;
		dec/=2;
	}
	for(i=0;i<nb;i++)
	printf("%d",bin[i]);
}
int main()
{
	int opc, num;
	char snum[256];
	scanf("%d",&opc);
	switch(opc){
		case 1:
			scanf("%s",snum);
			binario_decimal(snum);
			break;
		case 2:
			scanf("%s",snum);
			binario_hexadecimal(snum);
			break;
		case 3:
			scanf("%s",snum);
			hexadecimal_decimal(snum);
			break;
		case 4:
			scanf("%s",snum);
			hexadecimal_binario(snum);
			break;
		case 5:
			scanf("%d",&num);
			decimal_binario(num);
			break;
		case 6:
			scanf("%d",&num);
			printf("%x",num);
			break;
		case 7:
			scanf("%o",&num);
			printf("%d",num);
			break;
		case 8:
			scanf("%d",&num);
			printf("%o",num);
			break;				
	}
}

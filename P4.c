/*P4.c/
/Marcos Paulo Arruda Freitas/
/11811EEL011*/
#include <stdio.h>
int A(int m, int n)
{
	if(m == 0)
		return (n + 1);
	if(m > 0 && n == 0)
		return A(m - 1, 1);
	if(m > 0 && n > 0)
		return A(m - 1, A(m, n - 1));
}
int main ()
{
	int m, n;
	scanf("%d %d", &m, &n);
	printf("\n%d", A(m, n));
	return 0;
}

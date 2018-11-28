#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d\n", &x);
	x = (x*sizeof(x));
	printf("%d\n", x);
	return 0;
}

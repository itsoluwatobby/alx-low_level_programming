#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - program that assigns a random numbeer to a variablee when executed
 * Return: 0 (success)
*/
int main(void)
{
	int n;
	int m;
	char mem[] = "Last digit of";

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	m = n % 10;

if (m > 5)
{
	printf("%s %d is %d and is greater than 5\n", mem, n, m);
}
else if (m == 0)
{
	printf("%s %d is %d and is 0\n", mem, n, m);
}
else if (m < 0 && m != 0)
{
	printf("%s %d is %d and is less than 6 and not 0\n", mem, n, m);
}
return (0);
}

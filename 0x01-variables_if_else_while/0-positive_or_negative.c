#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - program that assigns a random number to a variable when executed
 * Return: 0 (success)
*/
int main(void)
{
	int n;
	srand(time(0));
	n = rand();

	if (n > 0)
	{
		printf("is positive\n");
	}
	else if (n == 0)
	{
		printf("is zero\n");
	}
	else
	{
		printf("is negative\n");
	}

	return (0);
}

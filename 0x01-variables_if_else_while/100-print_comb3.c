#include <stdio.h>
/**
 * main -  program that prints all possible combinations of two digits
 * Return: 0 (success)
 */
int main(void)
{
        int i;

        for (i = 0; i < 10; i++)
        {
		putchar(i + '0');
                if (i < i+1)
                {
                        putchar('0');
                        putchar(i + '0');
                }
                else
                {

                }
                putchar(',');
                putchar(' ');
        }
        return (0);
}

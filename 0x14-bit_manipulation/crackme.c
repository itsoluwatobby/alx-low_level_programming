#include <string.h>
#include <stdio.h>
#include <aio.h>

int check(char *pwd);

/**
 * check - function that checks the password
 * @pwd: 1st parameter
 * Return: 0 or 1 on success
*/

int check(char *pwd)
{
	size_t var1;
	int var2;
	int local;

	var1 = strlen(pwd);
	if (var1 == 4)
	{
		for (local = 0; local < 4; local++)
		{
			if ((uint)(int)pwd[local] != (0x46c6f48U >> ((local & 3) << 3) & 0xff))
				return (0);
		}
		var2 = 1;
	}
	else
		var2 = 0;
	return (var2);
}

/**
 * main - main function to run the crackme program
 * @pwd1: 1st parameter
 * @pwd2: 2nd parameter
 * Return: result
*/ 

int main(int pwd1, char *pwd2)
{
	int var1;
	int  var2;

	if (pwd1 == 2)
	{
		var1 = check(pwd2[1]);
		if (var1 == 1)
		{
			puts("Congratulations!");
			var2 = 0;
		}
		else
		{
			puts("ko");
			var2 = 1;
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s password\n", *pwd2);
		var2 = 1;
	}
	return (var2);
}

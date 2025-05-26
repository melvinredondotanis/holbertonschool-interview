#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 *
 * @n: the number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int i;
	char str[21];
	int n_size;

	sprintf(str, "%lu", n);
	n_size = strlen(str) - 1;
	for (i = 0; i <= n_size; i++)
		if (str[i] != str[n_size - i])
			return (0);
	return (1);
}

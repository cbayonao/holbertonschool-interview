#include "palindrome.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
/**
 * is_palindrome - Function that verify if a long int is  palindrome
 * @n: unsigned long to check
 * Return: 1 if is a palinrome or 0 instead
 */

int is_palindrome(unsigned long n)
{
	unsigned long r, sum = 0, t;

	for (t = n; n != 0; n = n / 10)
	{
		r = n % 10;
		sum = sum * 10 + r;
	}
	if (t == sum)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

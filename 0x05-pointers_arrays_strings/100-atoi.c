#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, lens, h, digit;

	i = 0;
	d = 0;
	n = 0;
	lens = 0;
	h = 0;
	digit = 0;

	while (s[lens] != '\0')
		lens++;

	while (i < lens && h == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			h = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			h = 0;
		}
		i++;
	}

	if (h == 0)
		return (0);

	return (n);
}

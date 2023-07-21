#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */

void print_all(const char * const format, ...)
{
	int i = 0;
	char *wd, *lin = "";

	va_list list;

	va_start(list, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", lin, va_arg(list, int));
					break;
				case 'i':
					printf("%s%d", lin, va_arg(list, int));
					break;
				case 'f':
					printf("%s%f", lin, va_arg(list, double));
					break;
				case 's':
					wd = va_arg(list, char *);
					if (!wd)
						wd = "(nil)";
					printf("%s%s", lin, wd);
					break;
				default:
					i++;
					continue;
			}
			lin = ", ";
			i++;
		}
	}

	printf("\n");
	va_end(list);
}

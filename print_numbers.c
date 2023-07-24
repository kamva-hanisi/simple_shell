#include "shell_main.h"

/**
 * big_numbers - Print whole numbers
 * @number: long int
 * Return: number
 */
int big_numbers(long int number)
{
	int base_value = 10, count = 0, aux;

	if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		count++;
	}
	else
	{
		while (number / base_value > 9)
		{
			base_value *= 10;
		}

		while (base_value > 0)
		{
			aux = number / base_value;
			number = number % base_value;
			_putchar(aux + 48);
			base_value = base_value / 10;
			count++;
		}
	}

	return (count);
}

/**
 * print_int - Print numbers
 * @args: variable va_list
 * Return: k (nbytes) or (NULL)
 */
int print_int(int number)
{
	int count = 0;

	if (number < 0)
	{
		number *= -1;
		_putchar(45);
		count++;

		count += big_numbers(number);
	}
	else if (number >= 0 && number <= 9)
	{
		_putchar(number + 48);
		count++;
	}
	else if (number > 9)
	{
		count += big_numbers(number);
	}

	return (count);
}


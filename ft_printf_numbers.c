/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:36:25 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 09:48:11 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_length(long long nbr)
{
	int	length;

	length = 0;
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		length++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length + 1);
}

int	hex_length(unsigned long int nbr)
{
	int	length;

	length = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		length++;
	}
	return (length + 1);
}

int	converter(char *str, long long nbr, int index)
{
	while (nbr > 0)
	{
		str[index] = (nbr % 10 + 48);
		nbr = nbr / 10;
		index--;
	}
	return (index);
}

int	hex_converter(char *str, unsigned long int nbr, int index, char c)
{
	while (nbr > 0)
	{
		if (nbr % 16 > 9)
		{
			if (c == 'x' || c == 'p')
				str[index] = nbr % 16 - 10 + 97;
			else
				str[index] = nbr % 16 - 10 + 65;
		}
		else
			str[index] = nbr % 16 + 48;
		nbr = nbr / 16;
		index--;
	}
	return (index);
}

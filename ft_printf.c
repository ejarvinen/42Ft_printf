/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:54:50 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 09:47:46 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printstr(va_list args, t_stats *stats)
{
	char	*string;

	string = va_arg(args, char *);
	if (!string)
		return (ft_putstr("(null)", stats));
	else
		return (ft_putstr(string, stats));
}

static void	print_ptr(va_list args, t_stats *stats)
{
	char	*string;

	string = ft_ptr_itoa(va_arg(args, unsigned long int), 'p', stats);
	if (string)
	{
		ft_putstr("0x", stats);
		if (stats->error == 0)
		{
			ft_putstr(string, stats);
			if (stats->error == 0)
			{
			}
		}
	}
	free(string);
}

static void	nbr_handler(va_list args, t_stats *stats, int c)
{
	char	*string;

	if (c == 'd' || c == 'i')
		string = ft_itoa_printf(va_arg(args, int), stats);
	if (c == 'u')
		string = ft_u_itoa(va_arg(args, unsigned int), stats);
	if (c == 'x')
		string = ft_hex_itoa(va_arg(args, int), 'x', stats);
	if (c == 'X')
		string = ft_hex_itoa(va_arg(args, int), 'X', stats);
	if (string)
	{
		ft_putstr(string, stats);
		if (stats->error == 0)
		{
		}
	}
	free(string);
}

static void	printf_helper(int s, va_list args, t_stats *stats)
{
	if (s == '%')
		ft_putchar(s, stats);
	else if (s == 'c')
		ft_putchar(va_arg(args, int), stats);
	else if (s == 's')
		printstr(args, stats);
	else if (s == 'p')
		print_ptr(args, stats);
	else if (s == 'd' || s == 'i')
		nbr_handler(args, stats, s);
	else if (s == 'u')
		nbr_handler(args, stats, s);
	else if (s == 'x')
		nbr_handler(args, stats, s);
	else if (s == 'X')
		nbr_handler(args, stats, s);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_stats	stats;

	va_start(args, str);
	stats.chrs_written = 0;
	stats.error = 0;
	while (*str != '\0' && stats.error == 0)
	{
		stats.error = 0;
		if (*str == '%')
		{
			str++;
			printf_helper(*str, args, &stats);
		}
		else
			ft_putchar(*str, &stats);
		str++;
	}
	va_end(args);
	if (stats.error < 0)
		return (-1);
	return (stats.chrs_written);
}

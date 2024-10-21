/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puteverything.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:16:58 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 09:48:08 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, t_stats *stats)
{
	if (stats->error == -1)
	{
	}
	else if (write(1, &c, 1) >= 0)
		stats->chrs_written = stats->chrs_written + 1;
	else
		stats->error = -1;
}

void	ft_putstr(char *str, t_stats *stats)
{
	while (*str != '\0' && stats->error != -1)
	{
		ft_putchar(*str, stats);
		str++;
	}
}

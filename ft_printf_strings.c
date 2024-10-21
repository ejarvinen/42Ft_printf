/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:18:17 by emansoor          #+#    #+#             */
/*   Updated: 2024/10/21 09:48:05 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup_printf(const char *str, t_stats *stats)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ptr != NULL)
	{
		while (str[i] != '\0')
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	stats->error = -1;
	return (0);
}

char	*ft_u_itoa(int n, t_stats *stats)
{
	int			index;
	char		*str;
	int			digit_count;
	long long	nbr;

	nbr = (long long)n;
	if (nbr == 0)
		return (ft_strdup_printf("0", stats));
	if (nbr < 0)
		nbr = nbr + 4294967295 + 1;
	digit_count = num_length(nbr);
	str = (char *)malloc(sizeof(char) * digit_count);
	if (str != NULL)
	{
		index = 0;
		str[digit_count - 1] = '\0';
		index = converter(str, nbr, digit_count - 2);
		return (str);
	}
	stats->error = -1;
	return (NULL);
}

char	*ft_hex_itoa(long n, char c, t_stats *stats)
{
	int			index;
	char		*str;
	long long	nbr;
	int			digit_count;

	nbr = (long long)n;
	if (nbr == 0)
		return (ft_strdup_printf("0", stats));
	if (nbr < 0)
		nbr = nbr + 4294967295 + 1;
	digit_count = hex_length(nbr);
	str = (char *)malloc(sizeof(char) * digit_count);
	if (str != NULL)
	{
		index = 0;
		str[digit_count - 1] = '\0';
		index = hex_converter(str, nbr, digit_count - 2, c);
		return (str);
	}
	stats->error = -1;
	return (NULL);
}

char	*ft_ptr_itoa(unsigned long int n, char c, t_stats *stats)
{
	int		index;
	char	*str;
	int		digit_count;

	if (n == 0)
		return (ft_strdup_printf("0", stats));
	digit_count = hex_length(n);
	str = (char *)malloc(sizeof(char) * digit_count);
	if (str != NULL)
	{
		index = 0;
		str[digit_count - 1] = '\0';
		index = hex_converter(str, n, digit_count - 2, c);
		return (str);
	}
	stats->error = -1;
	return (NULL);
}

char	*ft_itoa_printf(int n, t_stats *stats)
{
	int		index;
	char	*str;
	int		digit_count;
	long	nbr;

	nbr = (long)n;
	if (nbr == 0)
		return (ft_strdup_printf("0", stats));
	digit_count = num_length(nbr);
	str = (char *)malloc(sizeof(char) * digit_count);
	if (str != NULL)
	{
		index = 0;
		str[digit_count - 1] = '\0';
		if (nbr < 0)
		{
			str[index] = '-';
			nbr = nbr * (-1);
		}
		index = converter(str, nbr, digit_count - 2);
		return (str);
	}
	stats->error = -1;
	return (NULL);
}

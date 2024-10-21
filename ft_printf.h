/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emansoor <emansoor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:04:32 by emansoor          #+#    #+#             */
/*   Updated: 2023/12/17 13:22:16 by emansoor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct t_stats {
	int	chrs_written;
	int	error;
}				t_stats;	

int		ft_printf(const char *str, ...);
char	*ft_itoa_printf(int n, t_stats *stats);
char	*ft_hex_itoa(long n, char c, t_stats *stats);
char	*ft_u_itoa(int n, t_stats *stats);
char	*ft_ptr_itoa(unsigned long int n, char c, t_stats *stats);
int		hex_converter(char *str, unsigned long int nbr, int index, char c);
int		converter(char *str, long long nbr, int index);
int		hex_length(unsigned long int nbr);
int		num_length(long long nbr);
void	ft_putstr(char *str, t_stats *stats);
void	ft_putchar(int c, t_stats *stats);

#endif

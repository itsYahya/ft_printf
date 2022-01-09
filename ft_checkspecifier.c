/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkspecifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:46:46 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/27 13:00:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkspecifier(char ch, t_data data, va_list ap)
{
	if (ch == 's')
		return (ft_putstr(va_arg(ap, char *), data));
	else if (ch == 'c')
		return (ft_putchar(va_arg(ap, int), data));
	else if (ch == 'd' || ch == 'i')
		return (ft_putnumbers(va_arg(ap, int), data));
	else if (ch == 'u')
		return (ft_put_unsigned_numbers(va_arg(ap, unsigned int), data));
	else if (ch == 'x' || ch == 'X')
		return (ft_put_hexa(va_arg(ap, unsigned int), data, ch));
	else if (ch == 'p')
		return (ft_print_meme(va_arg(ap, unsigned long), data));
	else
		return (ft_putchar(ch, data));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:17:27 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/29 14:09:25 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

static int	ft_min(int arg1, int arg2)
{
	if (arg1 < arg2)
		return (arg1);
	return (arg2);
}

int	ft_putstr(char *str, t_data data)
{
	int	width;
	int	printed;
	int	len;

	if (!str)
		str = "(null)";
	if (data.point.point)
		len = ft_min(ft_strlen(str), data.point.width);
	else
		len = ft_strlen(str);
	width = data.width - len;
	printed = ft_max(data.width, len);
	while (width-- > 0 && !data.minus)
		write(1, " ", 1);
	write(1, str, len);
	while (width-- > -1 && data.minus)
		write(1, " ", 1);
	return (printed);
}

int	ft_putchar(char ch, t_data data)
{
	int	width;
	int	printed;

	width = data.width - 1;
	printed = ft_max(data.width, 1);
	while (width-- > 0 && !data.minus)
		write(1, &data.sup, 1);
	write(1, &ch, 1);
	while (width-- > -1 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

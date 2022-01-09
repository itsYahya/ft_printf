/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:11 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/27 13:34:20 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_do_the_math(int *width, int *point, int number, t_data *data)
{
	int	printed;
	int	count;
	int	supp;

	if (number < 0)
		count = ft_countdigits(-number, 10);
	else
		count = ft_countdigits(number, 10);
	*point = data->point.width - count;
	*width = data->width - ft_max(data->point.width, count)
		- ((number < 0) || data->space || (data->plus && number >= 0));
	supp = ((number < 0) || (data->plus && (number >= 0)) || data->space);
	printed = ft_max(data->width - supp, ft_max(data->point.width, count))
		+ supp;
	if (point <= 0)
		data->point.point = 0;
	data->count_d = count;
	if (number == 0 && data->point.point && data->point.width == 0)
	{
		*width += 1;
		if (ft_max(data->width - supp, ft_max(data->point.width, count))
			== ft_max(data->point.width, count))
			printed--;
	}
	return (printed);
}

static long	ft_front(int number, t_data data, int width, int width_point)
{
	long	num;

	if (number >= 0 && data.space && !data.plus)
		write(1, " ", 1);
	if (number < 0)
	{
		if (data.sup == '0')
			write(1, "-", 1);
		num = -number;
	}
	else
	{
		if (data.sup == '0' && data.plus)
			write(1, "+", 1);
		num = number;
	}
	while (width-- > 0 && !data.minus)
		write(1, &data.sup, 1);
	if (data.sup != '0' && number < 0)
		write(1, "-", 1);
	else if (data.sup != '0' && number >= 0 && data.plus)
		write(1, "+", 1);
	while (width_point-- > 0)
		write(1, "0", 1);
	return (num);
}

int	ft_putnumbers(int number, t_data data)
{
	long	num;
	int		width;
	int		width_point;
	int		printed;

	printed = ft_do_the_math(&width, &width_point, number, &data);
	num = ft_front(number, data, width, width_point);
	if (number == 0 && data.point.point && data.point.width == 0)
	{
		while (width-- > 0 && data.minus)
			write(1, &data.sup, 1);
		return (printed);
	}
	ft_printf_digits(num, 10, "0123456789");
	while (width-- > 0 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:10:17 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/27 13:28:32 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_zero_(int width, int width_point, int printed, t_data data)
{
	while (width-- > -1 && !data.minus)
		write(1, &data.sup, 1);
	while (width_point-- > 0)
		write(1, "0", 1);
	while (width-- > -2 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

int	ft_put_unsigned_numbers(unsigned int number, t_data data)
{
	int	count;
	int	width;
	int	width_point;
	int	printed;

	count = ft_countdigits(number, 10);
	width_point = data.point.width - count;
	width = data.width - ft_max(data.point.width, count);
	printed = ft_max(data.width, ft_max(data.point.width, count));
	if (number == 0 && data.point.point && !data.point.width)
		return (ft_zero_(width, width_point, printed, data));
	while (width-- > 0 && !data.minus)
		write(1, &data.sup, 1);
	while (width_point-- > 0)
		write(1, "0", 1);
	ft_printf_digits(number, 10, "0123456789");
	while (width-- > -1 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

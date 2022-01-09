/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supplement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:28:51 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/27 13:39:53 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_max(int arg1, int arg2)
{
	if (arg1 > arg2)
		return (arg1);
	return (arg2);
}

int	ft_countdigits(unsigned int number, unsigned int base_len)
{
	int	index;

	index = 0;
	while (number >= base_len)
	{
		index++;
		number /= base_len;
	}
	return (++index);
}

void	ft_printf_digits(unsigned int number, unsigned int base_len, char *base)
{
	if (number >= base_len)
	{
		ft_printf_digits(number / base_len, base_len, base);
		ft_printf_digits(number % base_len, base_len, base);
	}
	else
		write(1, &base[number], 1);
}

t_data	ft_newdata(void)
{
	t_data	data;

	data.hashtag = 0;
	data.minus = 0;
	data.plus = 0;
	data.point.point = 0;
	data.point.width = 0;
	data.width = 0;
	data.sup = ' ';
	data.hashtag_sup = 0;
	data.space = 0;
	data.count_d = 0;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:28:19 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/27 13:23:28 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_getbase(char ch, t_data *data)
{
	if (ch == 'x')
	{
		data->hashtag_sup = "0x";
		return ("0123456789abcdef");
	}
	data->hashtag_sup = "0X";
	return ("0123456789ABCDEF");
}

static void	ft_null_case(int width, int point, unsigned int hex, t_data data)
{
	if (data.hashtag && data.sup == '0' && hex)
		write(1, data.hashtag_sup, 2);
	while (width-- > -1 && !data.minus)
		write(1, &data.sup, 1);
	if (data.hashtag && data.sup != '0' && hex)
		write(1, data.hashtag_sup, 2);
	while (point-- > 0)
		write(1, "0", 1);
	while (width-- > -2)
		write(1, &data.sup, 1);
}

static void	ft_normall_case(int width, int point, unsigned int hex, t_data data)
{
	if (data.hashtag && data.sup == '0' && hex)
		write(1, data.hashtag_sup, 2);
	while (width-- > -0 && !data.minus)
		write(1, &data.sup, 1);
	if (data.hashtag && data.sup != '0' && hex)
		write(1, data.hashtag_sup, 2);
	while (point-- > 0)
		write(1, "0", 1);
}

int	ft_put_hexa(unsigned int hex, t_data data, char ch)
{
	int		count;
	int		width;
	int		width_point;
	int		printed;
	char	*base;

	base = ft_getbase(ch, &data);
	count = ft_countdigits(hex, 16);
	width_point = data.point.width - count;
	width = data.width - ft_max(data.point.width, count) - (data.hashtag * 2);
	printed = ft_max(data.width, ft_max(count, data.point.width))
		+ (data.hashtag * 2 * (hex != 0));
	if (hex == 0 && data.point.point && !data.point.width)
	{
		ft_null_case(width, width_point, hex, data);
		return (printed);
	}
	ft_normall_case(width, width_point, hex, data);
	ft_printf_digits(hex, 16, base);
	while (width-- > 0 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

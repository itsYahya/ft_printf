/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_meme.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:52:43 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/27 13:07:20 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_meme_count(unsigned long meme)
{
	int	index;

	index = 0;
	while (meme >= 16)
	{
		index++;
		meme /= 16;
	}
	return (++index);
}

static void	ft_put_meme(unsigned long meme, char *base)
{
	if (meme >= 16)
	{
		ft_put_meme(meme / 16, base);
		ft_put_meme(meme % 16, base);
	}
	else
		write(1, &base[meme], 1);
}

static int	ft_zero_case(int width, int width_point, int printed, t_data data)
{
	while (width-- > -1 && !data.minus)
		write(1, &data.sup, 1);
	if (data.sup != '0')
		write(1, "0x", 2);
	while (width_point-- > 0)
		write(1, "0", 1);
	while (width-- > -2 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

int	ft_print_meme(unsigned long meme, t_data data)
{
	int	count;
	int	width;
	int	width_point;
	int	printed;

	count = ft_meme_count(meme);
	width_point = data.point.width - count;
	width = data.width - ft_max(data.point.width, count + 2);
	printed = ft_max(data.width, (ft_max(data.point.width, count + 2)));
	if (data.sup == '0')
		write(1, "0x", 2);
	if (meme == 0 && data.point.point && data.point.width == 0)
		return (ft_zero_case(width, width_point, printed, data));
	while (width-- > 0 && !data.minus)
		write(1, &data.sup, 1);
	if (data.sup != '0')
		write(1, "0x", 2);
	while (width_point-- > 0)
		write(1, "0", 1);
	ft_put_meme(meme, "0123456789abcdef");
	while (width-- > -1 && data.minus)
		write(1, &data.sup, 1);
	return (printed);
}

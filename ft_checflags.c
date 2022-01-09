/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:17:25 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/29 14:15:35 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isflag(char ch)
{
	char	*flags;
	int		index;

	flags = "-0+ #";
	index = 0;
	while (flags[index])
	{
		if (ch == flags[index])
			return (1);
		index++;
	}
	return (0);
}

static void	ft_lookforflags(char *format, int *index, t_data *data)
{
	*index += 1;
	while (ft_isflag(format[*index]))
	{
		if (format[*index] == '#')
			data->hashtag = 1;
		else if (format[*index] == '-')
		{
			data->minus = 1;
			data->sup = ' ';
		}
		else if (format[*index] == '+')
			data->plus = 1;
		else if (format[*index] == '0' && !data->minus)
			data->sup = '0';
		else if (format[*index] == ' ')
			data->space = 1;
		*index += 1;
	}
}

static int	ft_isdigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

static int	ft_isspecifier(char ch)
{
	char	*specifiers;
	int		index;

	index = 0;
	specifiers = "cspdiuxX%";
	while (specifiers[index])
	{
		if (ch == specifiers[index])
			return (1);
		index++;
	}
	return (0);
}

int	ft_checkflags(char *format, int *index, t_data *data, int len)
{
	ft_lookforflags(format, index, data);
	data->width = 0;
	while (ft_isdigit(format[*index]))
	{
		data->width = data->width * 10 + (format[*index] - '0');
		*index += 1;
	}
	if (format[*index] == '.')
	{
		*index += 1;
		data->point.point = 1;
		data->sup = ' ';
		while (ft_isdigit(format[*index]))
		{
			data->point.width = data->point.width * 10 + (format[*index] - '0');
			*index += 1;
		}
		if (ft_isspecifier(format[*index]))
			return (*index);
	}
	if (ft_isspecifier(format[*index]))
		return (*index);
	data->point.point = 1;
	return (-1);
}

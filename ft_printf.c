/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:01 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/12/09 00:25:21 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;
	t_data	data;
	int		index;

	va_start(ap, format);
	index = 0;
	printed = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			data = ft_newdata();
			if (ft_checkflags((char *)format, &index, &data, 16) > -1)
				printed += ft_checkspecifier(format[index], data, ap);
		}
		else
		{
			write(1, &format[index], 1);
			printed++;
		}
		index++;
	}
	va_end(ap);
	return (printed);
}

int	main()
{
	//char *b = "edkldkl";
	int i = ft_printf("-->|%#20x|<-- ", -1);
	printf("\n");
	int j = printf("-->|%#20x|<-- ", -1);
	printf("\n%d || %d\n", i, j);
}

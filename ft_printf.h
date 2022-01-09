/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:08:51 by yel-mrab          #+#    #+#             */
/*   Updated: 2021/11/29 14:12:19 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_point
{
	int		point;
	int		width;
}t_point;

typedef struct s_data
{
	int		width;
	int		hashtag;
	int		minus;
	int		plus;
	int		space;
	char	sup;
	char	*hashtag_sup;
	int		count_d;
	t_point	point;
}t_data;

int		ft_printf(const char *format, ...);
int		ft_checkflags(char *format, int *index, t_data *data, int sdj);
int		ft_checkspecifier(char ch, t_data data, va_list ap);
int		ft_putstr(char *str, t_data data);
int		ft_putchar(char ch, t_data data);
int		ft_putnumbers(int number, t_data data);
int		ft_put_unsigned_numbers(unsigned int number, t_data data);
int		ft_put_hexa(unsigned int hex, t_data data, char ch);
int		ft_print_meme(unsigned long meme, t_data data);
t_data	ft_newdata(void);
int		ft_max(int arg1, int arg2);
int		ft_countdigits(unsigned int number, unsigned int base_len);
void	ft_printf_digits(unsigned int number, unsigned int len, char *base);

#endif

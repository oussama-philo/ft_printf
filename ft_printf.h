/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:34 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/27 11:15:06 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*-----------Includes-----------*/

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

/*-----------Struct-----------*/

typedef struct format_print
{
	char				type;
	struct format_print	*next;
}	t_format;

/*-----------Functions----------*/

int			ft_printf(const char *format, ...);
int			ft_putnbr(long nb);
int			ft_putchar(char c);
int			ft_puthex(unsigned int n, int c);
int			ft_putstr(char *str);
int			ft_addr(void *ptr);
int			ft_unsigned(unsigned int nb);
char		*ft_strchr(const char *s, int c);
t_format	*add_node(t_format **head, t_format *new_node);
t_format	*create_node(char type);

#endif

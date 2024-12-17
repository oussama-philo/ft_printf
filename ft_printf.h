/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:34 by olachhab          #+#    #+#             */
/*   Updated: 2024/12/17 10:08:49 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*-----------Includes-----------*/

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

/*-----------Struct-----------*/

typedef struct s_format
{
	char			type;
	int				flag_hash;
	int				flag_space;
	int				flag_plus;
	struct s_format	*next;
}	t_format;

/*-----------Functions----------*/

int			ft_addr(void *ptr);

t_format	*create_node(void);
void		add_node(t_format **head, t_format *new_node);

int			ft_printf(const char *format, ...);

int			ft_putchar(char c);
int			ft_puthex(unsigned int n, int type);
int			ft_putnbr(long n);
int			ft_putstr(char *s);

char		*ft_strchr(const char *s, int c);
int			ft_unsigned(unsigned int nb);

int			handle_hash_flag(t_format *current, va_list args);
int			handle_space_flag(t_format *current, va_list args);
int			handle_plus_flag(t_format *current, va_list args);
int			handle_type(t_format *current, va_list args);

int			handle_format_specifier(const char *format, int *i,
				t_format **current, va_list args);
int			handle_specifier(t_format *current, va_list args);
int			handle_flags(t_format *current, va_list args);
int			parse_type(const char *format, int *i, t_format *node);
void		parse_flags(const char *format, int *i, t_format *node);

#endif

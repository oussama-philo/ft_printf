/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:06 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/27 11:13:12 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	x;

	x = 42;
	ft_printf("Min int {%d} | Max int {%d} | Percent: {%%} | Unsigned: {%u} | Hexadecimal: {%x} {%X} | Character: {%c} | String: {%s} | Integer: {%d} | Pointer: {%p} \n", INT_MIN, INT_MAX, 4294967295U, 255, 255, 'A', "oussama", 42, &x);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:24 by olachhab          #+#    #+#             */
/*   Updated: 2024/12/11 09:55:20 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*create_node(void)
{
	t_format	*node;

	node = (t_format *)malloc(sizeof(t_format));
	if (!node)
		return (NULL);
	node->type = 0;
	node->flag_hash = 0;
	node->flag_space = 0;
	node->flag_plus = 0;
	node->next = NULL;
	return (node);
}

void	add_node(t_format **head, t_format *new_node)
{
	t_format	*temp;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

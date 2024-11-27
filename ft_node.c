/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:09:24 by olachhab          #+#    #+#             */
/*   Updated: 2024/11/27 11:09:25 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*add_node(t_format **head, t_format *new_node)
{
	t_format	*current_node;

	if (!new_node)
	{
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	return (*head);
}

t_format	*create_node(char type)
{
	t_format	*new_node;

	new_node = (t_format *)malloc(sizeof(t_format));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->type = type;
	new_node->next = NULL;
	return (new_node);
}

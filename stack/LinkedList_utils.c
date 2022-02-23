/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:28:52 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 00:39:00 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_front_utils(t_list *new, t_list **head)
{
	t_list	*tail;

	tail = (*head)->prev;
	new->next = *head;
	new->prev = tail;
	(*head)->prev = new;
	tail->next = new;
	tail = new;
	*head = new;
	new->i = -1;
	while (new != (*head)->prev)
	{
		new->i += 1;
		new = new->next;
	}
	new->i += 1;
}

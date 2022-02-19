/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:16:41 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/19 19:36:03 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_list *head)
{
	int	swap;
	
	if (lst_size(head) < 1)
		return ;
	swap = head->data;
	head->data = head->next->data;
	head->next->data = swap;
}

void	push_stack(t_list **from, t_list **to)
{
	t_list	*tmp;
	t_list	*last;

	if (lst_size(*from) == 0)
		return ;
	tmp = (*from)->next;
	last = (*from)->prev;
	add_front(new_node((*from)->data), to);
	if (lst_size(*from) == 1)
		*from = NULL;
	else
	{
		tmp->prev = last;
		last->next = tmp;
		free(*from);
		*from = tmp;
	}
}

void	rotate_stack(t_list **head)
{
	if (lst_size(*head) < 2)
		return ;
	*head = (*head)->next;
}

void	reverse_rotate_stack(t_list **head)
{
	if (lst_size(*head) < 2)
		return ;
	*head = (*head)->prev;
}
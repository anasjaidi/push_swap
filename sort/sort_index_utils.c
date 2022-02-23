/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 05:01:10 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 05:07:48 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	(*best_function(int x, int y, char **msg, int z))(t_list**, char*)
{
	if (x < y / 2)
	{
		if (z == 1)
			*msg = "ra\n";
		else
			*msg = "rb\n";
		return (rotate_stack);
	}
	else
	{
		if (z == 1)
			*msg = "rra\n";
		else
			*msg = "rrb\n";
		return (reverse_rotate_stack);
	}
}

void	sort_index_utils(t_list *a, t_list *b)
{
	int		max;

	max = a->data;
	while (b != a->prev)
	{
		if (b->data > max)
		{
			a->index += 1;
			max = b->data;
		}
		b = b->next; 
	}
	if (b->data > max)
	{
		a->index += 1;
		max = b->data;
	}
}

void	write_steps(t_list *target, t_list *node, t_list *heada, t_list *headb)
{
	if (node->i > (lst_size(headb) / 2))
		node->steps = lst_size(headb) - node->i ;
	else
		node->steps = node->i;
	if (target->i > (lst_size(heada) / 2))
		node->steps += lst_size(heada) - target->i ;
	else
		node->steps += target->i;
	node->place = target;
}

void	push_stack_b(t_list **a, t_list **b, t_list *node)
{
    t_list  *tmp;
	char    *msg;
	void	(*f)(t_list**, char*);

	f = best_function(node->i, lst_size(*a), &msg, 1);
	tmp = *a;
	while (*a != node)
	{
		(*f)(a, msg);
	}
	push_stack(a, b, "pb\n");
}

void	push_b(t_list **a, t_list **b, t_list *head)
{
	t_list	*tmp;
	int		max;

	tmp = head;
	max = tmp->data;
	while (tmp != head->prev)
	{
		if (max <= tmp->data)
		{
			max = tmp->data;
		}
		else
			push_stack_b(a, b, tmp);
		tmp = tmp->next;
	}
	if (max < tmp->data)
	{
			max = tmp->data;
	}
	else
		push_stack_b(a, b, tmp);
}
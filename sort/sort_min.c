/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:05:04 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 18:37:55 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort2(t_list **a)
{
	t_list	*tmp;

	if (lst_size(*a) != 2)
		return ;
	tmp = *a;
	if (tmp->data > tmp->next->data)
		swap_stack(*a, "sa\n");
}

void	sort3(t_list **a)
{
	t_list	*tmp;

	if (lst_size(*a) != 3)
		return ;
	tmp = *a;
	if (tmp->data > tmp->next->data)
	{
		if (tmp->data > tmp->next->next->data && tmp->next->data \
		< tmp->next->next->data)
			reverse_rotate_stack(a, "rra\n");
		else
			swap_stack(*a, "sa\n");
	}
	if (tmp->data > tmp->next->next->data)
		reverse_rotate_stack(a, "rra\n");
	if (tmp->data < tmp->next->next->data \
	&& tmp->next->data > tmp->next->next->data)
	{
		swap_stack(*a, "sa\n");
		rotate_stack(a, "ra\n");
	}
}

void	sort_index(t_list **stack)
{
	t_list	*tmp1;

	tmp1 = *stack;
	while (tmp1 != (*stack)->prev)
	{
		sort_index_utils(tmp1, tmp1);
		tmp1 = tmp1->next;
	}
	sort_index_utils(tmp1, tmp1);
}

void	sort4(t_list **a, t_list **b)
{
	t_list	*tmp;
	char	*msg;
	void	(*f)(t_list**, char*);

	tmp = min_data(*a);
	f = best_function(tmp->i, lst_size(*a), &msg, 1);
	while (tmp != *a)
		(*f)(a, msg);
	push_stack(a, b, "pb\n");
	sort3(a);
	push_stack(b, a, "pa\n");
}

void	sort_4_5(t_list **a, t_list **b)
{
	t_list	*tmp;
	char	*msg;
	void	(*f)(t_list**, char*);

	if (lst_size(*a) == 4)
		sort4(a, b);
	else
	{
		tmp = min_data(*a);
		f = best_function(tmp->i, lst_size(*a), &msg, 1);
		while (tmp != *a)
			(*f)(a, msg);
		push_stack(a, b, "pb\n");
		sort4(a, b);
		push_stack(b, a, "pa\n");
	}
}

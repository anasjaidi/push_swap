/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:21:24 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 05:06:31 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*max_index(t_list **stack)
{
	t_list	*tmp;
	t_list	*rtn;
	int		max;

	tmp = *stack;
	max = tmp->index;
	rtn = tmp;
	while (tmp != (*stack)->prev)
	{
		if (max < tmp->index)
		{
			max = tmp->index;
			rtn = tmp;
		}
		tmp = tmp->next;
	}
	if (max < tmp->index)
	{
		max = tmp->index;
		rtn = tmp;
	}
	return (rtn);
}

t_list	*min_steps(t_list *b)
{
	int		min;
	t_list	*tmp;
	t_list	*rtn;

	min = b->steps;
	tmp = b;
	rtn = tmp;
	while (tmp != b->prev)
	{
		if (min > tmp->steps)
		{
			min = tmp->steps;
			rtn = tmp;
		}
		tmp = tmp->next;
	}
	if (min > tmp->steps)
	{
		min = tmp->steps;
		rtn = tmp;
	}
	return (rtn);
}

void	range_stack_utils(t_list **a, t_list **b, t_list *min, void	(*fa)(t_list**, char*), void	(*fb)(t_list**, char*))
{
	while (*b != min && min->place != *a && (fa == fb && fb == rotate_stack))
	{
		(*fa)(a,NULL);
		(*fb)(b,NULL);
		printf("rr\n");
	}
	while (*b != min && min->place != *a && (fa == fb && fb == reverse_rotate_stack))
	{
		(*fa)(a,NULL);
		(*fb)(b,NULL);
		printf("rrr\n");
	}
}

t_list	*min_data(t_list *a)
{
	t_list	*tmp;
	int		min;
	t_list	*rtn;

	rtn = a;
	min = a->data;
	tmp = a;
	while (tmp != a->prev)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			rtn = tmp;
		}
		tmp = tmp->next;
	}
	if (min > tmp->data)
	{
			min = tmp->data;
			rtn = tmp;
	}
	return (rtn);
}

void	min_on_top(t_list **a)
{
	t_list	*min;
	void	(*f)(t_list**, char*);
	char	*msg;

	min = min_data(*a);
	f = best_function(min->i, lst_size(*a), &msg, 1);
	while (*a != min)
	{
		(*f)(a, msg);
	}
}

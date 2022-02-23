/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:21:24 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 04:54:01 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void	(*best_function(int x, int y, char **msg, int z))(t_list**, char*);

void	sort(t_list **a, t_list **b)
{
	t_list	*tmp;

	sort_index(a);
	tmp = max_index(a);
	push_b(a, b, tmp);
	mix_stack(a, b);
}

void	(*best_function(int x, int y, char **msg, int z))(t_list**, char*)
{
	if (x < y / 2)
	{
		if (z == 1)
			*msg = "ra\n";
		else
			*msg = "ra\n";
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

void	push_stack_b(t_list **a, t_list **b, t_list *node)
{
	t_list	*tmp;
	char	*msg;
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

void	range_stack(t_list **a, t_list **b, t_list *min)
{
	void	(*fa)(t_list**, char*);
	void	(*fb)(t_list**, char*);
	char	*msga;
	char	*msgb;

	fa = best_function(min->place->i, lst_size(*a), &msga, 1);
	fb = best_function(min->i, lst_size(*b), &msgb, 0);
	while (1)
	{
		range_stack_utils(a, b, min, fa, fb);
		while (*a != min->place)
		{
			(*fa)(a, msga);
		}
		while (*b != min)
		{
			(*fb)(b, msgb);
		}
		if (*a == min->place && *b == min)
			break ;
	}
	push_stack(b, a, "pa\n");
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

void	mix_stack(t_list **a, t_list **b)
{
	t_list	*send;
	t_list	*tmp;
	t_list	*markup;

	tmp = *b;
	calculate_steps(a, b, max_index(a));
	while (1)
	{
		send = min_steps(*b);
		range_stack(a, b, send);
		if (!lst_size(*b))
			break ;
		markup = min_data(*a);
		calculate_steps(a, b, markup);
	}
	min_on_top(a);
}

void	calculate_steps(t_list **a, t_list **b, t_list *markup)
{
	t_list	*tmp;

	if (!lst_size(*b))
		return ;
	tmp = *b;
	while (tmp != (*b)->prev)
	{
		check_place(a, b, tmp, markup);
		tmp = tmp->next;
	}
	check_place(a, b, tmp, markup);
}

void	check_place(t_list **a, t_list **b, t_list *node_p, t_list *markup)
{
	t_list	*tmp;
	int		num;

	num = node_p->data;
	tmp = *a;
	while (tmp != (*a)->prev)
	{
		if ((tmp->data < num && num < tmp->next->data))
			write_steps(tmp->next, node_p, *a, *b);
		else if ((num < markup->data && tmp == markup))
			write_steps(tmp, node_p, *a, *b);
		tmp = tmp->next;
	}
	if ((tmp->data < num && num < tmp->next->data))
		write_steps(tmp->next, node_p, *a, *b);
	else if ((num < markup->data && tmp == markup))
		write_steps(tmp, node_p, *a, *b);
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

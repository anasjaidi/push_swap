/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:21:24 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/22 15:42:34 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list **a, t_list **b)
{
	(void)b;
	t_list	*tmp;
	sort_index(a);
	tmp = max_index(a);
	push_b(a, b, tmp);
	//mix_stack(a, b, tmp);
	tmp = *b;
	while (tmp != (*b)->prev)
	{
		check_place(a, b, tmp);
		tmp= tmp->next;
	}
	check_place(a, b, tmp);
}

void	push_stack_b(t_list **a, t_list **b, t_list *node)
{
	t_list	*tmp;
	void	(*f)(t_list**, char*);
	char	*msg;

	if (node->i <= lst_size(*a) / 2)
	{
		f = &rotate_stack;
		msg = "ra\n";
	}
	else
	{
 		f = &reverse_rotate_stack;
		msg = "rra\n";
	}
	tmp = *a;
	while (*a != node)
	{
		(*f)(a, msg);
	}
	push_stack(a, b, "pb\n");
}

void	push_b(t_list **a, t_list **b, t_list *head)
{
	(void)b;
	(void)a;
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

void	sort_index(t_list **stack)
{
	t_list 	*tmp1;
	t_list 	*tmp2;
	int		max;

	tmp1 = *stack;
	max = tmp1->data;
	while (tmp1 != (*stack)->prev)
	{
		max = tmp1->data;
		tmp2 = tmp1;
		while (tmp2 != tmp1->prev)
		{
			if (tmp2->data > max)
			{
				tmp1->index += 1;
				max = tmp2->data;
			}
			tmp2 = tmp2->next; 
		}
		if (tmp2->data > max)
			{
				tmp1->index += 1;
				max = tmp2->data;
			}
			tmp1 = tmp1->next;
		
	}
	max = tmp1->data;
		tmp2 = tmp1;
		while (tmp2 != tmp1->prev)
		{
			if (tmp2->data > max)
			{
				tmp1->index += 1;
				max = tmp2->data;
			}
			tmp2 = tmp2->next; 
		}
		if (tmp2->data > max)
		{
				tmp1->index += 1;
				max = tmp2->data;
		}
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

// void	mix_stack(t_list **a, t_list **b)
// {
// 	t_list	*send;
// 	t_list	*tmp;

// 	tmp = *b;
// 	while (tmp != (*b)->prev)
// 	{
// 		check_place(a, b, tmp);
// 	}
	
	
	
// }

void	check_place(t_list **a, t_list **b, t_list *node_p)
{
	t_list	*tmp;
	//t_list	*node;
	int		num;
	(void)b;


	num = node_p->data;
	tmp = *a;
	while (tmp != (*a)->prev)
	{
		if ((tmp->data < num && num > tmp->next->data))
			write_steps(tmp->next, node_p, *a, *b);
		if ((num < max_index(a)->data && tmp == max_index(a)))
			write_steps(tmp, node_p, *a, *b);
		tmp = tmp->next;
	}
	if ((tmp->data < num && num > tmp->next->data))
		write_steps(tmp->next, node_p, *a, *b);
	if ((num < max_index(a)->data && tmp == max_index(a)))
		write_steps(tmp, node_p, *a, *b);
}

void	write_steps(t_list *target, t_list *node, t_list *heada, t_list *headb)
{
	printf("----[%d]---\n",node->data);
	if (node->i > (lst_size(headb) / 2))
		//node->steps += lst_size(headb) - node->i ;
		printf("lst_size(headb) - node->i [%d]\n", lst_size(headb) - node->i);
	else
		//node->steps += node->i;
		printf("node->i [%d]\n",node->i);
	if (target->i > (lst_size(heada) / 2))
		//node->steps += lst_size(heada) - target->i ;
		printf("lst_size(heada) - target->i [%d]\n", lst_size(heada) - target->i );
	else
		//node->steps += target->i;
		printf("target->i [%d]\n",target->i);
		
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:21:24 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/21 03:40:40 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sort(t_list **a, t_list **b)
// {
// 	t_list	*tmp;
// 	sort_index(a);
// 	tmp = max_index(a);
// 	push_b(a, b, tmp);
// }
// void	push_stack_a(t_list **a, t_list **b, int num)
// {
// 	t_list	*tmp;

// 	tmp = *a;
// 	while (tmp != (*a)->prev)
// 	{
		
// 	}
	
// }

// void	push_b(t_list **a, t_list **b, t_list *head)
// {
// 	t_list	*tmp;
// 	int		max;

// 	tmp = head;
// 	max = tmp->data;
// 	while (tmp != head->prev)
// 	{
// 		if (max < tmp->data)
// 		{
// 			max = tmp->data;
// 		}
// 		// else
// 		// 	push_stack_b(a, b);
// 	}
	
// }

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:47:31 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/21 03:48:34 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_list *head)
{
	t_list	*tmp;

	if (!head)
		return ;
	tmp = head;
	while (tmp != head->prev)
	{
		printf("%d %d\n", tmp->i, tmp->data);
		tmp = tmp->next;
	}
	printf("%d %d\n", tmp->i, tmp->data);
}

int	main(int ac, char **av)
{
	t_list	*a;
	//t_list	*b;

	if (ac > 1)
	{
		fil_in(ac, av, &a);
		add_front(new_node(0), &a);
		//sort_index(&a);
		//max_index(&a);
		printf("-----a-----\n");
		display_stack(a);
		//printf("-----b-----\n");
		//display_stack(b);
	}
	return (0);
}

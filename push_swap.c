/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:47:31 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/21 22:41:13 by ajaidi           ###   ########.fr       */
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
		printf("%d %d\n", tmp->steps, tmp->data);
		tmp = tmp->next;
	}
	printf("%d %d\n", tmp->steps, tmp->data);
}

int	main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;

	if (ac > 1)
	{
		fil_in(ac, av, &a);
		sort(&a, &b);
		//swap_stack(a);
		//sort_index(&a);
		//max_index(&a);
		printf("-----a-----\n");
		display_stack(a);
		printf("-----b-----\n");
		display_stack(b);
	}
	return (0);
}

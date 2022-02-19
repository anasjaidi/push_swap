/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:47:31 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/19 19:37:01 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_list *head)
{
	t_list	*tmp;

	if (!head)
		return;
	tmp = head;
	while (tmp != head->prev)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->data);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b= NULL;
	//int		i;

	if (ac > 1)
	{
		fil_in(ac, av, &a);
		reverse_rotate_stack(&a);
		printf("-----a-----\n");
		display_stack(a);
		printf("-----b-----\n");
		display_stack(b);
	}
	return (0);
}

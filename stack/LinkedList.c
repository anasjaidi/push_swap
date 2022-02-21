/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:09:07 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/21 03:47:06 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

t_list	*new_node(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*add_back(t_list *new, t_list **head)
{
	t_list	*tail;

	if (!(*head))
	{
		new->next = new;
		new->prev = new;
		*head = new;
		(*head)->i =0;
		return (NULL);
	}
	tail = (*head)->prev;
	new->next = *head;
	new->prev = tail;
	(*head)->prev = new;
	tail->next = new;
	tail = new;
	new->i = new->prev->i + 1;
	return (*head);
}

t_list	*add_front(t_list *new, t_list **head)
{
	t_list	*tail;

	if (!(*head))
	{
		new->next = new;
		new->prev = new;
		*head = new;
		return (NULL);
	}
	tail = (*head)->prev;
	new->next = *head;
	new->prev = tail;
	(*head)->prev = new;
	tail->next = new;
	tail = new;
	*head = new;
	new->i = -1;
	while (new != (*head)->prev)
	{
		new->i += 1;
		new = new->next;
	}
	new->i += 1;
	return (*head);
}

void	clr_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp != temp->prev)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
	free(temp);
}

int	lst_size(t_list *head)
{
	t_list	*tmp;
	int		c;

	if (!head)
		return (0);
	c = 1;
	tmp = head;
	while (tmp != head->prev)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}


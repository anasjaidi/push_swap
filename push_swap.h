/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:58:21 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/19 23:33:55 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list {
	struct s_list	*prev;
	int				data;
	struct s_list	*next;
}	t_list;

int		lst_size(t_list *head);
void	swap_stack(t_list *head);
int		ft_sep(char c);
int		check_num(int ac, char **av);
void	fil_in(int ac, char **av, t_list **head);
t_list	*new_node(int data);
t_list	*add_back(t_list *new, t_list **head);
void	clr_list(t_list *head);
void	push_stack(t_list **from, t_list **to);
t_list	*add_front(t_list *new, t_list **head);
void	reverse_rotate_stack(t_list **head);
void	rotate_stack(t_list **head);
void	sort3(t_list **a);
void	sort2(t_list **a);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:58:21 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/23 05:01:41 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list {
	int				steps;
	int				i;
	struct s_list	*prev;
	int				index;
	struct s_list	*place;
	int				data;
	struct s_list	*next;
}	t_list;
void	(*best_function(int x, int y, char **msg, int z))(t_list**, char*);
int		lst_size(t_list *head);
void	swap_stack(t_list *head, char *msg);
int		ft_sep(char c);
int		check_num(int ac, char **av);
void	fil_in(int ac, char **av, t_list **head);
t_list	*new_node(int data);
t_list	*add_back(t_list *new, t_list **head);
void	clr_list(t_list *head);
void	push_stack(t_list **from, t_list **to, char *msg);
t_list	*add_front(t_list *new, t_list **head);
void	reverse_rotate_stack(t_list **head, char *msg);
void	sort_index(t_list **stack);
void	rotate_stack(t_list **head, char *msg);
void	sort3(t_list **a);
void	sort2(t_list **a);
t_list	*max_index(t_list **stack);
void	sort(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b, t_list *head);
void	push_stack_b(t_list **a, t_list **b, t_list *node);
void	get_inx(int *min, int *max, t_list **a);
void	check_place(t_list **a, t_list **b, t_list *node_p, t_list *markup);
void	write_steps(t_list *target, t_list *node, t_list *heada, t_list *headb);
void	calculate_steps(t_list **a, t_list **b, t_list *markup);
void	mix_stack(t_list **a, t_list **b);
void	display_stack(t_list *head);
void    add_front_utils(t_list *new, t_list **head);
#endif

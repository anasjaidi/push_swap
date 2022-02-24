/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <ajaidi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:58:21 by ajaidi            #+#    #+#             */
/*   Updated: 2022/02/24 02:26:29 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define MX 536870912
# define BUFFER_SIZE 10000

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
void	fil_in(int ac, char **av, t_list **head);
t_list	*new_node(int data);
t_list	*add_back(t_list *new, t_list **head);
void	clr_list(t_list **head);
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
void	add_front_utils(t_list *new, t_list **head);
void	sort_index_utils(t_list *a, t_list *b);
void	min_on_top(t_list **a);
t_list	*min_steps(t_list *b);
void	range_stack_utils(t_list **a, t_list **b, t_list *min, \
	void (*fa)(t_list**, char*), void (*fb)(t_list**, char*));
t_list	*min_data(t_list *a);
void	sort_4_5(t_list **a, t_list **b);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
char	**ft_split(char const *s);
int		ft_write_split(char **split, char *str);
void	ft_write_word(char *dest, char *src);
int		ft_words(char *str);
void	check_in(int ac, char **av, t_list **a);
int		check_num(char *str);
int		ft_atoi(const char *str);
void	ft_exit(t_list **a);
char	*ft_strdup(const char *s1);
int		ft_strchr(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2);
#endif

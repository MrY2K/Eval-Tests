/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:57:36 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/14 00:56:33 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

//DEBUGING
void			ll(void);

//error:
void			ft_error(void);
void			ft_perror(char *s);

//input:
char			**validate_input(int ac, char **av, int total_tokens);
char			**ft_split(char const *s, char c);
void			ft_free_split(char **split);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				count_tokens(int ac, char **av);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(char *src);
int				ft_isspace(char c);

//list manipulation
t_stack_node	*ft_lstnew(int data);
void			ft_lstadd_front(t_stack_node **lst, t_stack_node *new_node);
void			ft_lstclear(t_stack_node **lst);
void			ft_lstdelone(t_stack_node *lst);
int				has_duplicates(t_stack_node *head);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *_new);
size_t			ft_lstsize(t_stack_node *head);

//Ops
int				swap(t_stack_node **stack);
int				sa(t_stack_node **stack);
int				sb(t_stack_node **stack);
int				ss(t_stack_node **stack_a, t_stack_node **stack_b);
int				push_top(t_stack_node **stack_to, t_stack_node **stack_from);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
int				rotate(t_stack_node **stack);
int				ra(t_stack_node **stack);
int				rb(t_stack_node **stack);
int				rr(t_stack_node **stack_a, t_stack_node **stack_b);
int				reverse_rotate(t_stack_node **stack);
int				rra(t_stack_node **stack);
int				rrb(t_stack_node **stack);
int				rrr(t_stack_node **stack_a, t_stack_node **stack_b);

//Sorting
int				sorted(t_stack_node *stack_a);
void			indexing(t_stack_node *stack_a);
void			small_stack_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_two(t_stack_node **stack_a);
void			sort_three(t_stack_node **stack_a);
void			sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
void			sort_five(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
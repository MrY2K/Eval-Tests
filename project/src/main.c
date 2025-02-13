/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:38:15 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/13 18:40:51 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_args(char **args);
void	print_stack(t_stack_node *stack);
void	ll(void);


int main(int ac, char **av)
{
	//*----------------------------------- INPUT VALIDATION:
	printf("NUMBER OF ARGUMENTS: %d\n", ac);

	char			**_valid_args;
	t_stack_node	*stack_a = NULL;
	int				total_tokens;

	total_tokens = count_tokens(ac, av);
	_valid_args = validate_input(ac, av, total_tokens);
	if (!_valid_args)
		ft_error();

	print_args(_valid_args);

	//*----------------------------------- FILL THE STACK
	int i = -1;
	while (_valid_args[++i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(_valid_args[i]))); //!

	print_stack(stack_a);

	//*----------------------------------- check for dups
	if (has_duplicates(stack_a))
	{
		ft_perror("Error\n");
		printf("(X) ==> Duplicates found!\n");
		exit(1);
	}
	else
		printf("(+) ==> No duplicates.\n");
	// FREE --------------------------------------------
	ft_free_split(_valid_args); // FREE the args
	ft_lstclear(&stack_a); // free the stack
	atexit(ll); //CHECK LEAKS
	return (0);
}

void	ll(void)
{
	printf("----------------------☠️ LEAKS ☠️--------------------------\n");
	system("leaks -q push_swap");
}

void	print_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		printf("Argument %d: [%s]\n", i + 1, args[i]);
		i++;
	}
}

void	print_stack(t_stack_node *stack)
{
	if (!stack)
	{
		printf("Stack is empty\n");
		return ;
	}
	printf("================== MY LIST (STACK_A): =======================:\n");
	while (stack != NULL)
	{
		printf("[%d]\n", stack->data);
		printf(" |\n");
		printf(" v\n");
		stack = stack->next;
	}
	printf("\n");
}

//* Normed:
// int	main(int ac, char **av)
// {
// 	char			**_valid_args;
// 	t_stack_node	*stack_a;
// 	int				i;
// 	int				total_tokens;

// 	total_tokens = count_tokens(ac, av);
// 	_valid_args = validate_input(ac, av, total_tokens);
// 	if (!_valid_args)
// 		ft_error();
// 	print_args(_valid_args);
// 	i = -1;
// 	while (_valid_args[++i])
// 		ft_lstadd_front(&stack_a, ft_lstnew(ft_atoi(_valid_args[i])));
// 	print_stack(stack_a);
// 	if (has_duplicates(stack_a))
// 		ft_error();
// 	ft_free_split(_valid_args);
// 	ft_lstclear(&stack_a);
// 	atexit(ll);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:03:15 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/14 00:58:08 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	indexing(t_stack_node *stack_a);
int		sorted(t_stack_node *stack_a);
void	small_stack_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_two(t_stack_node **stack_a);
void	sort_three(t_stack_node **stack_a);
void	sort_four(t_stack_node **stack_a, t_stack_node **stack_b);
void	sort_five(t_stack_node **stack_a, t_stack_node **stack_b);

int	sorted(t_stack_node *stack_a)
{
	if (!stack_a)
		return (1);

	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void indexing(t_stack_node *stack_a)
{
    t_stack_node	*current;
    t_stack_node	*temp;
    int				count;

    if (!stack_a)
        return;

    current = stack_a;
    while (current)
    {
        count = 0;
        temp = stack_a;
        while (temp)
        {
            if (current->data > temp->data)
                count++;
            temp = temp->next;
        }
        current->index = count;
        current = current->next;
    }
}

int get_min_index(t_stack_node *stack_a)
{
    int pos;
	
	pos = 0;
    while (stack_a)
    {
        if (stack_a->index == 0)
            return (pos);
        pos++;
        stack_a = stack_a->next;
    }
    return (-1);
}

void	small_stack_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!stack_a || !*stack_a)
    	return ;
	if (ft_lstsize(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
}
void	sort_two(t_stack_node **stack_a)
{
	t_stack_node	*tmp;
	
	if (!stack_a || !*stack_a || !((*stack_a)->next))
	    return ;
	tmp = *stack_a;
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
}


// Sorts a stack with exactly three elements.
void sort_three(t_stack_node **stack_a)
{
    size_t a = (*stack_a)->data;
    size_t b = (*stack_a)->next->data;
    size_t c = (*stack_a)->next->next->data;
    
    // Case 1: a > b, a < c => only need to swap a and b.
    if (a > b && a < c)
        sa(stack_a);
    // Case 2: a > b, b > c => stack is in descending order.
    else if (a > b && b > c)
    {
        sa(stack_a);
        rra(stack_a);
    }
    // Case 3: a > b, a > c, but b < c => a is the largest.
    else if (a > b && a > c && b < c)
        ra(stack_a);
    // Case 4: a < b, a < c, but b > c => b is the largest.
    else if (a < b && a < c && b > c)
    {
        sa(stack_a);
        ra(stack_a);
    }
    // Case 5: a < b, a > c => a is in the middle.
    else if (a < b && a > c)
        rra(stack_a);
}

// Sorts a stack with exactly four elements.
// Strategy: bring the smallest element to the top and push it to stack_b,
// then sort the remaining three, and finally push the smallest back.
void sort_four(t_stack_node **stack_a, t_stack_node **stack_b)
{
    size_t min_index = get_min_index(*stack_a);
    
    // Rotate or reverse-rotate until the smallest element is at the top.
    if (min_index == 1)
        ra(stack_a);
    else if (min_index == 2)
    {
        ra(stack_a);
        ra(stack_a);
    }
    else if (min_index == 3)
        rra(stack_a);
    
    // Push smallest to stack_b.
    pb(stack_a, stack_b);
    
    // Now sort the remaining three elements.
    sort_three(stack_a);
    
    // Finally, push back the smallest element.
    pa(stack_a, stack_b);
}

// Sorts a stack with exactly five elements.
// Strategy: push the two smallest elements to stack_b, sort the remaining three,
// and then push back the two smallest in order.
void sort_five(t_stack_node **stack_a, t_stack_node **stack_b)
{
    size_t min_index;
    
    // --- Push the smallest element to stack_b ---
    min_index = get_min_index(*stack_a);
    while (min_index > 0)
    {
        // Use rotation or reverse-rotation based on the element's position.
        if (min_index <= ft_lstsize(*stack_a) / 2)
            ra(stack_a);
        else
            rra(stack_a);
        min_index = get_min_index(*stack_a);
    }
    pb(stack_a, stack_b);
    
    // --- Push the next smallest element to stack_b ---
    min_index = get_min_index(*stack_a);
    while (min_index > 0)
    {
        if (min_index <= ft_lstsize(*stack_a) / 2)
            ra(stack_a);
        else
            rra(stack_a);
        min_index = get_min_index(*stack_a);
    }
    pb(stack_a, stack_b);
    
    // --- Sort the remaining three elements in stack_a ---
    sort_three(stack_a);
    
    // --- Ensure that the two elements in stack_b are in proper order ---
    // (Assuming that in the final sorted stack, the smallest should be on top)
    if ((*stack_b)->next && (*stack_b)->data < (*stack_b)->next->data)
        sb(stack_b);
    
    // --- Push back the two smallest elements ---
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

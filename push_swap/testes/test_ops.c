

void	print_args(char **args);
// void	print_stack(t_stack_node *stack);
void	ll(void);


// Function to create a new stack node
t_stack_node *new_node(int data)
{
    t_stack_node *node = malloc(sizeof(t_stack_node));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print a stack
void print_stack(t_stack_node *stack, char *name)
{
    printf("Stack %s: ", name);
    while (stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

// Function to free the stack
void free_stack(t_stack_node **stack)
{
    t_stack_node *temp;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

// Test function
void test_operations()
{
    // Initialize stacks
    t_stack_node *stack_a = new_node(3);
    stack_a->next = new_node(2);
    stack_a->next->next = new_node(1);

    t_stack_node *stack_b = NULL;

    printf("Initial state:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    // Swap A
    sa(&stack_a);
    printf("After sa:\n");
    print_stack(stack_a, "A");

    // Push to B
    pb(&stack_a, &stack_b);
    printf("After pb:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    pb(&stack_a, &stack_b);
    printf("After another pb:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    // Push back to A
    pa(&stack_a, &stack_b);
    printf("After pa:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    // Rotate A
    ra(&stack_a);
    printf("After ra:\n");
    print_stack(stack_a, "A");

    // Reverse Rotate A
    rra(&stack_a);
    printf("After rra:\n");
    print_stack(stack_a, "A");

    // Swap B
    sb(&stack_b);
    printf("After sb:\n");
    print_stack(stack_b, "B");

    // Rotate B
    rb(&stack_b);
    printf("After rb:\n");
    print_stack(stack_b, "B");

    // Reverse Rotate B
    rrb(&stack_b);
    printf("After rrb:\n");
    print_stack(stack_b, "B");

    // Clean up
    free_stack(&stack_a);
    free_stack(&stack_b);
}

void test_operations_rra_rrb_rrr_rr()
{
    // Initialize stack A: [1, 2, 3]
    t_stack_node *stack_a = new_node(1);
    stack_a->next = new_node(2);
    stack_a->next->next = new_node(3);

    // Initialize stack B: [4, 5, 6]
    t_stack_node *stack_b = new_node(4);
    stack_b->next = new_node(5);
    stack_b->next->next = new_node(6);

    printf("Initial Stacks:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    // Reverse rotate A
    rra(&stack_a);
    printf("After rra:\n");
    print_stack(stack_a, "A");

    // Reverse rotate B
    rrb(&stack_b);
    printf("After rrb:\n");
    print_stack(stack_b, "B");

    // Reverse rotate both (rrr)
    rrr(&stack_a, &stack_b);
    printf("After rrr:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    // Rotate both (rr)
    rr(&stack_a, &stack_b);
    printf("After rr:\n");
    print_stack(stack_a, "A");
    print_stack(stack_b, "B");

    // Free memory
    free_stack(&stack_a);
    free_stack(&stack_b);
}

int main()
{
    test_operations_rra_rrb_rrr_rr();
    return 0;
}
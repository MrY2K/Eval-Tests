#include "push_swap.h"

// Utility function to free split array
void free_split_array(char **array)
{
    if (array == NULL)
        return;
    
    for (int i = 0; array[i] != NULL; i++)
    {
        free(array[i]);
    }
    free(array);
}

void print_split_results(int ac, char **av)
{
    printf("Total Arguments: %d\n", ac);
    
    for (int i = 1; i < ac; i++)
    {
        printf("Argument %d: '%s'\n", i, av[i]);
        
        // Split the current argument
        char **split_args = ft_split(av[i], ' ');
        
        // Count and print split results
        int j = 0;
        printf("Split Results:\n");
        while (split_args[j] != NULL)
        {
            printf("  Split %d: '%s'\n", j, split_args[j]);
            j++;
        }
        printf("Total splits: %d\n\n", j);
        
        // Free the split results (important!)
        // You'll need to implement this free function
        free_split_array(split_args);
    }
}


// int main(int ac, char **av)
// {
//     // Call the print function to see splitting results
//     print_split_results(ac, av);
    
//     return 0;
// }
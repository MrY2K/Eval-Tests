#include "../include/push_swap.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>


int	ft_isspace(char c)
{
    // Check for space, tab, newline, vertical tab, form feed, and carriage return
    if (c == ' ' || c == '\t' || c == '\n' || 
        c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

// validate_argument returns 1 if every token in the argument is valid,
// or 0 if any token is invalid.
int validate_arg(const char *arg) {
    int i = 0;

    while (arg[i]) {
        // Skip any leading whitespace.
        while (arg[i] && ft_isspace((unsigned char)arg[i]))
            i++;
        
        // If we've reached the end after spaces, we're done.
        if (!arg[i])
            break;
        
        // Check for an optional sign.
        if (arg[i] == '+' || arg[i] == '-') {
            // A sign must be followed by a digit.
            if (!ft_isdigit(arg[i + 1]))
                return 0;
            i++;
        }
        
        // There must be at least one digit.
        if (!ft_isdigit(arg[i]))
            return 0;
        
        // Skip all digits.
        while (arg[i] && ft_isdigit(arg[i]))
            i++;
        
        // After the number, if we're not at the end, the next character should be whitespace.
        // (This also covers the case where extra non-digit characters appear.)
        if (arg[i] && !ft_isspace((unsigned char)arg[i]))
            return 0;
    }
    
    return 1;
}

void    validate_all_args(int ac, char **av)
{
    int i;
    i = 0;
    while (++i < ac)
    {
        if (!validate_arg(av[i]))
        {
            fprintf(stderr, "Invalid argument: \"%s\"\n", av[i]);
            exit(1);
        }
    }
}


// Example main() to test the function.
int main(void) {
    const char *test1 = "123";
    const char *test2 = "+123 -456 789";
    const char *test3 = "1a 2 3";         // Invalid: '1a' is not a number.
    const char *test4 = " + 123";          // Invalid: '+' not immediately followed by a digit.
    const char *test5 = "   -001 42";      // Valid: extra spaces and leading zeros are fine.
    const char *test6 = "";
    
    printf("Test1: %d\n", validate_arg(test1)); // Expected 1
    printf("Test2: %d\n", validate_arg(test2)); // Expected 1
    printf("Test3: %d\n", validate_arg(test3)); // Expected 0
    printf("Test4: %d\n", validate_arg(test4)); // Expected 0
    printf("Test5: %d\n", validate_arg(test5)); // Expected 1
    printf("Test6: %d\n", validate_arg(test6)); // Expected 1
    
    return 0;
}

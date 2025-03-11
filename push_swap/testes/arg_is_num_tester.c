#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

//! needs to handles string long numbers as in "1 23  44    -43" needs to skip the white space and have only one - or + infront of it needs to be a num as is no "- " or "--" or "2-"
int arg_is_num(char *arg)
{
    size_t  i;
    
    i = 0;

    // handling signs : first digit can be a sign
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    
    // the next one has to be a digit and not eampty
    if (!arg[i] || !ft_isdigit(arg[i]))
        return (0);

    // Validate remaining characters are digits
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
            return (0); //NOT A NUM //NOT VALID
        i++;
    }
    return (1);  // Valid number
}
void test_arg_is_num()
{
    // Test Cases Structure:
    // { input, expected_result }
    struct test_case {
        char *input;
        int expected;
    };

    struct test_case tests[] = {
        // Positive Numbers
        {"123", 1},
        {"0", 1},
        
        // Negative Numbers
        {"-123", 1},
        
        // Positive Numbers with Sign
        {"+456", 1},
        
        // Invalid Inputs
        {"", 0},
        {"a", 0},
        {"12a3", 0},
        {"-", 0},
        {"+", 0},
        {"--123", 0},
        {"123-", 0},
        {"+123-", 0}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    printf("Testing arg_is_num() function:\n");
    for (int i = 0; i < num_tests; i++)
    {
        int result = arg_is_num(tests[i].input);
        printf("Test %d: Input '%s' - Expected: %d, Got: %d - %s\n", 
               i + 1, 
               tests[i].input, 
               tests[i].expected, 
               result,
               (result == tests[i].expected) ? "PASS" : "FAIL");
    }
}

int main()
{
    test_arg_is_num();
    return 0;
}
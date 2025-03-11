# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int num_len(char *num, int *sign)
{
    int i;
    int len;
    i = 0;
    len = 0;
    *sign = 1;

    if (num[i] == '-' || num[i] == '+') //skip the - and + sign
    {
        if (num[i] == '-')
            *sign = -1;
        i++;
    }

    while (num[i] == '0') //skip zeros at the start
        i++;

    // Count the remaining digits
    while (num[i] && num[i] >= '0' && num[i] <= '9')
    {
        len++;
        i++;
    }
    return (len);
}


// check if the arg is an int
int arg_is_int(char *arg)
{
    char    *limit;
    int     len;
    int     sign;

    len = num_len(arg, &sign);
    if (*arg == '-' || *arg == '+')    // Handle an optional sign.
        arg++;
    while (*arg == '0')     // Skip any leading zeros.
        arg++;  
    if (len < 10)
        return (1); // defenetly with in range
    else if (len > 10)
        return (0); //defemetly not in the range
    else
    {
        if (sign == -1)
            limit = "2147483648";
        else
            limit = "2147483647";
        if (ft_strncmp(arg, limit, 10) <= 0)
            return (1);
        else
            return (0);
    }
}

/* Main function to test arg_is_int with several examples */
int main(void)
{
    /* Test cases: a mix of in-range and out-of-range examples */
    char *tests[] = {
        "2147483647",   // exactly INT_MAX (in range)
        "2147483646",   // in range
        "2147483648",   // one more than INT_MAX (out of range)
        "-2147483648",  // exactly INT_MIN (in range)
        "-2147483647",  // in range
        "-2147483649",  // one less than INT_MIN (out of range)
        "0000123",      // in range (leading zeros)
        "+123",         // in range with plus sign
        "-000001",      // in range (with sign and zeros)
        "12345678901",  // 11 digits (out of range)
        "987654321",    // 9 digits (in range)
        "214748364",    // 9 digits (in range)
    };
    
    int num_tests = sizeof(tests) / sizeof(tests[0]);
    int i;
    
    for (i = 0; i < num_tests; i++)
    {
        if (arg_is_int(tests[i]))
            printf("'%s' is in range\n", tests[i]);
        else
            printf("'%s' is out of range\n", tests[i]);
    }
    
    return 0;
}
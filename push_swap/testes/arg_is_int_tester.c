#include "push_swap.h"

int arg_is_int(char *arg)
{
    long long num = ft_atoll(arg);

    if (num < INT_MIN || num > INT_MAX)
        return (0); // NOT VALID

    return (1); //VALID
}


long long	ft_atoll(const char *str)
{
	int			sign;
	long long	r;

	sign = 1;
	r = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = sign * -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (r > (LONG_MAX - *str - '0') / 10)
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		r = r * 10 + *str++ - '0';
	}
	return (r * sign);
}

void test_ft_atoll()
{
    struct test_case {
        char *input;
        long long expected;
    } tests[] = {
        {"123", 123},
        {"-456", -456},
        {"2147483647", INT_MAX},
        {"-2147483648", INT_MIN},
        {"9223372036854775807", LLONG_MAX},  // Max long long
        {"-9223372036854775808", LLONG_MIN},  // Min long long
        {"0", 0}  // Min long long

    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++)
    {
        long long result = ft_atoll(tests[i].input);
        printf("Test %d: Input '%s' - Expected: %lld, Got: %lld - %s\n", 
               i + 1, 
               tests[i].input, 
               tests[i].expected, 
               result,
               (result == tests[i].expected) ? "PASS" : "FAIL");
    }
}

int main()
{
    test_ft_atoll();

}
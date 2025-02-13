#include <stdio.h>

int num_len(char *num)
{
    int i;
    int len;
    int sign;

    i = 0;
    len = 0;
    sign = 1;

    if (num[i] == '-' || num[i] == '+')
    {
        if (num[i] == '-')
            sign = -1;
        i++;
    }

    while (num[i] == '0')
        i++;

    // Count the remaining digits
    while (num[i] >= '0' && num[i] <= '9') 
    {
        len++;
        i++;
    }
    return (len * sign);
}

int main()
{
    char *num = "000023463264";
    printf("%d\n", num_len(num));

    char *num2 = "-23463264";
    printf("%d\n", num_len(num2));

    char *num3 = "0";
    printf("%d\n", num_len(num3));

    return 0;
}
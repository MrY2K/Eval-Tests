#include <limits.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	////---------------//---------------//---------------//---------------//---------------//---------------
	// * test %c
	char c = 'c';
	write(1, ">>>>>>>>>>TEST: %c \n", 20);
	int mi = ft_printf("MINE: %c\n", c);
	int og = printf("OG  : %c\n", c);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi, og);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %s
	char *s = "Hello!   there   !!! !!";
	write(1, ">>>>>>>>>>TEST: %s \n", 20);
	int mi0 = ft_printf("MINE: %s\n", s);
	int og0 = printf("OG  : %s\n", s);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi0, og0);
	char *s55 = NULL;
	write(1, ">>>>>>>>>>TEST: %s but s = null \n", 33);
	int mi55 = ft_printf("MINE: %s\n", s55);
	int og55 = printf("OG  : %s\n", s55);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi55, og55);
// // 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %d and %i
	int n = 0;
	write(1, ">>>>>>>>>>TEST1: %d INT_MAX\n", 28);
	int mi66 = ft_printf("MINE: %d\n", n);
	int og66 = printf("OG  : %d\n", n);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi66, og66);
	int n2 = INT_MIN;
	write(1, ">>>>>>>>>>TEST: %d INT_MIN\n", 27);
	int mi2 = ft_printf("MINE: %d\n", n2);
	int og2 = printf("OG  : %d\n", n2);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi2, og2);
	int n3 = INT_MAX;
	write(1, ">>>>>>>>>>TEST2: %d \n", 21);
	int mi3 = ft_printf("MINE: %d\n", n3);
	int og3 = printf("OG  : %d\n", n3);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi3, og3);
// // 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %u
	unsigned int n4 = 4294967295; //UINT_MAX
	write(1, ">>>>>>>>>>TEST3: %u \n", 21);
	int mi4 = ft_printf("MINE: %u\n", n4);
	int og4 = printf("OG  : %u\n", n4);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi4, og4);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %%
	char * n5 = "Hi %%";
	write(1, ">>>>>>>>>>TEST4: %% \n", 21);
	int mi5 = ft_printf("MINE: :%s:\n", n5);
	int og5 = printf("OG  : :%s:\n", n5);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi5, og5);
// ////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %z
	char * n6 = "Hi %z";
	write(1, ">>>>>>>>>>TEST5: %z \n", 21);
	int mi6 = ft_printf("MINE: :%s:\n", n6);
	int og6 = printf("OG  : :%s:\n", n6);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi6, og6);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %
	char * n7 = "Hi %";
	write(1, ">>>>>>>>>>TEST6: % \n", 21);
	int mi7 = ft_printf("MINE: :%s:\n", n7);
	int og7 = printf("OG  : :%s:\n", n7);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi7, og7);
// // 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %u
	unsigned int n8 = UINT_MAX; 
	write(1, ">>>>>>>>>>TEST7: %u \n", 21);
	int mi8 = ft_printf("MINE: %u\n", n8);
	int og8 = printf("OG  : %u\n", n8);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi8, og8);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %p
	void *ptr;
	write(1, ">>>>>>>>>>TEST8: %p \n", 21);
	int mi9 = ft_printf("MINE: %p\n", ptr);
	int og9 = printf("OG  : %p\n", ptr);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi9, og9);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test empty str
	char *str = "";
	write(1, ">>>>>>>>>>TEST9: %s \n", 21);
	int mi10 = ft_printf("MINE: %s\n", str);
	int og10 = printf("OG  : %s\n", str);
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi10, og10);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test overflow
	char *str2 = "hihi9";
	write(1, ">>>>>>>>>>TEST10: overflow \n", 28);
	int mi11 = ft_printf("%s%", str2);
	int og11 = printf("%s%", str2);
	printf("\n");
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi11, og11);
// 	////---------------//---------------//---------------//---------------//---------------//---------------
	// //* test %man
	write(1, ">>>>>>>>>>TEST10: %man \n", 24);
	int mi12 = ft_printf("%man");
	int og12 = printf("%man");
	printf("\n");
	printf("RETURNED MINE: %d\nRETURNED OG  : %d\n\n", mi12, og12);
// 	////---------------//---------------//---------------/2---------------//---------------//---------------
	write(1, ">>>>>>>>>>TEST11: Error \n", 25);
	int len = 0, len2 = 0;
	fclose(stdout);
	len = ft_printf("hello\n");
	if (len == - 1)
	{
		perror("ERROR IN MINE");
	}
	len2 = printf("hello\n");
	if (len2 == - 1)
	{
		perror("ERROR IN OG");
	}
	return 0;
}
// // #include "ft_printf.h"
// // #include <limits.h>
// // #include <stdio.h>
// // int main(void)
// // {
// // 	int i;
// // 	int len;
// //     int len2;
// //     unsigned int ui;
// //     void *addr;
// //     char *str = NULL;
// //     len = ft_printf("Let's try to printf a simple sentence.\n");
// //     len2 = printf("Let's try to printf a simple sentence.\n");
// //     ui = (unsigned int)INT_MAX + 1024;
// //     addr = (void *)0x7ffe637541f0;
// //     ft_printf("Length:[%d, %i]\n", len2, len2);
// //     printf("Length:[%d, %i]\n", len2, len2);
// //     ft_printf("Negative:[%d]\n", -762534);
// //     printf("Negative:[%d]\n", -762534);
// //     ft_printf("Unsigned:[%u]\n", ui);
// //     printf("Unsigned:[%u]\n", ui);
// //     ft_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
// //     printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
// //     ft_printf("Character:[%c]\n", 'H');
// //     printf("Character:[%c]\n", 'H');
// //     ft_printf("String:[%s]\n", "I am a string !");
// //     printf("String:[%s]\n", "I am a string !");
// //     ft_printf("Address:[%p]\n", addr);
// //     printf("Address:[%p]\n", addr);
// //     len = ft_printf("Percent:[%%]\n");
// //     len2 = printf("Percent:[%%]\n");
// //     ft_printf("Len:[%d]\n", len2);
// //     printf("Len:[%d]\n", len);
// //     ft_printf("%s\n", str);
// //     printf("%s\n", str);
// //     len = ft_printf("%");
// //     len2 = printf("%");
// //     printf("len[%d] == len[%d]\n", len, len2);
// //     len = ft_printf("%m\n");
// //     len2 = printf("%m\n");
// //     printf("len[%d] == len[%d]\n", len, len2);
// //     return (0);
// // }

//! TESTS 3
// #include <stdio.h>
// #include <limits.h>
// void	test_simple(void)
// {
// 	int	x;
// 	int	y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: simple string -----------\n\n");
// 	printf("Testing: (\"\\tHello!\\n\")\n");
// 	x += printf("  Or\t:\tHello!\n");
// 	y += ft_printf("  Ft\t:\tHello!\n");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_percent(void)
// {
// 	int	x;
// 	int	y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: percent -----------\n\n");
// 	printf("Testing: (\"\\t%%%%\\n\")\n");
// 	x += printf("  Or\t:\t%%\n");
// 	y += ft_printf("  Ft\t:\t%%\n");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_c(void)
// {
// 	int	x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: %%c -----------\n\n");
// 	printf("Testing: (\"\\t%%c\\n\", 'a')\n");
// 	x += printf("  Or\t:\t%c\n", 'a');
// 	y += ft_printf("  Ft\t:\t%c\n", 'a');
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe character %%c is visible.\\n\", 'x')\n");
// 	x += printf("  Or\t:\tThe character %c is visible.\n", 'x');
// 	y += ft_printf("  Ft\t:\tThe character %c is visible.\n", 'x');
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_s(void)
// {
// 	int	x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: %%s -----------\n\n");
// 	printf("Testing: (\"\\t%%s\\n\", \"coucou, ca va?\")\n");
// 	x += printf("  Or\t:\t%s\n", "coucou, ca va?");
// 	y += ft_printf("  Ft\t:\t%s\n", "coucou, ca va?");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe string \\\"%%s\\\" is visible.\\n\", \"TRALALA\")\n");
// 	x += printf("  Or\t:\tThe string \"%s\" is visible.\n", "TRALALA");
// 	y += ft_printf("  Ft\t:\tThe string \"%s\" is visible.\n", "TRALALA");
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	char *s = NULL;
// 	if (s == NULL)
// 		write(1, "(null)\n", 7);
// 	printf("Testing: (\"\\tNULL %%s NULL.\\n\", NULL)\n");
// 	x += printf("  Or\t:\tNULL %s NULL.\n", s);
// 	y += ft_printf("  Ft\t:\tNULL %s NULL.\n", s);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_d(void)
// {
// 	int x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: %%d -----------\n\n");
// 	printf("Testing: (\"\\t%%d\\n\", 42)\n");
// 	x += printf("  Or\t:\t%d\n", 42);
// 	y += ft_printf("  Ft\t:\t%d\n", 42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe number %%d is visible.\\n\", 5671)\n");
// 	x += printf("  Or\t:\tThe number %d is visible.\n", 5671);
// 	y += ft_printf("  Ft\t:\tThe number %d is visible.\n", 5671);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%d\\n\", INT_MAX)\n");
// 	x += printf("  Or\t:\t%d\n", INT_MAX);
// 	y += ft_printf("  Ft\t:\t%d\n", INT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%d\\n\", INT_MIN)\n");
// 	x += printf("  Or\t:\t%d\n", INT_MIN);
// 	y += ft_printf("  Ft\t:\t%d\n", INT_MIN);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%i\\n\", INT_MIN - INT_MIN)\n");
// 	x += printf("  Or\t:\t%i\n", INT_MIN - INT_MIN);
// 	y += ft_printf("  Ft\t:\t%i\n", INT_MIN - INT_MIN);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_i(void)
// {
// 	int x, y;
// 	printf("\n----------- TEST: %%i -----------\n\n");
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%i\\n\", 4422)\n");
// 	x += printf("  Or\t:\t%i\n", 4422);
// 	y += ft_printf("  Ft\t:\t%i\n", 4422);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe number %%i is visible.\\n\", 0)\n");
// 	x += printf("  Or\t:\tThe number %i is visible.\n", 0);
// 	y += ft_printf("  Ft\t:\tThe number %i is visible.\n", 0);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%i\\n\", INT_MAX)\n");
// 	x += printf("  Or\t:\t%i\n", INT_MAX);
// 	y += ft_printf("  Ft\t:\t%i\n", INT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%i\\n\", INT_MIN)\n");
// 	x += printf("  Or\t:\t%i\n", INT_MIN);
// 	y += ft_printf("  Ft\t:\t%i\n", INT_MIN);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%i\\n\", INT_MIN + INT_MAX)\n");
// 	x += printf("  Or\t:\t%i\n", INT_MIN + INT_MAX);
// 	y += ft_printf("  Ft\t:\t%i\n", INT_MIN + INT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_x(void)
// {
// 	int	x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: %%x -----------\n\n");
// 	printf("Testing: (\"\\t%%x\\n\", 42)\n");
// 	x += printf("  Or\t:\t%x\n", 42);
// 	y += ft_printf("  Ft\t:\t%x\n", 42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe hex number %%x is visible.\\n\", 5671)\n");
// 	x += printf("  Or\t:\tThe hex number %x is visible.\n", 5671);
// 	y += ft_printf("  Ft\t:\tThe hex number %x is visible.\n", 5671);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%x\\n\", INT_MAX)\n");
// 	x += printf("  Or\t:\t%x\n", INT_MAX);
// 	y += ft_printf("  Ft\t:\t%x\n", INT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%x\\n\", INT_MIN)\n");
// 	x += printf("  Or\t:\t%x\n", INT_MIN);
// 	y += ft_printf("  Ft\t:\t%x\n", INT_MIN);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%x\\n\", -42)\n");
// 	x += printf("  Or\t:\t%x\n", -42);
// 	y += ft_printf("  Ft\t:\t%x\n", -42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%x\\n\", UINT_MAX)\n");
// 	x += printf("  Or\t:\t%x\n", UINT_MAX);
// 	y += ft_printf("  Ft\t:\t%x\n", UINT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_X(void)
// {
// 	int	x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: %%X -----------\n\n");
// 	printf("Testing: (\"\\t%%X\\n\", 42)\n");
// 	x += printf("  Or\t:\t%X\n", 42);
// 	y += ft_printf("  Ft\t:\t%X\n", 42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe hex number %%X is visible.\\n\", 5671)\n");
// 	x += printf("  Or\t:\tThe hex number %X is visible.\n", 5671);
// 	y += ft_printf("  Ft\t:\tThe hex number %X is visible.\n", 5671);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%X\\n\", INT_MAX)\n");
// 	x += printf("  Or\t:\t%X\n", INT_MAX);
// 	y += ft_printf("  Ft\t:\t%X\n", INT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%X\\n\", INT_MIN)\n");
// 	x += printf("  Or\t:\t%X\n", INT_MIN);
// 	y += ft_printf("  Ft\t:\t%X\n", INT_MIN);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%X\\n\", -42)\n");
// 	x += printf("  Or\t:\t%X\n", -42);
// 	y += ft_printf("  Ft\t:\t%X\n", -42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%X\\n\", UINT_MAX)\n");
// 	x += printf("  Or\t:\t%X\n", UINT_MAX);
// 	y += ft_printf("  Ft\t:\t%X\n", UINT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_u(void)
// {
// 	int	x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: %%u -----------\n\n");
// 	printf("Testing: (\"\\t%%u\\n\", 42)\n");
// 	x += printf("  Or\t:\t%u\n", 42);
// 	y += ft_printf("  Ft\t:\t%u\n", 42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\tThe number %%u is visible.\\n\", 5671)\n");
// 	x += printf("  Or\t:\tThe number %u is visible.\n", 5671);
// 	y += ft_printf("  Ft\t:\tThe number %u is visible.\n", 5671);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%u\\n\", INT_MAX)\n");
// 	x += printf("  Or\t:\t%u\n", INT_MAX);
// 	y += ft_printf("  Ft\t:\t%u\n", INT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%u\\n\", INT_MIN)\n");
// 	x += printf("  Or\t:\t%u\n", INT_MIN);
// 	y += ft_printf("  Ft\t:\t%u\n", INT_MIN);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%u\\n\", -42)\n");
// 	x += printf("  Or\t:\t%u\n", -42);
// 	y += ft_printf("  Ft\t:\t%u\n", -42);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%u\\n\", UINT_MAX)\n");
// 	x += printf("  Or\t:\t%u\n", UINT_MAX);
// 	y += ft_printf("  Ft\t:\t%u\n", UINT_MAX);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_p(void)
// {
// 	int	x, y;
// 	printf("\n----------- TEST: %%p -----------\n\n");
// 	x = 0;
// 	y = 0;
// 	int	n;
// 	char	c;
// 	void	*p;
// 	n = 50;
// 	c = 'a';
// 	p = NULL;
// 	printf("Testing: (\"\\t%%p\\n\", (void *)&n)\n");
// 	x += printf("  Or\t:\t%p\n", (void *)&n);
// 	y += ft_printf("  Ft\t:\t%p\n", (void *)&n);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%p\\n\", (void *)&c)\n");
// 	x += printf("  Or\t:\t%p\n", (void *)&c);
// 	y += ft_printf("  Ft\t:\t%p\n", (void *)&c);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// 	x = 0;
// 	y = 0;
// 	printf("Testing: (\"\\t%%p\\n\", p)\n");
// 	x += printf("  Or\t:\t%p\n", p);
// 	y += ft_printf("  Ft\t:\t%p\n", p);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// void	test_all(void)
// {
// 	int	x, y;
// 	x = 0;
// 	y = 0;
// 	printf("\n----------- TEST: ALL -----------\n\n");
// 	printf("Testing: (\"\\tThe int is %%i or %%d, the char is %%c, the string is \\\"%%s\\\", the hex is %%x or %%X, the unsigned is %%u and the percent is %%%%.\\n\", 42, -42, 's', \"Hello\", 42, 42, 242)\n");
// 	x += printf("  Or\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
// 	y += ft_printf("  Or\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
// 	printf("Printf = %d, ft_printf = %d\n\n", x, y);
// }
// int	main(void)
// {
// 	printf("\n\n========== MANDATORY TESTS ========\n\n");
// 	test_simple();
// 	test_percent();
// 	test_c();
// 	test_s();
// 	test_d();
// 	test_i();
// 	test_x();
// 	test_X();
// 	test_u();
// 	test_p();
// 	test_all();
// 	return (0);
// }
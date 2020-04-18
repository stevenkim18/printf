#include "ft_printf.h"

int main(void)
{	
	// int ret = printf("%%0i 42 == |%0i|", 42);
	// printf("\n");
	// printf("printf ret = %d\n", ret);
	//char *ptr = "HEllo";
	int ret = ft_printf("%4.5p", "123");
	printf("\n");
	printf("   printf --> ret = %d\n", ret);
	printf("------------------------------------\n");
}

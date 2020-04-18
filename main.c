#include "ft_printf.h"

int main(void)
{	
	// int ret = printf("%%0i 42 == |%0i|", 42);
	// printf("\n");
	// printf("printf ret = %d\n", ret);
	//char *ptr = "HEllo";
	printf("\n");
	int ret = printf("%d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
	printf("\n");
	printf("   printf --> ret = %d\n", ret);
	printf("------------------------------------\n");
	ret = ft_printf("%d\n\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n\n", 42, -42));
	printf("\n");
	printf("ft_printf --> ret = %d\n", ret);
	printf("------------------------------------\n");
}

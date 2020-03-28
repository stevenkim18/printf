#include "libftprintf.h"

int main(void)
{
	printf("%-5c\n", 'a');
	printf("%5c\n", 'a');
	printf("%.c\n", 'a');
	printf("%-.c\n", 'a');
}


#include "ft_printf.h"
#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "");
	int i = 0;
	while (i < 100000)
	{
		ft_printf("%C\n", L'♥');
		i++;
	}
	//printf("%d\n", ft_printf("The - [%5.3s] --> [%+lld] <-- \n", "Piglads", 9223372036854775807));
	//printf("%d\n", printf("The - [%5.3s] --> [%+lld] <-- \n", "Piglads", 9223372036854775807));
	//ft_printf("Hello World! %s\n", "LOL");
	// printf("(1)%d\n", ft_printf("MINE1>\t[%30%]\n", 25, 16215));
	// printf("(1)%d\n", printf("ORIG1>\t[%30%]\n", 25, 16215));

	// printf("(2)%d\n", ft_printf("MINE2>\t[%hhd]\n", 123456789));
	// printf("(2)%d\n", printf("ORIG2>\t[%hhd]\n", 123456789));

	// printf("(3)%d\n", ft_printf("MINE3>\t[%jd]\n", 123456789));
	// printf("(3)%d\n", printf("ORIG3>\t[%jd]\n", 123456789));

	// printf("(4)%d\n", ft_printf("MINE4>\t[%zd]\n", 123456789));
	// printf("(4)%d\n", printf("ORIG4>\t[%zd]\n", 123456789));
	return (0);
}
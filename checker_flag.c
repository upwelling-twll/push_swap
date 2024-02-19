#include "push_swap.h"
#include "checker_inc.c"
#include "libft/ft_atoi.c"

int	is_flag(char *argv[])
{
	char	*str1;
	char	*flags[] = "cflvhs";
	char	flag;

	str1 = *argv;
	while(*str1 != '\0')
	{
		if (!ft_strrchr(flags, *str1))
			return(-1);
		
	}
	if (*argv[0] == '-' && !(verify_atoi(*argv)))
	{
		if(*argv[1] == 'f')
		{
			argv++;
			parse_fname(*argv);
		}
		if (*argv[)
	}
}

void	process_flag_input(char *str)
{

}

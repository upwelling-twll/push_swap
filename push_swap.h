#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct ss_list
{
	struct ss_list	*prev;
	int				data;
	struct ss_list	*next;
}					tt_list;

#endif
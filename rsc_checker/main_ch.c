/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:41:11 by nmagdano          #+#    #+#             */
/*   Updated: 2024/03/08 13:59:43 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_llist	*lst;
	t_llist	*stack2;
	t_chins	*oper;

	if (argc < 2)
		return (0);
	lst = malloc(sizeof(t_llist));
	stack2 = NULL;
	if (!(ft_parse_input_ch(argc, argv, &lst)))
		return (0);
	if (!(parse_instr(&lst, &oper)))
		return (0);
	return (apply_instructions(&lst, &stack2, oper));
}

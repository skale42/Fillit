/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:26:45 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/04 21:07:04 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_three(int num_tet, unsigned int *tet)
{
	int i;
	int flag;

	i = 0;
	if (num_tet == 1 && tet[0] == 52224)
		return (2);
	flag = 0;
	while (i < num_tet)
	{
		if (((61152 | tet[i]) ^ 61152) != 0)
			flag = flag | 1;
		i++;
	}
	if (flag)
		return (4);
	return (3);
}

size_t	ft_calc_field(int num_tet, unsigned int *tet)
{
	int	pre;

	pre = 0;
	if (num_tet > 2)
	{
		pre = num_tet * 4;
		while (ft_sqrt(pre) == 0)
			pre++;
		return (ft_sqrt(pre));
	}
	return (ft_three(num_tet, tet));
}

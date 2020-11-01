/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:07:52 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/07 17:59:24 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned int	ft_offset_xy(t_tetr *list, t_tetr *t)
{
	unsigned int offset_xy;
	unsigned int var_for_linuz_gcc_1;
	unsigned int var_for_linuz_gcc_2;

	offset_xy = list->x >= t->x ? ft_mleft(t->t, (list->x - t->x)) \
	: ft_mright(t->t, (t->x - list->x));
	var_for_linuz_gcc_1 = offset_xy >> (ft_abs((t->y - list->y)) * 4);
	var_for_linuz_gcc_2 = ft_mup(offset_xy, list->y - t->y);
	offset_xy = list->y >= t->y ? var_for_linuz_gcc_2 : var_for_linuz_gcc_1;
	return (offset_xy);
}

int				ft_far(t_tetr *list, t_tetr *t)
{
	if ((ft_abs(list->y - t->y) > 3) || (ft_abs(list->y - t->y) > 3))
		return (1);
	return (0);
}

int				ft_find_x(t_tetr *list, size_t *field)
{
	int			res;
	t_tetr		*t;

	t = list->prev;
	res = 1;
	while (t && res != 0)
	{
		res = 0;
		if (ft_far(list, t) || ((ft_offset_xy(list, t) & list->t) == 0))
			res = res | 1;
		t = t->prev;
	}
	if (res == 1)
		return (1);
	if (!ft_can_we_movex(list, field))
	{
		list->x = 0;
		return (0);
	}
	list->x++;
	if (ft_find_x(list, field))
		return (1);
	list->x = 0;
	return (0);
}

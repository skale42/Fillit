/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:54:05 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/14 14:42:01 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_find_xy(t_tetr *list, size_t *field)
{
	int		find_x;

	if (list->prev == NULL)
		return (1);
	find_x = ft_find_x(list, field);
	if (find_x)
		return (1);
	if (!ft_can_we_movey(list, field))
		return (0);
	list->y++;
	if (ft_find_xy(list, field))
		return (1);
	else
	{
		list->x = 0;
		list->y = 0;
		return (0);
	}
}

void	ft_zero(t_tetr *list)
{
	list->x = 0;
	list->y = 0;
}

int		ft_fuck_norme(t_tetr *list, size_t *field)
{
	if (!ft_can_we_movex(list, field))
	{
		if (!ft_can_we_movey(list, field))
		{
			ft_zero(list);
			return (0);
		}
		list->x = 0;
		list->y++;
		if (ft_puzzle(list, field))
			return (1);
		return (0);
	}
	list->x++;
	if (ft_puzzle(list, field))
		return (1);
	return (0);
}

int		ft_puzzle(t_tetr *list, size_t *field)
{
	if (!ft_find_xy(list, field))
	{
		ft_zero(list);
		return (0);
	}
	if (list->next == NULL || ft_puzzle(list->next, field))
		return (1);
	else
		return (ft_fuck_norme(list, field));
}

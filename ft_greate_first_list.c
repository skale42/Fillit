/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_greate_first_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:09:35 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/15 19:07:49 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr		*ft_greate_first_list(unsigned int tetr, char letter)
{
	t_tetr	*ttetr;

	ttetr = (t_tetr*)malloc(sizeof(t_tetr));
	if (!ttetr)
		return (0);
	ttetr->next = NULL;
	ttetr->prev = NULL;
	ttetr->t = tetr;
	ttetr->x = 0;
	ttetr->y = 0;
	ttetr->letter = letter;
	return (ttetr);
}

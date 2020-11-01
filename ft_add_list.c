/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:19:26 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/11 22:21:11 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*ft_add_list(t_tetr *result, unsigned int tet, char letter)
{
	t_tetr *new;

	while (result->next != NULL)
		result = result->next;
	new = malloc(sizeof(t_tetr));
	result->next = new;
	new->prev = result;
	new->next = NULL;
	new->letter = letter;
	new->t = tet;
	new->x = 0;
	new->y = 0;
	return (result);
}

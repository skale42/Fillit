/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:37:09 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/14 14:05:55 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_list(t_tetr *result)
{
	t_tetr *buf;

	while (result)
	{
		result->prev = NULL;
		buf = result->next;
		result->next = NULL;
		free(result);
		result = buf;
	}
	result = NULL;
}

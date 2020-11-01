/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mright.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:48:55 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/07 18:00:31 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_mover(unsigned int d)
{
	return (((d | 4369) ^ 4369) >> 1);
}

unsigned int		ft_mright(unsigned int d, int offcet)
{
	int i;

	i = 0;
	while (i < offcet)
	{
		d = ft_mover(d);
		i++;
	}
	return (d);
}

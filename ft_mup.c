/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:06:56 by mstefani          #+#    #+#             */
/*   Updated: 2019/11/20 20:48:00 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_moveup(unsigned int d)
{
	return (((d | 61440) ^ 61440) << 4);
}

unsigned int		ft_mup(unsigned int d, int offcet)
{
	int i;

	i = 0;
	while (i < offcet)
	{
		d = ft_moveup(d);
		i++;
	}
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mleft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:51:39 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/04 13:34:09 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_move(unsigned int d)
{
	return (((d | 34952) ^ 34952) << 1);
}

unsigned int		ft_mleft(unsigned int d, int offcet)
{
	int i;

	i = 0;
	while (i < offcet)
	{
		d = ft_move(d);
		i++;
	}
	return (d);
}

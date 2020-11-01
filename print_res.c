/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:53:43 by skale             #+#    #+#             */
/*   Updated: 2019/12/14 17:29:15 by skale            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_if(int *pryg, int *i, int dlina)
{
	if (*pryg == 3)
	{
		*i = *i + dlina - 4;
		*pryg = 0;
	}
	*pryg = *pryg + 1;
}

void				perevod(char *res, int dlina, t_tetr *lst, int i)
{
	unsigned int	digits;
	int				pryg;
	int				tetr_num;

	tetr_num = 0;
	while (ft_l(lst, tetr_num))
	{
		i = ft_l(lst, tetr_num)->x + (ft_l(lst, tetr_num)->y * dlina);
		digits = 0b1000000000000000;
		pryg = 0;
		while (digits > 0)
		{
			if (ft_l(lst, tetr_num)->t >= digits && digits != 0)
			{
				ft_l(lst, tetr_num)->t = ft_l(lst, tetr_num)->t - digits;
				res[i] = ft_l(lst, tetr_num)->letter;
			}
			digits = digits >> 1;
			i++;
			ft_if(&pryg, &i, dlina);
		}
		tetr_num++;
	}
}

int					print_res(t_tetr *lst, int dlina)
{
	int				i;
	char			res[dlina * dlina];

	i = 0;
	res[dlina * dlina] = '\0';
	while (i < (dlina * dlina))
	{
		res[i] = '.';
		i++;
	}
	i = 0;
	perevod(res, dlina, lst, i);
	while (res[i] != '\0')
	{
		(i % dlina == 0 && i != 0) ? write(1, "\n", 1) : 1;
		write(1, &res[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

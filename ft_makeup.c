/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:04:24 by skale             #+#    #+#             */
/*   Updated: 2019/12/14 19:02:11 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_up_left(int k)
{
	if (k == 0)
		return (k);
	while (k < 0b1000000000000)
		k = k << 4;
	while ((0b1000100010001000 & k) == 0)
		k = k << 1;
	return (k);
}

int					ft_error(unsigned int k)
{
	if (k != 34952 && k != 61440 && k != 52224 && k != 35008)
	{
		if (k != 50240 && k != 59392 && k != 11776 && k != 51328)
		{
			if (k != 17600 && k != 36352 && k != 57856 && k != 35904)
			{
				if (k != 27648 && k != 19584 && k != 50688 && k != 19968)
				{
					if (k != 19520 && k != 35968 && k != 58368)
						return (-1);
				}
			}
		}
	}
	return (1);
}

unsigned int		*num(char *str, unsigned int *new)
{
	int				i;
	int				j;
	int				ret;

	i = 0;
	j = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			new[j] = ft_up_left(ret);
			if (ft_error(new[j]) == -1)
				return (0);
			j++;
			ret = 0;
		}
		if (str[i] != '\n')
			ret = ret * 2 + (str[i] - '0');
		i++;
	}
	return (new);
}

int					proverochka(char *str)
{
	int				i;
	int				tch;
	int				resh;
	int				new;

	i = 0;
	while (str[i] != '\0')
	{
		tch = 0;
		resh = 0;
		new = 0;
		while (str[i] != '\n' || (str[i + 1] != '\n' && str[i + 1] != '\0'))
		{
			str[i] == '.' ? tch++ : tch;
			str[i] == '#' ? resh++ : resh;
			(str[i] == '\n' && str[i - 1] != '\n') ? new++ : new;
			if (!(str[i] == '.' || str[i] == '#' || str[i] == '\n'))
				return (0);
			i++;
		}
		if (resh != 4 || tch != 12 || new != 3)
			return (0);
		(resh == 4 && tch == 12 && new == 3) ? i = i + 1 : 1;
	}
	return (1);
}

unsigned int		*ft_makeup(int fd)
{
	static char		*str;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	unsigned int	*new;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	if (((!str) || proverochka(str) == 0) || \
			!(new = (unsigned int*)malloc(sizeof(unsigned int) * schet1(str))))
	{
		write(1, "error\n", 6);
		return (0);
	}
	new = num(str, new);
	if (new == NULL)
		write(1, "error\n", 6);
	close(fd);
	free(str);
	return (new);
}

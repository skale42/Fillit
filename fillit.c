/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <mstefani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:54:06 by mstefani          #+#    #+#             */
/*   Updated: 2019/12/14 19:04:03 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_refresh_list(t_tetr *tet)
{
	t_tetr *buf;

	buf = tet;
	while (buf)
	{
		buf->x = 0;
		buf->y = 0;
		buf = buf->next;
	}
	return (1);
}

int		ft_check_file(int argc, char *argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		write(1, "can't open file ", 16);
		ft_putendl(argv);
		return (0);
	}
	return (1);
}

t_tetr	*ft_make_list(unsigned int *tet, size_t num_tet)
{
	t_tetr	*test;
	t_tetr	*result;
	size_t	i;

	i = 0;
	result = ft_greate_first_list(tet[0], 'A');
	test = result;
	while (++i < num_tet)
		test = ft_add_list(result, tet[i], ('A' + i));
	return (result);
}

int		main(int argc, char **argv)
{
	unsigned int	*tet;
	size_t			num_tet;
	t_tetr			*result;
	size_t			field;

	if ((!ft_check_file(argc, argv[1])) \
			|| (!((tet = ft_makeup(open(argv[1], O_RDONLY))))))
		return (0);
	num_tet = ft_calc(open(argv[1], O_RDONLY));
	field = ft_calc_field(num_tet, tet);
	result = ft_make_list(tet, num_tet);
	ft_memdel((void*)&tet);
	while (!ft_puzzle(result, &field))
	{
		ft_refresh_list(result);
		field++;
	}
	print_res(result, field);
	ft_free_list(result);
	return (0);
}

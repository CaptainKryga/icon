/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 17:30:14 by jbashiri          #+#    #+#             */
/*   Updated: 2019/05/08 10:17:44 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_texture   *get_player(char *name)
{
	/*
	 * android
	 */
	if (!ft_strcmp("android=10", name))
		return (get_texture("players/android=10.bmp"));
	else if (!ft_strcmp("android=15", name))
		return (get_texture("players/android=15.bmp"));
	else if (!ft_strcmp("android=20", name))
		return (get_texture("players/android=20.bmp"));
	else if (!ft_strcmp("android=10-1", name))
		return (get_texture("players/android=10-1.bmp"));
	/*
	 * horde
	 */
	else if (!ft_strcmp("horde=10", name))
		return (get_texture("players/horde=10.bmp"));
	else if (!ft_strcmp("horde=15", name))
		return (get_texture("players/horde=15.bmp"));
	else if (!ft_strcmp("horde=20", name))
		return (get_texture("players/horde=20.bmp"));
	else if (!ft_strcmp("horde=22", name))
		return (get_texture("players/horde=22.bmp"));
	/*
	 * alliance
	 */
	else if (!ft_strcmp("alliance=10", name))
		return (get_texture("players/alliance=10.bmp"));
	else if (!ft_strcmp("alliance=15", name))
		return (get_texture("players/alliance=15.bmp"));
	else if (!ft_strcmp("alliance=20", name))
		return (get_texture("players/alliance=20.bmp"));
	else if (!ft_strcmp("alliance=21", name))
		return (get_texture("players/alliance=21.bmp"));
	else if (!ft_strcmp("alliance=22", name))
		return (get_texture("players/alliance=22.bmp"));
	/*
	 * wow
	 */
	else if (!ft_strcmp("wow=20v1", name))
		return (get_texture("players/wow=20v1.bmp"));
	/*
	 * GOT
	 */
	else if (!ft_strcmp("GOT_stark=20", name))
		return (get_texture("players/GOT_stark=20.bmp"));
	return (NULL);
}

int    **apple(t_window *win)
{
	char *apple;
	int **player1;
	int  x, y, z;

	/*
	 * 20x20
	 */
	apple ="00000000000023000000\n"
	       "00000000003213000000\n"
	       "00000000002113000000\n"
	       "00000000001130000000\n"
	       "00000022002333300000\n"
	       "00002111122111120000\n"
	       "00031111111111113000\n"
	       "00021111111111130000\n"
	       "00011111111111200000\n"
	       "00311111111111300000\n"
	       "00311111111111200000\n"
	       "00011111111111130000\n"
	       "00021111111111123000\n"
	       "00031111111111112000\n"
	       "00002111111111113000\n"
	       "00003111111111112000\n"
	       "00000211111111113000\n"
	       "00000032330322300000\n"
	       "00000000000000000000";
	player1 = (int**)malloc(sizeof(int*) * 20);
	y = 0;
	z = 0;
	while (y < 20)
	{
		x = 0;
		player1[y] = (int*)malloc(sizeof(int) * 20);
		while (x < 20)
		{
			if (apple[z] == '0')
				player1[y][x] = 0xECF104;//белый
			else if (apple[z] == '1')
				player1[y][x] = 0x000000;//черный
			else if (apple[z] == '2')
				player1[y][x] = 0x636363;//светлочерный
			else if (apple[z] == '3')
				player1[y][x] = 0xB0B0B0;//сильносветлочерный
			x++;
			z++;
			if (apple[z] == '\n')
			{
				z++;
				break ;
			}
		}
		y++;
	}
	return (player1);
}


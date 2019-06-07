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

void    print_player(t_texture *player, int pos_y, int pos_x, t_window *win)
{
	int x, y, z;

	y = z = 0;
	while (y < player->h)
	{
		x = 0;
		while (x < player->w)
		{
//			if (win->player1->pixels[z] != 0xFFFFFF)//убираем фон(белый)
				mlx_pixel_put(win->mlx, win->win, x + pos_x, y + pos_y, player->pixels[z]);
			x++;
			z++;
		}
		y++;
	}
}

int     main()
{
	t_window	*win;
	t_texture   *player1, *player2, *player3, *player4;
	int         *fraction1, *fraction2, *fraction3, *fraction4;

	win = inicialization_win();
	win->win = mlx_new_window(win->mlx, SIZEX, SIZEY, "icon");
	/*
	player1 = get_texture("players/alliance=15");
	player2 = get_texture("players/horde=15");
	player3 = get_texture("players/undead");
	player4 = get_texture("players/elf");
	if (player1 != NULL)
		print_player(player1, 0, 0, win);
	if (player2 != NULL)
		print_player(player2, 0, 20, win);
	if (player3 != NULL)
		print_player(player3, 0, 40, win);
	if (player4 != NULL)
		print_player(player4, 0, 60, win);
*/
	int size_line = 1000;
	int bpp = 8;
	int endian = 0;
	int fd, i;
	char *path;
	char *line;
	char hex[6];
	win->img = mlx_new_image(win->mlx, 15, 15);
	path = "players/hexHorde";
	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("10");
		exit (10);
	}
	get_next_line(fd, &line);
	ft_printf("l: %s\n", line);
	fraction1 = (int *)mlx_get_data_addr(win->img, &bpp, &size_line, &endian);
	i = 0;
	while (i < 225)
	{
		hex[0] = line[2];
		hex[1] = line[3];
		hex[2] = line[7];
		hex[3] = line[8];
		hex[4] = line[12];
		hex[5] = line[13];
		fraction1[i] = ft_atoi_hex(hex);
		ft_printf("%s %d\n", hex, fraction1[i]);
		line += 15;
		i++;
	}
	close(fd);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 100, 100);
	controls(win);
	mlx_loop(win->mlx);
	return (0);
}


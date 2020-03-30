/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:04:13 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 20:25:01 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_bmp_header(int fd, t_bfh *bfh, t_bih *bih)
{
	write(fd, &bfh->bitmap_type, sizeof(unsigned char) * 2);
	write(fd, &bfh->file_size, sizeof(int));
	write(fd, &bfh->reserved1, sizeof(short int));
	write(fd, &bfh->reserved2, sizeof(short int));
	write(fd, &bfh->offset_bits, sizeof(unsigned int));
	write(fd, &bih->size_header, sizeof(unsigned int));
	write(fd, &bih->width, sizeof(unsigned int));
	write(fd, &bih->height, sizeof(unsigned int));
	write(fd, &bih->planes, sizeof(short int));
	write(fd, &bih->bit_count, sizeof(short int));
	write(fd, &bih->compression, sizeof(unsigned int));
	write(fd, &bih->image_size, sizeof(unsigned int));
	write(fd, &bih->ppm_x, sizeof(unsigned int));
	write(fd, &bih->ppm_y, sizeof(unsigned int));
	write(fd, &bih->clr_used, sizeof(unsigned int));
	write(fd, &bih->clr_important, sizeof(unsigned int));
}

void	init_bmp_header(t_c3d *t, t_bfh *bfh, t_bih *bih)
{
	int	dpi;

	dpi = 96;
	ft_memcpy(&bfh->bitmap_type, "BM", 2);
	bfh->file_size = 54 + 4 * (t->winw * t->winh);
	bfh->reserved1 = 0;
	bfh->reserved2 = 0;
	bfh->offset_bits = 0;
	bih->size_header = sizeof(t_bih);
	bih->width = t->winw;
	bih->height = t->winh;
	bih->planes = 1;
	bih->bit_count = 24;
	bih->compression = 0;
	bih->image_size = t->winw * t->winh;
	bih->ppm_x = dpi * 39.375;
	bih->ppm_y = dpi * 39.375;
	bih->clr_used = 0;
	bih->clr_important = 0;
}

void	create_bmp(t_c3d *t)
{
	t_bfh			bfh;
	t_bih			bih;
	int				fd;
	int				*pxl;
	int				x;
	int				y;

	init_bmp_header(t, &bfh, &bih);
	fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	fill_bmp_header(fd, &bfh, &bih);
	y = t->winh + 1;
	while (--y > 0 && (x = -1))
	{
		while (++x < t->winw)
		{
			pxl = (int*)(t->imgptr + 4 * (t->winw * y + x));
			write(fd, pxl, sizeof(char) * 3);
		}
	}
	close(fd);
}

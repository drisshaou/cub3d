/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaouhao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 01:04:13 by dhaouhao          #+#    #+#             */
/*   Updated: 2020/03/29 21:28:24 by dhaouhao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_bmp_header(int fd, t_bmp *bmp)
{
	write(fd, &bmp->bitmap_type, sizeof(unsigned char) * 2);
	write(fd, &bmp->file_size, sizeof(int));
	write(fd, &bmp->reserved1, sizeof(short int));
	write(fd, &bmp->reserved2, sizeof(short int));
	write(fd, &bmp->offset_bits, sizeof(unsigned int));
	write(fd, &bmp->size_header, sizeof(unsigned int));
	write(fd, &bmp->width, sizeof(unsigned int));
	write(fd, &bmp->height, sizeof(unsigned int));
	write(fd, &bmp->planes, sizeof(short int));
	write(fd, &bmp->bit_count, sizeof(short int));
	write(fd, &bmp->compression, sizeof(unsigned int));
	write(fd, &bmp->image_size, sizeof(unsigned int));
	write(fd, &bmp->ppm_x, sizeof(unsigned int));
	write(fd, &bmp->ppm_y, sizeof(unsigned int));
	write(fd, &bmp->clr_used, sizeof(unsigned int));
	write(fd, &bmp->clr_important, sizeof(unsigned int));
}

void	init_bmp_header(t_c3d *t, t_bmp *bmp)
{
	int	dpi;

	dpi = 96;
	ft_memcpy(&bmp->bitmap_type, "BM", 2);
	bmp->file_size = 54 + 4 * (t->winw * t->winh);
	bmp->reserved1 = 0;
	bmp->reserved2 = 0;
	bmp->offset_bits = 0;
	bmp->size_header = sizeof(unsigned int) * 9 + sizeof(short int) * 2;
	bmp->width = t->winw;
	bmp->height = t->winh;
	bmp->planes = 1;
	bmp->bit_count = 24;
	bmp->compression = 0;
	bmp->image_size = t->winw * t->winh;
	bmp->ppm_x = dpi * 39.375;
	bmp->ppm_y = dpi * 39.375;
	bmp->clr_used = 0;
	bmp->clr_important = 0;
}

void	create_bmp(t_c3d *t)
{
	t_bmp	bmp;
	int		fd;
	int		*pxl;
	int		x;
	int		y;

	init_bmp_header(t, &bmp);
	fd = open("img.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	fill_bmp_header(fd, &bmp);
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

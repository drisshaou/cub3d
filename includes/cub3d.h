# ifndef CUB3D_H
# define CUB3D_H

# define CANT_RD_CUB "Can't read the .cub file\n"
# define CANT_RD_XPM "Can't read the .xpm file\n"
# define MAP_NOT_CORRECT "The map is not correct.\n"
# define TOO_MUCH_PLAYERS "Too much players on map.\n"
# define CANT_FIND_PLAYER "Can't find a player on map.\n"
# define CANT_MALLOC_MAP "Can't allocate memory for map.\n"
# define CANT_CHECK_MAP "Can't check map validity.\n"
# define MAP_INVALID "The map is not valid.\n"
# define NOT_XPM "File is not .xpm extension.\n"
# define NOT_CUB "File is not .cub extension.\n"
# define RESOLUTION_PROBLEM "Problem with resolution.\n"
# define NO_XPM "There is no .xpm file.\n"
# define NO_CUB "There is no .xpm file.\n"
# define TEXTURE_PROBLEM "There is a problem with a texture.\n"
# define COLOR_PROBLEM "There is a problem with RGB color.\n"
# define CANT_MALLOC_STRUCT "Can't allocate memory for structure.\n"
# define CANT_MALLOC_SPRITE "Can't allocate memory sprite.\n"
# define CANT_FIND_SPRITE "No sprite found.\n"
# define VALID_CHAR " 012NSEW"

# include "mlx.h"
# include "../minilibft/minilibft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define tx_w 64
# define tx_h 64

typedef struct	s_int
{
	int			x;
	int			y;
}				t_int;

typedef struct	s_double
{
	double		x;
	double		y;
	double		z;
}				t_double;

typedef struct	s_path
{
	int			x;
	int			y;
	int			nb;
}				t_path;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			txid;
}				t_sprite;

typedef struct	s_raysprite
{
	t_int		_tx;
	t_int		drws;
	t_int		drwe;
	t_double	sprite;
	t_double	transform;
	double		invdet;
	int			screenx;
	int			spriteh;
	int			spritew;
	int			x;
	int			y;
}				t_raysprite;

typedef struct	s_tx
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_tx;

typedef struct	s_c3d
{
	char		**map;
	t_double	pos;
	int			orienter;
	int			winw;
	int			winh;
	char		**tex_tab;
	int			flr_color;
	int			cl_color;
	int			tex_flr;
	int			tex_cl;
	int			save;
	t_tx		tx[9];
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*imgptr;
	int			bpp;
	int			endian;
	int			sl;
	t_int		mp;
	t_int		_t;
	t_int		stp;
	t_int		_tx;
	int			color;
	int			x;
	int			hit;
	int			side;
	int			lnh;
	int			drws;
	int			drwe;
	int			txid;
	int			mvu;
	int			mvd;
	int			mvr;
	int			mvl;
	int			rtr;
	int			rtl;
	t_double	dir;
	t_double	raydir;
	t_double	sdist;
	t_double	ddist;
	t_double	flrstp;
	t_double	pln;
	t_double	flr;
	double		perpwdist;
	double		rwdist;
	double		wllx;
	double		mvs;
	double		rts;
	double		*bufz;
	int			nbsprites;
	t_sprite	**sprites;
	double		shadedist;
}				t_c3d;

typedef struct	s_bfh
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short int		reserved1;
	short int		reserved2;
	unsigned int	offset_bits;
}				t_bfh;

typedef struct	s_bih
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_bih;

int				check_conf(t_c3d **t);
int				exit_error(const char *error);
int				rgb_int(int r, int g, int b);
int				file_exist(int fd, char *type);
void			free_sprite(t_c3d *t, t_sprite **sprite);
int				find_sprites(t_c3d *t);
int				fill_sprite(t_c3d *t, t_sprite ***sprites);
int				find_player(char ***map, t_double *pos, int *orienter);
int				check_map(char ***map, t_double pos);
int				track_map_borders(char ***map, t_path ***path, t_double pos);
int				is_inside(char ***map, t_int c);
int				is_validated(char ***map, t_path ***path, t_int c,
					t_double dest, int i);
int				is_visited(t_path ***path, int x, int y, int i);
int				try_player_pos(char ***map, t_path ***path, int x, int y,
					int i);
int				get_ways(char ***map, t_path ***path, t_int c, int i);
int				move_back(char ***map, t_path ***path, t_int *c, int i);
void			move_to(char ***map, t_path ***path, t_int *c, int i);
void			free_conf(t_c3d *t);
int				fill_map(char ***map, char *line);
int				set_color(t_c3d *t, char **split);
int				fill_tex_tab(char ***tab, char *tmp, int index);
void			reorder_tex_tab(char ***tab, int *indexes, int i);
int				fill_texture(t_c3d *t, char **split);
int				set_texture(t_c3d *t, char **split);
int				set_resolution(t_c3d *t, char **split);
int				extract_data(char *line, char **split, t_c3d *t);
void			init_conf(t_c3d *t);
void			free_line_n_split(char *line, char **split);
int				parse_file(int fd, t_c3d **t, char **av);
void			start_game(t_c3d *t);
int				ft_exit(t_c3d *t);
void			load_xpm(t_c3d *t);
int				keypress(int keycode, t_c3d *t);
int				keyrelease(int keycode, t_c3d *t);
void			rotate(t_c3d *t);
void			move_vertical(t_c3d *t);
void			move_horizontal(t_c3d *t);
int				move(t_c3d *t);
void			init_orientation(t_c3d *t, char orient);
void			raycast(t_c3d *t);
int				shade_color(int color, double shadedist);
void			draw_pxl(t_c3d *t, int x, int y);
int				get_pxl_color(t_c3d *t, t_int _tx);
void			init_cast_walls(t_c3d *t);
void			cast_walls(t_c3d *t);
void			calc_side_dist(t_c3d *t);
void			perform_dda(t_c3d *t);
void			calc_draw_limits(t_c3d *t);
void			draw_wall(t_c3d *t);
void			cast_sky_flr(t_c3d *t);
void			draw_sky_flr(t_c3d *t, int y);
void			init_bufz(t_c3d *t);
void			cast_sprite(t_c3d *t);
void			init_cast_sprite(t_c3d *t, t_raysprite *s, int i);
void			calc_sprite_w_h(t_c3d *t, t_raysprite *s);
void			draw_sprite(t_c3d *t, t_raysprite *s, int i);
void			free_sprite(t_c3d *t, t_sprite **sprite);
void			create_bmp(t_c3d *t);
void			init_bmp_header(t_c3d *t, t_bfh *bfh, t_bih *bih);
void			fill_bmp_header(int fd, t_bfh *bfh, t_bih *bih);
void			draw_small_map(t_c3d *t);
void			draw_small_background(t_c3d *t, int rows, int cols, t_int c, int l);
void			draw_small_walls(t_c3d *t, int rows, int cols, t_int c, int l);
void			draw_small_position(t_c3d *t, int rows, int cols, int l);
void			draw_small_sprites(t_c3d *t, int rows, int cols, t_int c, int l);

#endif
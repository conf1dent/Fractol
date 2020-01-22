/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:56:40 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/20 13:57:18 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# define THREADS 16

# include <unistd.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h> // header in the C, contains constructs that refer to file control, e.g. opening a file, retrieving and changing the permissions of file, locking a file for edit, etc.
# include <errno.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_fractol
{
	void		*mlx_ptr; //window identifier.
	void		*win_ptr; //screen connection identifier.
	void		*image; //identifier needed to manip. the image later.
	char		*address; //address that repr. the beginning of the mem.area where the image is stored.
	int			bits_per_pixel; //1st bbp repr. the color of the 1st pixel in the 1st line of the image.
	int			size_line; //gets the beginning of the 2nd line.
	int 		endian; //tells whether the pixel color in the image needs to be stored in little endian.
	int			x; // real or re.
	int			y; // imaginary or im.
	float		step;
	//float	y_step;
	int			iter;
	int			max_iter;
	int			fractol_number;
	float		max_x; //max real
	float		min_x; //min real
	float		max_y; //max im
	float		min_y; //min im
	float		imag_px;
	float		real_px;
	float		tmp_px_y;
	float		tmp_px_x;
	float		new_tmp_px_x;
	float		julia_x;
	float		julia_y;
	int			julia_fix;
	int			i;
	int			key;
	int			start;
	int			finish;
}				t_fractol;

	void		draw(t_fractol *head);
	int			keys(int key, t_fractol *head);
	void		default_settings(t_fractol *head);
	void		choose_fractol(t_fractol *head);
	void		black_color(t_fractol *head);
	void		other_colors(t_fractol *head);
	int			mouse (int key, int x, int y, t_fractol *head);
	void		choose_fractol(t_fractol *head);
	int			julia_iter(int x, int y, t_fractol *head);
	void		mandelbrot(t_fractol *head);
	void		celtic(t_fractol *head);
	void		buffalo(t_fractol *head);
	void		burning_ship(t_fractol *head);
	void		julia(t_fractol *head);
	void		heart(t_fractol *head);
	void		chicken(t_fractol *head);
	void		hyperthreading(t_fractol *head);

#endif
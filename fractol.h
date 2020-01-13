/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:56:40 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/12 19:16:13 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH 1000
#define HEIGHT 1000

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
	//int height;
	//int width;
	void	*mlx_ptr; //window identifier.
	void	*win_ptr; //screen connection identifier.
	void	*new_image; //identifier needed to manip. the image later.
	char	*address; //address that repr. the beginning of the mem.area where the image is stored.
	int		bits_per_pixel; //1st bbp repr. the color of the 1st pixel in the 1st line of the image.
	int		size_line; //gets the beginning of the 2nd line.
	int 	endian; //tells whether the pixel color in the image needs to be stored in little endian.
	int		x; // real or re.
	int		y; // imaginary or im.
	float	step;
	//float	y_step;
	int		iter;
	int		max_iter;
	float	max_x; //max real
	float	min_x; //min real
	float	max_y; //max im
	float	min_y; //min im
	float	imag_px;
	float	real_px;
	float	tempo_imag_px;
	float	tempo_real_px;
	float	new_tempo_real_px;
	//float	t; //?
	int		i; //?


}				t_fractol;

	void	draw(t_fractol *head);
	//void	set_color(t_fractol *head);

#endif
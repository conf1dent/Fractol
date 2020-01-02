/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:56:40 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/02 14:35:10 by bbekmama         ###   ########.fr       */
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
	void *mlx_ptr;
	void *win_ptr;
	void *new_image; //?
	char *address; //?

}				t_fractol;

#endif
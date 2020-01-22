/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:19:39 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/20 15:09:37 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractol(t_fractol *head)
{
	if (head->fractol_number == 1)
		mandelbrot(head);
	else if (head->fractol_number == 2)
		celtic(head);
	else if (head->fractol_number == 3)
		buffalo(head);
	else if (head->fractol_number == 4)
		burning_ship(head);
	else if (head->fractol_number == 5)
		julia(head);
	else if (head->fractol_number == 6)
		heart(head);
	else if (head->fractol_number == 7)
		chicken(head);
}

void	draw(t_fractol *head)
{
	head->step = (head->max_x - head->min_x) / (WIDTH - 1);
	head->y = head->start;
	while (head->y < head->finish)
	{
		head->imag_px = head->max_y - head->y * head->step; //going upside down
		//head->tmp_px_y = head->imag_px;
		head->x = 0;
		while (head->x < WIDTH)
		{
			head->real_px = head->min_x + head->x * head->step; //going from left to right
			head->tmp_px_y = head->imag_px;
			head->tmp_px_x = head->real_px;
			head->iter = 0;
			while (head->iter < head->max_iter && sqrt(head->tmp_px_x *
			head->tmp_px_x + head->tmp_px_y * head->tmp_px_y) <= 2)
				choose_fractol(head);
			head->i = (head->x * 4) + (head->y * WIDTH * 4);
			if (head->iter / head->max_iter == 1)
				black_color(head);
			else
				other_colors(head);
			head->x++;
		}
		head->y++;
	}
}

void	hyperthreading(t_fractol *head)
{
	t_fractol	new_head[THREADS];
	pthread_t	thread_id[THREADS]; //int that identifies # of threads in the sys
	int			i;
	
	i = 0;
	while (i < THREADS)
	{
		new_head[i] = *head;
		new_head[i].start = i * (HEIGHT / THREADS);
		new_head[i].finish = (i + 1) * (HEIGHT / THREADS);
		pthread_create(&thread_id[i], NULL, (void *)draw, (void*)&thread_id[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(thread_id[i], NULL);
	mlx_put_image_to_window(head->mlx_ptr, head->win_ptr, head->image, 0, 0);
}


//The first argument is a pointer to thread_id which is set by this function.
//The second argument specifies attributes. If the value is NULL, then default attributes shall be used.
//The third argument is name of function to be executed for the thread to be created.
//The fourth argument is used to pass arguments to the function, myThreadFun.

//The pthread_join() function for threads is the equivalent of wait() for processes. A call to pthread_join blocks
//the calling thread until the thread with identifier equal to the first argument terminates.
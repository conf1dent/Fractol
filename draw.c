/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:19:39 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/13 14:49:40 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

// void choose_fractal(t_fractol *head)
// {
// 	if (av[1] == 1)
// 		mandelbrot(head);
// 	else if ()
// 		julia(head);
// }

// void	draw(t_fractol *head)
// {
// 	head->y = 0;
// 	head->x_step = (head->max_x - head->min_x) / WIDTH - 1;
// 	while (head->y < HEIGHT)
// 	{
// 		head->imag_px = head->max_y - head->y * head->x_step;
// 		head->x = 0;
// 		while (head->x < WIDTH)
// 		{
// 			head->real_px = head->min_x + head->x * head->x_step;
// 			head->tempo_imag_px = head->imag_px;
// 			head->tempo_real_px = head->real_px;
// 			while (((head->tempo_real_px * head->tempo_real_px) + (head->tempo_imag_px * head->tempo_imag_px) <= 4) && (head->iter < head->max_iter)) //potential brackets error
// 				choose_fractal(head);
// 			set_color(head);
// 			head->x++;
// 		}
// 		head->y++;
// 	}
// }

#include "fractol.h"

void draw(t_fractol *head)
{
	head->step = (head->max_x - head->min_x) / (WIDTH - 1);

	head->y = 0;
	while (head->y < HEIGHT)
	{
		head->imag_px = head->max_y - head->y * head->step; //going upside down
		//head->tempo_imag_px = head->imag_px;
		head->x = 0;
		while (head->x < WIDTH)
		{
			head->real_px = head->min_x + head->x * head->step; //going from left to right
			head->tempo_imag_px = head->imag_px;
			head->tempo_real_px = head->real_px;
			head->iter = 0;
			while (head->iter < head->max_iter && sqrt(head->tempo_real_px * head->tempo_real_px + head->tempo_imag_px * head->tempo_imag_px) <= 2)
			{
				head->new_tempo_real_px = (head->tempo_real_px * head->tempo_real_px - head->tempo_imag_px * head->tempo_imag_px) + head->real_px;
				head->tempo_imag_px = 2 * head->tempo_real_px * head->tempo_imag_px + head->imag_px;
				head->tempo_real_px = head->new_tempo_real_px;
				head->iter++;
			}
			head->i = (head->x * 4) + (head->y * WIDTH * 4);
			//if (head->iter < 100)
			if (head->iter / head->max_iter == 1)
			{
				head->address[head->i] = (char)0;
				head->address[++head->i] = (char)255;
				head->address[++head->i] = (char)0;
				head->address[++head->i] = (char)0;
			}
			else
			{
				head->address[head->i] = (char)0;
				head->address[++head->i] = (char)0;
				head->address[++head->i] = (char)255;
				head->address[++head->i] = (char)0;
			}
			head->x++;
		}
		head->y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:08:11 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/17 00:14:41 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(int x, int y, t_fractol *head)
{
	if (head->julia_fix == 1)
	{
		head->julia_x = ((float)x / WIDTH - 0.5) * 4;
		head->julia_y = ((float)(HEIGHT - y) / HEIGHT - 0.5) * 4;
		draw(head);
	}
	return (0);
}

int		mouse(int key, int x, int y, t_fractol *head)
{
	float	mouse_x;
	float	mouse_y;
	float	zoom;
	if (key == 4 || key == 5)
	{
		mouse_x = (float)x / (WIDTH / (head->max_x - head->min_x)) + head->min_x;
		mouse_y = (float)y / (HEIGHT / (head->max_y - head->min_y)) * -1 + head->max_y;
		if (key == 4)
			zoom = 0.90;
		else
			zoom = 1.10;
		head->min_x = (mouse_x + ((head->min_x - mouse_x) * (1.0 / zoom)));
		head->max_x = (mouse_x + ((head->max_x - mouse_x) * (1.0 / zoom)));
		head->min_y = (mouse_y + ((head->min_y - mouse_y) * (1.0 / zoom)));
		head->max_y = (mouse_y + ((head->max_y - mouse_y) * (1.0 / zoom)));
		draw(head);
	}
	return (0);
}

void	move_arrows(int key, t_fractol *head)
{
	if (key == 123)
	{
		head->min_x += 0.1;
		head->max_x += 0.1;
	}
	else if (key == 124)
	{
		head->min_x -= 0.1;
		head->max_x -= 0.1;
	}
	else if (key == 125)
	{
		head->min_y += 0.1;
		head->max_y += 0.1;
	}
	else
	{
		head->min_y -= 0.1;
		head->max_y -= 0.1;
	}
}

int		keys(int key, t_fractol *head)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		move_arrows(key, head);
	else if (key == 27)
		head->max_iter--;
	else if (key == 24)
		head->max_iter++;
	else if (key == 49)
		default_settings(head);
	else if (key == 53)
		exit(0);
	draw(head);
	return (0);
}

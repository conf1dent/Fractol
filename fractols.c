/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:14:07 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/17 13:18:31 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	mandelbrot(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = 2 * head->tmp_px_x * head->tmp_px_y + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}


void 	celtic(t_fractol *head)
{
	head->new_tmp_px_x = fabsf(head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = 2.0 * (head->tmp_px_x * head->tmp_px_y) + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	buffalo(t_fractol *head)
{
	head->new_tmp_px_x = fabsf(head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = -2.0 * head->tmp_px_x * fabs(head->tmp_px_y) + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	burning_ship(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = -2.0 * fabsf(head->tmp_px_x * head->tmp_px_y) + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	julia(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->julia_x;
	head->tmp_px_y = 2.0 * head->tmp_px_x * head->tmp_px_y + head->julia_y;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	heart(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = 2 * fabsf(head->tmp_px_x) * head->tmp_px_y + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	chicken(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x - head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = -2.0 * head->tmp_px_x * fabsf(head->tmp_px_y) + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

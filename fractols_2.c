/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:39:59 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/23 11:46:04 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x -
		head->tmp_px_y * head->tmp_px_y) + head->julia_x;
	head->tmp_px_y = 2.0 * head->tmp_px_x * head->tmp_px_y + head->julia_y;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	heart(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x -
		head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = 2 * fabsf(head->tmp_px_x) * head->tmp_px_y + head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

void	chicken(t_fractol *head)
{
	head->new_tmp_px_x = (head->tmp_px_x * head->tmp_px_x -
		head->tmp_px_y * head->tmp_px_y) + head->real_px;
	head->tmp_px_y = -2.0 * head->tmp_px_x * fabsf(head->tmp_px_y)
		+ head->imag_px;
	head->tmp_px_x = head->new_tmp_px_x;
	head->iter++;
}

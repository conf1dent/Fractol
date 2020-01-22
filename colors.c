/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:26:29 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/17 14:10:54 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	black_color(t_fractol *head)
{
	head->address[head->i] = (char)0;
	head->address[++head->i] = (char)0;
	head->address[++head->i] = (char)0;
	head->address[++head->i] = (char)0;
}

void	other_colors(t_fractol *head)
{
	float ratio;

	ratio = (float)head->iter / (float)head->max_iter;
	head->address[head->i] = (char)(5.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);
	head->address[++head->i] = (char)(8 * (1 - ratio) * ratio * ratio * ratio * 255);
	head->address[++head->i] = (char)(17.5 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);
	head->address[++head->i] = (char)0;

	// ratio = (float)head->iter / (float)head->max_iter;
	// head->address[head->i] = (char)(3 * pow((1 - ratio), 3) * ratio * 255);
	// head->address[++head->i] = (char)(8.5 * (1 - ratio) * pow(ratio, 3) * 255);
	// head->address[++head->i] = (char)(14.5 * pow((1 - ratio), 2) * pow(ratio, 2) * 255);
	// head->address[++head->i] = (char)0;
}

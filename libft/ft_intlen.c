/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:09:35 by bbekmama          #+#    #+#             */
/*   Updated: 2019/05/25 19:16:24 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long c, int len)
{
	int base;

	base = 10;
	while (c > 0)
	{
		c /= base;
		len++;
	}
	return (len);
}

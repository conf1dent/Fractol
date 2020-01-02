/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:56:05 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/02 14:38:54 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int test_errors(int ac, char *av)
{
	if (ac == 2)
	{
		if (!(ft_strstr(av, ".fractol")))
		{
			write(1, "Please use *.fractol as an argument.\n", 37);
			exit (1);
		}
		else
			return (0);
	}
	write(1, "Please type: ./fractol (1/2/3/4/5).\n", 37);
	return (1);
}

void read_file()
{
	
}

void initialize(t_fractol *head)
{
	head->mlx_ptr = mlx_init();
	head->win_ptr = mlx_new_window(head->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	head->new_image = mlx_new_image(head->mlx_ptr, WIDTH, HEIGHT); //?
	head->address = mlx_get_data_addr(head->new_image, &1, &2, &3); //?
}

int main(int ac, char **av)
{
	t_fractol *head;

	if (!(t_fractol*)malloc(sizeof(t_fractol)))
		return NULL;
	test_errors(ac, av[1]);
	read_file(head, ac);
	initialize(head);

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:56:05 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/13 14:41:10 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int test_errors(int ac, char *av)
// {
// 	if (ac == 2)
// 	{
// 		if (!(ft_strstr(av, ".fractol"))) 
// 		{
// 			write(1, "Please use *.fractol as an argument.\n", 38);
// 			exit (1);
// 		}
// 		else if (av[1] == "1" || av[1] == "2" || av[1] == "3" || av[1] == "4" || av[1] == "5")
// 			return (0);
// 		else
// 		{
// 			write(1, "Please type: ./fractol (1/2/3/4/5).\n", 37);
// 			return (1);
// 		}
// 	}
// 	write(1, "Please add the parameter, type: ./fractol (1/2/3/4/5).\n", 56);
// 	return (1);
// }

void initialize(t_fractol *head)
{
	head->mlx_ptr = mlx_init();
	head->win_ptr = mlx_new_window(head->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	head->new_image = mlx_new_image(head->mlx_ptr, WIDTH, HEIGHT); //creates a new image in memory.
	head->address = mlx_get_data_addr(head->new_image, &head->bits_per_pixel, &head->size_line, &head->endian); //returns info about the created image, allowing a user to modify it later.
	head->max_iter = 200;
	head->max_y = 2.0;
	head->min_y = -2.0;
	head->max_x = 2.0;
	head->min_x = -2.0;
}

int main()
//int main(int ac, char **av)
{
	t_fractol *head;

	head = (t_fractol*)malloc(sizeof(t_fractol));
	// if (!(t_fractol*)malloc(sizeof(t_fractol)))
	// 	return NULL;
	
	//test_errors(ac, av[1]);
	initialize(head);
	draw(head);
	mlx_put_image_to_window(head->mlx_ptr, head->win_ptr, head->new_image, 0, 0);
	//mlx_hook(head->win_ptr, 2, 0, kbrd, head); //why 2 and 0?
	//mlx_hook(head->win_ptr, 2, 0, mouse, head);
	mlx_loop(head->mlx_ptr);
	//free(head);
	return (0);
}
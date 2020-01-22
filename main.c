/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbekmama <bbekmama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 19:56:05 by bbekmama          #+#    #+#             */
/*   Updated: 2020/01/20 13:56:10 by bbekmama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		set_fractol(int ac, char **av, t_fractol *head)
{
	if (ac == 3 && ac--)
		if (fork())
			av[1] = av[2];
	if ((ft_strcmp(av[1], "1" ) == 0 || ft_strcmp(av[1], "2" ) == 0 ||
	ft_strcmp(av[1], "3" ) == 0 || ft_strcmp(av[1], "4" ) == 0 || ft_strcmp(av[1], "5") == 0||
	ft_strcmp(av[1], "6") == 0 || ft_strcmp(av[1], "7") == 0) && ac == 2)
		head->fractol_number = ft_atoi(av[1]);
	else
		write(1, "Please add the parameter, type: ./fractol 1-5\n", 47);
	return (0);
}

void	default_settings(t_fractol *head)
{
	head->max_iter = 15;
	head->max_y = 2.0;
	head->min_y = -2.0;
	head->max_x = 2.0;
	head->min_x = -2.0;
	head->julia_x = -0.4;
	head->julia_y = 0.6;
	head->julia_fix = 1;
}

void	initialize(t_fractol *head)
{
	head->mlx_ptr = mlx_init();
	head->win_ptr = mlx_new_window(head->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	head->image = mlx_new_image(head->mlx_ptr, WIDTH, HEIGHT); //creates a new image in memory.
	head->address = mlx_get_data_addr(head->image, &head->bits_per_pixel, &head->size_line, &head->endian); //returns info about the created image, allowing a user to modify it later.
	default_settings(head);
}

int		main(int ac, char **av)
{
	t_fractol *head;

	head = (t_fractol*)malloc(sizeof(t_fractol));
	set_fractol(ac, av, head);
	initialize(head);
	hyperthreading(head);
	draw(head);
	mlx_hook(head->win_ptr, 2, 0, keys, head);
	mlx_hook(head->win_ptr, 4, 0, mouse, head);
	if (ft_strcmp(av[1], "5") == 0)
		mlx_hook(head->win_ptr, 6, 0, julia_iter, head);
	mlx_loop(head->mlx_ptr);
	free(head);
	return (0);
}
















// int set_fractol(char **av, t_fractol *head)
// {
// 	// if (ft_strcmp(av[1], "1" ) == 0 || ft_strcmp(av[1], "2" ) == 0 || 
// 	// ft_strcmp(av[1], "3" ) == 0 || ft_strcmp(av[1], "4" ) == 0 || 
// 	// ft_strcmp(av[1], "5" ) == 0)
// 	if (ft_strcmp(av[1], "1" ) == 0 || ft_strcmp(av[1], "2") == 0)
// 		head->fractol_number = ft_atoi(av[1]);
// 	return (0);
// }

// int check_errors(int ac, char *av, t_fractol *head)
// {
// 	if (ac == 3 && ac++)
// 		if (fork())
// 			av[2] = av[1];
// 	if (ac == 2 && (ft_strcmp(&av[1], "1" ) == 0 || ft_strcmp(&av[1], "2") == 0))
// 	{
// 		// if (!(ft_strstr(av, ".fractol"))) 
// 		// {
// 		// 	write(1, "Please use *.fractol as an argument.\n", 38);
// 		// 	exit (1);
// 		// }
// 		// else if (ft_strcmp(&av[1], "1" ) == 0 || ft_strcmp(&av[1], "2") == 0)
// 		// {
// 			head->fractol_number = ft_atoi(&av[1]);
// 			// return (0);
// 		// }
// 	}
// 	else
// 	{
// 		write(1, "Please type: ./fractol (1/2/3/4/5).\n", 37);
// 		return (0);
// 	}
// 	// write(1, "Please add the parameter, type: ./fractol (1/2/3/4/5).\n", 56);
// 	return (0);
// }
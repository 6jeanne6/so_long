/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:48:31 by jewu              #+#    #+#             */
/*   Updated: 2024/03/29 14:04:57 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int fd = open("jeEmangeamafaim.txt", O_RDONLY);
	int errnum = ENOENT;
	if (fd == -1)
	{
		perror("\033[0;31mYour file cannot be opened");
		ft_putstr_fd("\033[0m", 2);
		// char	*erreur = strerror(errnum);
		// ft_printf("\033[0;31m%s\n", erreur);
		// ft_putstr_fd("\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	else
		printf("printf all is good");
	close(fd);
	exit(EXIT_SUCCESS);
	return (0);
}
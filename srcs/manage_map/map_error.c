/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:25:24 by jewu              #+#    #+#             */
/*   Updated: 2024/04/09 16:32:11 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_error(char *message)
{
	ft_putstr_fd("\033[0;31m", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\033[0m", 2);
	exit(EXIT_FAILURE);
}
//puts an error message in standard error and exits
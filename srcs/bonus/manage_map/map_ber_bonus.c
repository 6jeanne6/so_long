/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ber_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewu <jewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:21:21 by jewu              #+#    #+#             */
/*   Updated: 2024/05/06 16:11:18 by jewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	map_is_ber_bonus(char *argv)
{
	int	len;
	int	i;

	len = ft_strlen(argv);
	i = 0;
	if (len < 4)
		return (-1);
	while (argv[i] != '.')
		i++;
	if (ft_strncmp(argv + len, ".ber", 4) == 0
		|| ft_strncmp(argv + i, ".ber", len - i) == 0)
		return (1);
	else
		return (-1);
}
//check if argument is a ber map
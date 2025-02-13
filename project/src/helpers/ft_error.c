/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:44:09 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/08 17:32:50 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_error(void);
void	ft_perror(char *s);

void	ft_error(void)
{
	ft_perror("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_perror(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

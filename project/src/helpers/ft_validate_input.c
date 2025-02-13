/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukri <achoukri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:17:11 by achoukri          #+#    #+#             */
/*   Updated: 2025/02/08 18:03:48 by achoukri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	validate_all_args(int ac, char **av);
int		validate_arg(const char *arg);
int		arg_is_int(char *arg);
int		num_len(char *num, int *sign);
char	**validate_input(int ac, char **av, int total_tokens);

int	validate_arg(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && ft_isspace((unsigned char)arg[i]))
			i++;
		if (!arg[i])
			break ;
		if (arg[i] == '+' || arg[i] == '-')
		{
			if (!ft_isdigit(arg[i + 1]))
				return (0);
			i++;
		}
		if (!ft_isdigit(arg[i]))
			return (0);
		while (arg[i] && ft_isdigit(arg[i]))
			i++;
		if (arg[i] && !ft_isspace((unsigned char)arg[i]))
			return (0);
	}
	return (1);
}

void	validate_all_args(int ac, char **av)
{
	int	i;

	if (ac < 2)
	{
		ft_error();
	}
	i = 0;
	while (++i < ac)
	{
		if (!validate_arg(av[i]) || !arg_is_int(av[i]))
			ft_error();
	}
}

int	arg_is_int(char *arg)
{
	char	*limit;
	int		len;
	int		sign;

	len = num_len(arg, &sign);
	if (*arg == '-' || *arg == '+')
		arg++;
	while (*arg == '0')
		arg++;
	if (len < 10)
		return (1);
	else if (len > 10)
		return (0);
	else
	{
		if (sign == -1)
			limit = "2147483648";
		else
			limit = "2147483647";
		if (ft_strncmp(arg, limit, 10) <= 0)
			return (1);
		else
			return (0);
	}
}

int	num_len(char *num, int *sign)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	*sign = 1;
	if (num[i] == '-' || num[i] == '+')
	{
		if (num[i] == '-')
			*sign = -1;
		i++;
	}
	while (num[i] == '0')
		i++;
	while (num[i] && num[i] >= '0' && num[i] <= '9')
	{
		len++;
		i++;
	}
	return (len);
}

char	**validate_input(int ac, char **av, int total_tokens)
{
	char	**args;
	char	**valid_args;
	int		i;
	int		j;
	int		k;

	validate_all_args(ac, av);
	valid_args = malloc(sizeof(char *) * (total_tokens + 1));
	if (!valid_args)
		ft_error();
	i = 0;
	k = 0;
	while (++i < ac)
	{
		args = ft_split(av[i], ' ');
		if (args == NULL)
			ft_error();
		j = -1;
		while (args[++j])
			valid_args[k++] = ft_strdup(args[j]);
		ft_free_split(args);
	}
	valid_args[k] = NULL;
	return (valid_args);
}

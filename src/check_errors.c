/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:20:50 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 12:33:48 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_put_str(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
}

int	is_file2(char *s)
{
	int	x;

	x = 0;
	while (s[x++])
	{
		if (s[x] == '.' && s[x + 1])
			return (1);
	}
	return (0);
}

void	verify_data(int output)
{
	if (output < 0)
	{
		perror("file2 ");
		exit(0);
	}
}

void	ft_check_files(char **argv, int ac, t_data *data)
{
	if (access(argv[1], R_OK) == -1)
	{
		perror("file1 ");
		exit(0);
	}
	if (access(argv[ac - 1], F_OK) == -1)
	{
		if (is_file2(argv[ac - 1]))
		{
			data->output = open(argv[ac - 1], O_CREAT, 0700);
			verify_data(data->output);
		}
	}
	if (access(argv[ac - 1], W_OK) == -1 || access(argv[ac - 1], R_OK) == -1)
	{
		ft_put_str("Error\n");
		close(data->output);
		exit(0);
	}
	else
		data->output = open(argv[ac - 1], O_WRONLY | O_TRUNC);
}

void	ft_check_args(int argc, char **argv, char **env, t_data *data)
{
	data->output = 0;
	if (argc < 5)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_check_files(argv, argc, data);
	env = env;
}

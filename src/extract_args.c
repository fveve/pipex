/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 10:10:36 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:30:11 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_set_path(char *cmd, char *p)
{
	char	*path;
	int		x;
	int		y;

	path = malloc(sizeof(char) * (ft_strlen(p) + ft_strlen(cmd) + 2));
	x = 0;
	y = 0;
	while (p[x])
		path[y++] = p[x++];
	path[y++] = '/';
	x = 0;
	while (cmd[x])
		path[y++] = cmd[x++];
	path[y] = '\0';
	return (path);
}

char	*find_path(t_cmd *cmd, int y, char **env)
{
	char	**tab;
	char	*path;
	int		x;

	x = 0;
	while (env[x])
	{
		if (is_path(env[x]))
		{
			tab = ft_split(env[x], ':');
			break ;
		}
		x++;
	}
	x = 0;
	path = ft_set_path(cmd[y].args[0], tab[x]);
	while (access(path, F_OK && X_OK) == -1 && tab[x])
	{
		free(path);
		path = ft_set_path(cmd[y].args[0], tab[x]);
		x++;
	}
	free_tab(tab);
	verify_path(path, cmd);
	return (path);
}

int	is_file(char *s)
{
	if (!s)
		return (0);
	if (access(s, F_OK) == 0)
		return (1);
	return (0);
}

t_cmd	*set_args(char **argv, t_cmd *cmd, int *y)
{
	int		x;

	x = 1;
	while ((*y) <= 1 && argv[x])
	{
		if (is_file(argv[x]))
			cmd[(*y)++].args = ft_split(argv[x], ' ');
		x++;
	}
	return (cmd);
}

t_cmd	*extract_tab(char **argv, char **env)
{
	t_cmd	*cmd;
	int		x;
	int		y;

	x = 1;
	y = 0;
	cmd = init_cmd(ft_strlen_tab(argv));
	cmd = set_args(argv, cmd, &y);
	x = 2;
	while (argv[x])
	{
		if (!is_file(argv[x]))
		{
			cmd[y].args = ft_split(argv[x], ' ');
			cmd[y].path = find_path(cmd, y, env);
			x++;
			y++;
		}
		else
			x++;
	}
	return (cmd);
}

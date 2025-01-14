/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:31:14 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 15:31:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_cmd(t_cmd *cmd, int x, char **envp)
{
	if (execve(cmd[x].path, cmd[x].args, envp) == -1)
	{
		perror("execve ");
		free_cmd(cmd);
		exit (0);
	}
}

void	set_parent(int *fd, int output, pid_t pid)
{
	if (pid)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		dup2(output, 1);
	}
}

void	exec_child(t_cmd *cmd, int x, int output, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe ");
		free_cmd(cmd);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork ");
		free_cmd(cmd);
		exit(1);
	}
	if (!pid)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		exec_cmd(cmd, x, envp);
	}
	set_parent(fd, output, pid);
}

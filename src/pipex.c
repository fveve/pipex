/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:39:15 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:30:20 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd;
	t_data	data;
	int		x;

	ft_check_args(argc, argv, envp, &data);
	cmd = extract_tab(argv, envp);
	x = 2;
	data.input = open(cmd[0].args[0], R_OK);
	dup2(data.input, 0);
	while (x < argc - 2)
	{
		exec_child(cmd, x, data.output, envp);
		x++;
	}
	if (execve(cmd[x].path, cmd[x].args, envp) == -1)
	{
		perror("execve ");
		free_cmd(cmd);
		exit (0);
	}
}

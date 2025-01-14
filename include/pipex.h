/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafa <arafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:10:20 by arafa             #+#    #+#             */
/*   Updated: 2023/12/22 11:44:15 by arafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>

//Structure-------------------------------------------------
typedef struct s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_data
{
	int	input;
	int	output;
}	t_data;

//Functions-------------------------------------------------
int		ft_strlen(const char *s);
int		ft_strlen_tab(char **s);
int		is_tiret(char *s);
int		is_file(char *s);
int		is_path(char *s);
char	*ft_substr(char const *s, int start, int len);
char	**extract_args(char **argv, int x);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
void	ft_check_args(int argc, char **argv, char **env, t_data *data);
void	exec_child(t_cmd *cmd, int x, int output, char **envp);
void	verify_path(char *path, t_cmd *cmd);
void	free_tab(char **tab);
void	free_cmd(t_cmd *cmd);
t_cmd	*extract_tab(char **argv, char **env);
t_cmd	*init_cmd(int len);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Untitled-1                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:55:46 by marvin            #+#    #+#             */
/*   Updated: 2024/01/17 15:55:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	is_path(char *s)
{
	char	*path;
	int		x;

	x = 0;
	path = "PATH";
	while (s[x - 1] != 'H' && path[x])
	{
		if (path[x] != s[x])
			return (0);
		x++;
	}
	return (1);
}

void	verify_path(char *path, t_cmd *cmd)
{
	if (access(path, F_OK && X_OK) == -1)
	{
		perror("Error");
		free(path);
		free_cmd(cmd);
		exit(0);
	}
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*tab;
	int		x;
	int		y;

	if (ft_strlen(s) <= start || s == NULL)
	{
		tab = malloc(sizeof(char));
		tab[0] = '\0';
		return (tab);
	}
	else if (len >= ft_strlen(s))
		tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	x = start;
	y = 0;
	while (s[x] && y < len)
		tab[y++] = s[x++];
	tab[y] = '\0';
	return (tab);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

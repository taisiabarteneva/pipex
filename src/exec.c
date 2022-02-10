/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:16:11 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:21:49 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

void	ft_check_execute_no_system_bin(char *cmd, char **path, char ***cmdargs)
{
	*cmdargs = ft_split(cmd, ' ');
	if (!*cmdargs)
		ft_fatal_error("split");
	*path = *cmdargs[0];
}

void	ft_check_execute_system_bin(char *cmd, char ***cmdargs,
		char **ev, char **path)
{
	char	**paths;

	paths = ft_parse_paths(ev);
	*cmdargs = ft_split(cmd, ' ');
	if (!*cmdargs)
		ft_fatal_error("split");
	while (paths && *paths)
	{
		*path = ft_strjoin(*paths, (*cmdargs)[0]);
		if (!*path)
			ft_fatal_error("malloc");
		if (access(*path, F_OK) == 0)
			break ;
		free(*path);
		*path = NULL;
		paths++;
	}
	if (!*path)
	{
		*path = ft_strjoin("/", (*cmdargs)[0]);
		if (!*path)
			ft_fatal_error("malloc");
	}
}

void	ft_check_execute(char *cmd, char **ev)
{
	char	*path;
	char	**cmdargs;

	path = NULL;
	if (ft_strchr(cmd, '/') != NULL)
		ft_check_execute_no_system_bin(cmd, &path, &cmdargs);
	else
		ft_check_execute_system_bin(cmd, &cmdargs, ev, &path);
	execve(path, cmdargs, ev);
	perror(cmdargs[0]);
	exit(EXIT_FAILURE);
}

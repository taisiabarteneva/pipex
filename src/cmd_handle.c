/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:20:04 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:21:39 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

void	ft_handle_first(char *cmd, t_info *parent)
{
	int	fd_in;

	if (parent->here_doc == 1)
		ft_handle_heredoc(parent, cmd);
	fd_in = open(parent->av[1], O_RDWR, 0777);
	if (fd_in == -1)
		ft_fatal_error("open");
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_fatal_error("dup2");
	if (dup2(parent->pipes[0][1], STDOUT_FILENO) == -1)
		ft_fatal_error("dup2");
	close(fd_in);
}

void	ft_handle_last(t_info *parent,
		t_index *store, int cmd_counter)
{
	int	fd_out;

	if (parent->here_doc == 1)
		fd_out = open(parent->av[store->argc - 1],
				O_RDWR | O_APPEND | O_CREAT, 0777);
	else
		fd_out = open(parent->av[store->argc - 1],
				O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd_out == -1)
		ft_fatal_error("open");
	if (dup2(parent->pipes[cmd_counter - 1][0], STDIN_FILENO) == -1)
		ft_fatal_error("dup2");
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_fatal_error("dup2");
	close(fd_out);
}

void	ft_handle_standard(t_info *parent, int cmd_counter)
{
	dup2(parent->pipes[cmd_counter - 1][0], STDIN_FILENO);
	dup2(parent->pipes[cmd_counter][1], STDOUT_FILENO);
}

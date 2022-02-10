/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:23:48 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:21:52 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

void	ft_handle_heredoc(t_info *parent, char *del)
{
	char	*line;

	if (dup2(parent->pipes[0][1], STDOUT_FILENO) == -1)
		ft_fatal_error("dup2");
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strnstr(line, del, ft_strlen(del)) != NULL
			&& ft_strlen(line) == ft_strlen(del) + 1)
			break ;
		write(STDOUT_FILENO, line, ft_strlen(line));
		free(line);
	}
	ft_close_all_pipes(parent->pipes);
	exit(EXIT_SUCCESS);
}

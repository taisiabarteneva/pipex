/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:34:44 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:22:07 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

void	ft_open_pipes(int **pipes, int pipes_count)
{
	int	i;
	int	res;

	i = 0;
	while (i < pipes_count)
	{
		res = pipe(pipes[i]);
		if (res == -1)
			ft_fatal_error("Unable to create a pipe");
		i++;
	}
}

int	**ft_create_pipes(int pipes_count)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = (int **)malloc(sizeof(int *) * (pipes_count + 1));
	if (!pipes)
		ft_fatal_error("Unable to allocate memory");
	while (i < pipes_count)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (!pipes[i])
			ft_fatal_error("Unable to allocate memory");
		i++;
	}
	pipes[i] = NULL;
	ft_open_pipes(pipes, pipes_count);
	return (pipes);
}

void	ft_close_all_pipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

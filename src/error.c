/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:14:58 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:21:45 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

void	ft_fatal_error(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_check_child_status(int status)
{
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		exit(WTERMSIG(status));
	else if (WIFSTOPPED(status))
		exit(WSTOPSIG(status));
	else
		exit(EXIT_FAILURE);
}

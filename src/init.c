/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:26:48 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:21:56 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

t_index	ft_init_index_struct(int ac)
{
	t_index	store;

	store.cmd_count = ac - 3;
	store.i_current_cmd = 2;
	store.pipes_count = ac - 4;
	store.argc = ac;
	return (store);
}

void	ft_init_parent_struct(t_info *parent,
		int pipes_count, char **av, char **ev)
{
	parent->pid = 0;
	parent->pipes = ft_create_pipes(pipes_count);
	parent->av = av;
	parent->ev = ev;
}

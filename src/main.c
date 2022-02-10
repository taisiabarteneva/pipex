/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:28:04 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:25:52 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

void	ft_parse_command(t_index *store, t_info *parent,
		char *cmd, int cmd_counter)
{
	if (cmd_counter == 0)
		ft_handle_first(parent->av[store->i_current_cmd], parent);
	else if (cmd_counter == store->cmd_count - 1)
		ft_handle_last(parent, store, cmd_counter);
	else
		ft_handle_standard(parent, cmd_counter);
	ft_close_all_pipes(parent->pipes);
	ft_check_execute(cmd, parent->ev);
}

void	ft_wait_child_processes(int process_count)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	while (i < process_count)
	{
		wait(&status);
		if (status != 0)
			ft_check_child_status(status);
		i++;
	}
}

void	ft_main_process(t_index *store, t_info *parent)
{
	int	cmd_counter;

	cmd_counter = 0;
	while (cmd_counter < store->cmd_count)
	{
		parent->pid = fork();
		if (parent->pid == -1)
			ft_fatal_error("fork");
		if (parent->pid == 0)
			ft_parse_command(store, parent,
				parent->av[store->i_current_cmd], cmd_counter);
		store->i_current_cmd++;
		cmd_counter++;
	}
	ft_close_all_pipes(parent->pipes);
	ft_wait_child_processes(store->cmd_count);
}

// $> ./pipex infile cmd cmd1 cmdn outfile 
// $> ./pipex here_doc LIMITER cmd cmd1 file
// cmd << LIMITER | cmd1 >> file
int	main(int ac, char **av, char **ev)
{
	t_index	store;
	t_info	parent;

	if (ac < 5)
	{
		write(2, "You entered an invalid number of args.\n", 40);
		return (1);
	}
	if (ft_strnstr(av[1], "here_doc", 8) != NULL && ft_strlen(av[1]) == 8)
		parent.here_doc = 1;
	else
		parent.here_doc = 0;
	store = ft_init_index_struct(ac);
	ft_init_parent_struct(&parent, store.pipes_count, av, ev);
	ft_main_process(&store, &parent);
	return (0);
}

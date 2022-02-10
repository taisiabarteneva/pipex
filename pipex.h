/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:37:46 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:19:20 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/syscall.h> 
# include <sys/wait.h>
# include <sys/stat.h>

# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_info
{
	pid_t	pid;
	int		**pipes;
	char	**av;
	char	**ev;
	int		here_doc;
}				t_info;

typedef struct s_index
{
	int	cmd_count;
	int	i_current_cmd;
	int	pipes_count;
	int	argc;
}				t_index;

// ERROR
void	ft_fatal_error(char *message);
void	ft_check_child_status(int status);

// INIT
t_index	ft_init_index_struct(int ac);
void	ft_init_parent_struct(t_info *parent,
			int pipes_count, char **av, char **ev);
// PIPES
int		**ft_create_pipes(int pipes_count);
void	ft_open_pipes(int **pipes, int pipes_count);
void	ft_close_all_pipes(int **pipes);

// PARSE
char	**ft_parse_paths(char **ev);
void	ft_parse_command(t_index *store, t_info *parent,
			char *cmd, int cmd_counter);
// CMD
void	ft_check_execute(char *cmd, char **ev);
void	ft_handle_first(char *cmd, t_info *parent);
void	ft_handle_standard(t_info *parent, int cmd_counter);
void	ft_handle_last(t_info *parent,
			t_index *store, int cmd_counter);
			
// MAIN
void	ft_main_process(t_index *store, t_info *parent);

// BONUS
void	ft_handle_heredoc(t_info *parent, char *del);

//  UTILS
char	*ft_strstr(char **str, char *substr);

#endif

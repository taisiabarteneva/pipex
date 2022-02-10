/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wurrigon <wurrigon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 23:32:34 by wurrigon          #+#    #+#             */
/*   Updated: 2022/02/10 14:22:04 by wurrigon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../pipex.h"

char	*ft_strstr(char **str, char *substr)
{
	char	*path;

	while (*str)
	{
		if (ft_strncmp(*str, substr, ft_strlen(substr)) == 0)
		{
			path = ft_substr(*str, 5, ft_strlen(*str) - 5);
			return (path);
		}
		str++;
	}
	return (NULL);
}

char	**ft_parse_paths(char **ev)
{
	int		i;
	char	*PATH_ev;
	char	**mypaths;

	i = 0;
	PATH_ev = ft_strstr(ev, "PATH");
	if (!PATH_ev)
		return (NULL);
	mypaths = ft_split(PATH_ev, ':');
	if (!mypaths)
		ft_fatal_error("split");
	while (mypaths[i])
	{
		mypaths[i] = ft_strjoin(mypaths[i], "/");
		if (!mypaths[i])
			ft_fatal_error("malloc");
		i++;
	}
	return (mypaths);
}

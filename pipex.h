/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:14:00 by cprester          #+#    #+#             */
/*   Updated: 2022/05/04 19:50:44 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex_arg
{
	char	**envp;
	char	**av;
	int		ac;
}	t_pipex_arg;

typedef struct s_info
{
	int	start;
	int	end;
	int	temp;
	int	quote;
}	t_info;

#endif
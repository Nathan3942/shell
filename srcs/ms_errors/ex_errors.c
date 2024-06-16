/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 23:33:35 by ichpakov          #+#    #+#             */
/*   Updated: 2024/06/14 16:05:21 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_errors(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

int	exec_error(int num)
{
	if (num == 0)
		return (0 * ft_errors("error 1 : fatal error\n"));
	if (num == 2)
		return (0 * ft_errors("error 2 : ca a pas execute my J\n"));
	if (num == 3)
		return (0 * ft_errors("error 3 : seul echo peut avoir un flag dans l'enoncer\n"));
	if (num == 4)
		return (0 * ft_errors("error 4 : too many arguments\n"));
	else
		return (0 * ft_errors("error 0 : fatal error\n"));
}

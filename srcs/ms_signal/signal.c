/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njeanbou <njeanbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:38:48 by njeanbou          #+#    #+#             */
/*   Updated: 2024/07/02 17:57:57 by njeanbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void exec_signal(int signal)
{
	if (!kill(ft_getpid(), signal))
	{
		if (signal == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
		}
		else if (signal == SIGINT)
		{
			ft_putstr_fd("\n", 1);
		}
	}
	else if (signal == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		// et il me faut le prompt
	}
}

// void	handler_signal(int signal, siginfo_t *info, void *context)
// {
// 	(void)context;
// 	if (signal == SIGINT && ft_getpid() == info->si_pid)
// 	{
// 		// if (info->si_pid == ft_getpid())
// 		// 	ft_putstr_fd("\nminishel$\b", 1);
// 		// else
// 		// 	ft_putstr_fd("\n", 1);
// 		ft_putstr_fd("\nminishel$\b", 1);
// 	}
// 	else
// 		ft_putstr_fd("\n", 1);
// }

// void	sigquit_handler(int signal)
// {
// 	ft_putstr_fd("Quit: ", 1);
// 	ft_putnbr_fd(signal, 1);
// 	ft_putchar_fd('\n', 1);
// 	exit(EXIT_SUCCESS);
// }

void	handler_signal(int signal)
{
	if (signal == SIGINT)
	{
		//rl_replace_line("lala", 0);
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}

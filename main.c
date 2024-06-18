/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboxuser <vboxuser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:52:31 by njeanbou          #+#    #+#             */
/*   Updated: 2024/06/18 02:45:48 by vboxuser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static char	*get_input(void)
{
	char	*raw_input;
	char	*input;

	raw_input = readline("minishell$ ");
	input = clean_input(raw_input);
	free(raw_input);
	return (input);
}

void	init_data(t_params **para, t_put **put, t_data **data)
{
	*para = (t_params *)malloc (sizeof(t_params));
	*put = (t_put *) malloc (sizeof(t_put));
	*data = NULL;
	*data = malloc(sizeof(t_data));
	(*put)->input = NULL;
	(*put)->output = NULL;
}

void	loop_shell(t_params *para, t_env *lstenv, t_put *put, t_data *data)
{
	int		error;
	char	*input;

	while (1)
	{
		input = get_input();
		if (input != NULL)
		{
			init_data(&para, &put, &data);
			if (ft_strstr(input, "<<") == NULL)
				add_history(input);
			error = set_para(&para, input, &lstenv, &put);
			if (error == 0 && para->com[0] != NULL)
			{
				//print_all(&para, &lstenv, &put);
				add_var_status(&lstenv, ms_exec_loop(data, &para, put, &lstenv));
			}
			if (error != 0)
			{
				print_error(error);
				free_error(&para, &put, &data);
				if (error != 1 && error != 4 && error != 0)
					free(input);
			}
			else
				free_all(&para, &put, &data);
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	t_params	*para;
	t_env		*lstenv;
	t_put		*put;
	t_data		*data;

	para = NULL;
	put = NULL;
	data = NULL;
	if (argc > 1 && argv[1] == NULL)
		exit(EXIT_FAILURE);
	lstenv = set_env(env);
	loop_shell(para, lstenv, put, data);
	return (0);
}

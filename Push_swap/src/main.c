/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:25:21 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/05 10:25:23 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	algo_option(int argc, char **argv, t_env *env)
{
	if (argc <= env->index)
		return ;
	if (argv[env->index][0] == '-' && argv[env->index][1] == 'a')
	{
		if (ft_strequ("-a0", argv[env->index]) && ++(env->index))
			env->choice = 0;
		else if (ft_strequ("-a1", argv[env->index]) && ++(env->index))
			env->choice = 1;
		else if (ft_strequ("-a2", argv[env->index]) && ++(env->index))
			env->choice = 2;
		else if (ft_strequ("-a3", argv[env->index]) && ++(env->index))
			env->choice = 3;
		else if (ft_strequ("-a4", argv[env->index]) && ++(env->index))
			env->choice = 4;
	}
}

static void	get_options(int argc, char **argv, t_env *env)
{
	while (argc > env->index)
	{
		if (ft_strequ("-p", argv[env->index]) && (env->index)++)
			env->options += !(env->options & 1) ? 1 : 0;
		else if (ft_strequ("-t", argv[env->index]) && ++(env->index))
			env->options += !(env->options & 2) ? 2 : 0;
		else if (ft_strequ("-d", argv[env->index]) && ++(env->index))
			env->options += !(env->options & 8) ? 8 : 0;
		else if (ft_strequ("-rp", argv[env->index]) && ++(env->index))
			env->options += !(env->options & 16) ? 16 : 0;
		else
			break ;
	}
	if (env->options & 1 && env->options & 16)
		env->options -= 16;
}

int			main(int argc, char **argv)
{
	t_env	env;

	env.a_start = NULL;
	env.b_start = NULL;
	env.a_end = NULL;
	env.b_end = NULL;
	env.index = 1;
	env.asize = 0;
	env.bsize = 0;
	env.tot = 0;
	env.options = 0;
	env.choice = 4;
	get_options(argc, argv, &env);
	algo_option(argc, argv, &env);
	if (get_pile(argc, argv, &env) >= 0)
		begin_sort(&env);
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}

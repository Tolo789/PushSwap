/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:30:03 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/24 11:30:06 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_ordered(t_env *env)
{
	t_elem	*tmp;

	tmp = env->a_start;
	while (tmp && tmp->next && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp && tmp->next)
		return (0);
	return (1);
}

void	chose_algo(t_env *env)
{
	void	(*choices[5])(t_env*);

	choices[0] = only_a_sort;
	choices[1] = sort_from_front;
	choices[2] = sort_from_back;
	choices[3] = push_little;
	choices[4] = quicksort;
	if (env->a_start)
		choices[env->choice](env);
}

void	begin_sort(t_env *env)
{
	if (env->options & 1 || env->options & 16)
	{
		ft_putstr_fd("		START\n", 1);
		print_option(env);
		ft_putchar('\n');
	}
	if (env->a_start)
		first_optimization(env);
	if (env->a_start)
		chose_algo(env);
	ft_putchar('\n');
	if (env->options & 1 || env->options & 16)
	{
		ft_putstr_fd("\n		END\n", 1);
		print_option(env);
		(env->options & 2) ? ft_putchar('\n') : 0;
	}
	free_pile(&(env->a_start), &(env->a_end));
	free_pile(&(env->b_start), &(env->b_end));
	if (env->options & 2)
	{
		ft_putstr_fd("Total moves: ", 1);
		ft_putnbr(env->tot);
		ft_putchar('\n');
	}
}

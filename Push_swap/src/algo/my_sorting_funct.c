/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sorting_funct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:27:14 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/24 11:27:17 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	only_a_sort(t_env *env)
{
	t_elem	*tmp;
	int		i;
	int		step;

	while (1)
	{
		step = 0;
		i = 0;
		tmp = env->a_start;
		while (tmp->next && tmp->value < tmp->next->value && ++step)
			tmp = tmp->next;
		if (tmp->next)
		{
			while (i++ < step)
				move_ra(env);
			move_sa(env);
			while (step--)
				move_revra(env);
		}
		else
			break ;
	}
}

void	sort_from_front(t_env *e)
{
	while (!is_ordered(e))
	{
		while (e->a_start->next && e->a_start->value < e->a_start->next->value)
			move_pb(e);
		move_sa(e);
		if (e->b_start && e->b_start->value > e->a_start->value)
		{
			move_ra(e);
			while (e->b_start && e->b_start->value > e->a_end->value)
				move_pa(e);
			move_revra(e);
		}
	}
	while (e->b_start)
		move_pa(e);
}

void	sort_from_back2(t_env *env)
{
	if (env->a_start->value > env->a_start->next->value)
		move_sa(env);
	if (env->b_start && env->b_start->value > env->a_start->value)
	{
		move_ra(env);
		while (env->b_start && env->b_start->value > env->a_end->value)
			move_pa(env);
		move_revra(env);
	}
}

void	sort_from_back(t_env *env)
{
	while (!is_ordered(env))
	{
		while (env->a_start->value < env->a_end->value)
		{
			sort_from_back2(env);
			move_pb(env);
		}
		while (env->a_end->value < env->a_start->value)
		{
			while (env->b_start && env->b_start->value > env->a_end->value)
				move_pa(env);
			move_revra(env);
			while (env->a_start->value < env->a_end->value)
			{
				sort_from_back2(env);
				move_pb(env);
			}
		}
	}
	while (env->b_start)
		move_pa(env);
}

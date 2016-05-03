/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_optimization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:35:11 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/24 11:35:13 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	optimize_rotate(t_env *env)
{
	int		i;
	int		value;
	t_elem	*tmp;

	i = 0;
	value = env->a_start->value;
	tmp = env->b_start->next;
	if (value > env->b_start->value && value < env->b_end->value)
		return ;
	while (tmp && (tmp->value > value || tmp->prev->value < value))
	{
		i++;
		tmp = tmp->next;
	}
	if (i < env->bsize / 2)
		while (env->b_start->value > value || env->b_end->value < value)
			move_rb(env);
	else
		while (env->b_start->value > value || env->b_end->value < value)
			move_revrb(env);
}

static void	optimize_order(t_env *env)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = env->b_start;
	if (tmp)
	{
		while (tmp->next && tmp->value > tmp->next->value && ++i)
			tmp = tmp->next;
		if (!tmp)
			return ;
		if (i > env->bsize / 2)
			while (env->b_end->value > env->b_start->value)
				move_revrb(env);
		else
			while (env->b_end->value > env->b_start->value)
				move_rb(env);
	}
}

static void	pushing_to_b(t_env *env)
{
	int		value;
	int		done;
	t_elem	*tmp;

	done = 0;
	if (env->a_start && env->a_start->next)
		if (env->a_start->value > env->a_start->next->value)
			move_sa(env);
	tmp = env->b_start;
	value = env->a_start->value;
	while (tmp && value < tmp->value)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	tmp = env->b_start;
	while (tmp && value > tmp->value)
		tmp = tmp->next;
	if (!tmp && !done && ++done)
		optimize_order(env);
	if (!done && ++done)
		optimize_rotate(env);
	move_pb(env);
}

static void	second_part(t_env *env)
{
	if (env->a_start->next && env->a_start->value > env->a_start->next->value)
		move_sa(env);
	if (env->a_end->prev && env->a_end->value < env->a_end->prev->value)
	{
		move_revra(env);
		while (env->a_end->prev && env->a_end->value < env->a_end->prev->value)
		{
			move_pb(env);
			move_rb(env);
			move_revra(env);
		}
		move_revra(env);
		move_sa(env);
		while (env->b_start)
		{
			move_pa(env);
			move_ra(env);
		}
		move_ra(env);
		move_ra(env);
	}
}

void		first_optimization(t_env *env)
{
	while (env->a_end->value < env->a_start->value)
	{
		if (ASTA > ANEX && AEND != ANEX)
			move_sa(env);
		move_revra(env);
		if (ASTA > ANEX && AEND != ANEX)
			move_sa(env);
		while (env->a_start->next && AEND > ASTA && AEND < ANEX)
		{
			pushing_to_b(env);
			move_revra(env);
			if (ASTA > ANEX && AEND != ANEX)
				move_sa(env);
		}
	}
	while (env->b_start)
	{
		move_pa(env);
		if (ASTA > ANEX && AEND != ANEX)
			move_sa(env);
	}
	second_part(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:50:48 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/21 15:50:49 by cmutti           ###   ########.fr       */
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

static int	choose_pivot(t_env *env)
{
	int		i;
	int		split;
	t_elem	*tmp;
	t_elem	*tmp2;

	split = (env->asize <= 400) ? 2 : 7;
	tmp = env->a_start;
	while (tmp->next)
	{
		i = 0;
		tmp2 = env->a_start;
		while (tmp2)
		{
			if (tmp2->value < tmp->value)
				i++;
			if (i > (env->asize + 1) / split)
				break ;
			tmp2 = tmp2->next;
		}
		if (i == (env->asize + 1) / split)
			break ;
		tmp = tmp->next;
	}
	return (tmp->value);
}

void		quicksort(t_env *env)
{
	t_elem	*tmp;

	while (!is_ordered(env))
	{
		env->pivot = choose_pivot(env);
		while (env->a_start->value < env->pivot)
			pushing_to_b(env);
		while (1)
		{
			tmp = env->a_start;
			while (tmp && tmp->value >= env->pivot)
				tmp = tmp->next;
			if (!tmp)
				break ;
			while (env->a_start->value < env->pivot)
				pushing_to_b(env);
			if (env->a_start->next && ASTA > ANEX &&
				ANEX > env->pivot)
				move_sa(env);
			(!is_ordered(env)) ? move_ra(env) : 0;
		}
	}
	optimize_order(env);
	while (env->b_start)
		move_pa(env);
}

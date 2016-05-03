/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:12:45 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/16 16:12:47 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	tffront(t_env *env, int pos)
{
	t_elem	*tmp;

	tmp = env->a_start;
	while (pos--)
		move_ra(env);
	move_pb(env);
}

void	tfback(t_env *env, int pos)
{
	t_elem	*tmp;

	pos = env->asize - pos - 1;
	tmp = env->a_start;
	while (pos--)
		move_revra(env);
	move_pb(env);
}

void	push_little(t_env *env)
{
	int		little;
	int		i;
	int		pos;
	t_elem	*tmp;

	while (!is_ordered(env) && env->a_start && env->a_start->next)
	{
		i = 0;
		pos = 0;
		tmp = env->a_start;
		little = tmp->value;
		while (tmp->next)
		{
			tmp = tmp->next;
			++i;
			if (tmp->value < little && (pos = i))
				little = tmp->value;
		}
		(pos <= env->asize / 2) ? tffront(env, pos) : tfback(env, pos);
	}
	while (env->b_start)
		move_pa(env);
}

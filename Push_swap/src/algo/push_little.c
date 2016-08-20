/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <cmutti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:12:45 by cmutti            #+#    #+#             */
/*   Updated: 2016/08/20 05:16:05 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	tffront(t_env *env, int pos)
{
	while (pos--)
		move_ra(env);
	move_pb(env);
}

void	tfback(t_env *env, int pos)
{
	pos = env->asize - pos;
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

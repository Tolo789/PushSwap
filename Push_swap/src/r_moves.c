/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:36:07 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/05 10:36:08 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_ra(t_env *env)
{
	t_elem	*new_end;

	if (env->a_start && (env->a_start)->next)
	{
		new_end = env->a_start;
		env->a_start = env->a_start->next;
		env->a_start->prev = NULL;
		new_end->prev = env->a_end;
		new_end->next = NULL;
		env->a_end->next = new_end;
		env->a_end = new_end;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" ra", 1) : ft_putstr_fd("ra", 1);
		if (env->options & 8)
			print_pause(env);
	}
}

void	move_rb(t_env *env)
{
	t_elem	*new_end;

	if (env->b_start && (env->b_start)->next)
	{
		new_end = env->b_start;
		env->b_start = env->b_start->next;
		env->b_start->prev = NULL;
		new_end->prev = env->b_end;
		new_end->next = NULL;
		env->b_end->next = new_end;
		env->b_end = new_end;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" rb", 1) : ft_putstr_fd("rb", 1);
		if (env->options & 8)
			print_pause(env);
	}
}

void	move_rr(t_env *env)
{
	t_elem	*new_end;

	if (env->a_start && env->a_start->next)
	{
		new_end = env->a_start;
		env->a_start = env->a_start->next;
		env->a_start->prev = NULL;
		new_end->prev = env->a_end;
		new_end->next = NULL;
		env->a_end->next = new_end;
		env->a_end = new_end;
	}
	if (env->b_start && env->b_start->next)
	{
		new_end = env->b_start;
		env->b_start = env->b_start->next;
		env->b_start->prev = NULL;
		new_end->prev = env->b_end;
		new_end->next = NULL;
		env->b_end->next = new_end;
		env->b_end = new_end;
	}
	++(env->tot);
	((env->tot) != 1) ? ft_putstr_fd(" rr", 1) : ft_putstr_fd("rr", 1);
	(env->options & 8) ? print_pause(env) : 0;
}

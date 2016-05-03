/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 12:17:53 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/29 12:17:56 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_revra(t_env *env)
{
	t_elem	*new_start;

	if (env->a_start && env->a_start->next)
	{
		new_start = env->a_end;
		env->a_end = env->a_end->prev;
		env->a_end->next = NULL;
		new_start->next = env->a_start;
		new_start->prev = NULL;
		env->a_start->prev = new_start;
		env->a_start = new_start;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" rra", 1) : ft_putstr_fd("rra", 1);
		if (env->options & 8)
			print_pause(env);
	}
}

void	move_revrb(t_env *env)
{
	t_elem	*new_start;

	if (env->b_start && env->b_start->next)
	{
		new_start = env->b_end;
		env->b_end = env->b_end->prev;
		env->b_end->next = NULL;
		new_start->next = env->b_start;
		new_start->prev = NULL;
		env->b_start->prev = new_start;
		env->b_start = new_start;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" rrb", 1) : ft_putstr_fd("rrb", 1);
		if (env->options & 8)
			print_pause(env);
	}
}

void	move_revrr(t_env *env)
{
	t_elem	*new_start;

	if (env->a_start && env->a_start->next)
	{
		new_start = env->a_end;
		env->a_end = env->a_end->prev;
		env->a_end->next = NULL;
		new_start->next = env->a_start;
		new_start->prev = NULL;
		env->a_start->prev = new_start;
		env->a_start = new_start;
	}
	if (env->b_start && env->b_start->next)
	{
		new_start = env->b_end;
		env->b_end = env->b_end->prev;
		env->b_end->next = NULL;
		new_start->next = env->b_start;
		new_start->prev = NULL;
		env->b_start->prev = new_start;
		env->b_start = new_start;
	}
	++(env->tot);
	((env->tot) != 1) ? ft_putstr_fd(" rrr", 1) : ft_putstr_fd("rrr", 1);
	(env->options & 8) ? print_pause(env) : 0;
}

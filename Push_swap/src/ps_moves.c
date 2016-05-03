/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:35:54 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/05 10:35:57 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_sa(t_env *e)
{
	t_elem	*tmp1;

	if (e->a_start && e->a_start->next)
	{
		tmp1 = e->a_start->next;
		e->a_start->next->next ? e->a_start->next->next->prev = e->a_start : 0;
		!(e->a_start->next->next) ? e->a_end = e->a_start : 0;
		e->a_start->next = e->a_start->next->next;
		e->a_start->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->a_start;
		e->a_start = tmp1;
		++(e->tot);
		((e->tot) != 1) ? ft_putstr_fd(" sa", 1) : ft_putstr_fd("sa", 1);
		if (e->options & 8)
			print_pause(e);
	}
}

void	move_sb(t_env *e)
{
	t_elem	*tmp1;

	if (e->b_start && e->b_start->next)
	{
		tmp1 = e->b_start->next;
		e->b_start->next->next ? e->b_start->next->next->prev = e->b_start : 0;
		!(e->b_start->next->next) ? e->b_end = e->b_start : 0;
		e->b_start->next = e->b_start->next->next;
		e->b_start->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->b_start;
		e->b_start = tmp1;
		++(e->tot);
		((e->tot) != 1) ? ft_putstr_fd(" sb", 1) : ft_putstr_fd("sb", 1);
		if (e->options & 8)
			print_pause(e);
	}
}

void	move_ss(t_env *e)
{
	t_elem	*tmp1;

	if (e->a_start && e->a_start->next)
	{
		tmp1 = e->a_start->next;
		e->a_start->next->next ? e->a_start->next->next->prev = e->a_start : 0;
		!(e->a_start->next->next) ? e->a_end = e->a_start : 0;
		e->a_start->next = e->a_start->next->next;
		e->a_start->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->a_start;
		e->a_start = tmp1;
	}
	if (e->b_start && e->b_start->next && (tmp1 = e->b_start->next))
	{
		e->b_start->next->next ? e->b_start->next->next->prev = e->b_start : 0;
		!(e->b_start->next->next) ? e->b_end = e->b_start : 0;
		e->b_start->next = e->b_start->next->next;
		e->b_start->prev = tmp1;
		tmp1->prev = NULL;
		tmp1->next = e->b_start;
		e->b_start = tmp1;
	}
	((e->tot) != 1) ? ft_putstr_fd(" ss", 1) : ft_putstr_fd("ss", 1);
	(e->options & 8) ? print_pause(e) : 0;
}

void	move_pa(t_env *env)
{
	t_elem	*tmp1;

	if (env->b_start)
	{
		tmp1 = env->b_start;
		env->b_start = tmp1->next;
		(env->b_start) ? env->b_start->prev = NULL : 0;
		!(env->b_start) ? env->b_end = NULL : 0;
		env->a_start ? env->a_start->prev = tmp1 : 0;
		tmp1->next = env->a_start;
		env->a_start = tmp1;
		!((env->a_start)->next) ? env->a_end = env->a_start : 0;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" pa", 1) : ft_putstr_fd("pa", 1);
		if (env->options & 8)
			print_pause(env);
		env->asize++;
		env->bsize--;
	}
}

void	move_pb(t_env *env)
{
	t_elem	*tmp1;

	if (env->a_start)
	{
		tmp1 = env->a_start;
		env->a_start = tmp1->next;
		(env->a_start) ? env->a_start->prev = NULL : 0;
		!(env->a_start) ? env->a_end = NULL : 0;
		env->b_start ? env->b_start->prev = tmp1 : 0;
		tmp1->next = env->b_start;
		env->b_start = tmp1;
		!(env->b_start->next) ? env->b_end = env->b_start : 0;
		++(env->tot);
		((env->tot) != 1) ? ft_putstr_fd(" pb", 1) : ft_putstr_fd("pb", 1);
		if (env->options & 8)
			print_pause(env);
		env->bsize++;
		env->asize--;
	}
}

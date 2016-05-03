/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:47:44 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/27 13:47:46 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_pile(char *str, t_elem **start)
{
	t_elem	*tmp;

	tmp = *start;
	ft_putstr_fd(str, 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->value);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

static void	print_revpile(char *str, t_elem **end)
{
	t_elem	*tmp;

	tmp = *end;
	ft_putstr_fd(str, 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->value);
		tmp = tmp->prev;
	}
	ft_putchar('\n');
}

void		print_pause(t_env *env)
{
	char	c[1];

	ft_putchar('\n');
	read(0, &c, 1);
	if (env->options & 16)
		print_revpile("Pile A:", &(env->a_end));
	else
		print_pile("Pile A:", &(env->a_start));
	if (env->options & 16)
		print_revpile("Pile B:", &(env->b_end));
	else
		print_pile("Pile B:", &(env->b_start));
	ft_putchar('\n');
}

void		print_option(t_env *env)
{
	if (env->options & 16)
		print_revpile("Pile A:", &(env->a_end));
	else
		print_pile("Pile A:", &(env->a_start));
	if (env->options & 16)
		print_revpile("Pile B:", &(env->b_end));
	else
		print_pile("Pile B:", &(env->b_start));
}

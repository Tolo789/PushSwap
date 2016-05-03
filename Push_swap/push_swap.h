/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmutti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 10:22:20 by cmutti            #+#    #+#             */
/*   Updated: 2016/04/05 10:22:23 by cmutti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define ASTA		env->a_start->value
# define ANEX		env->a_start->next->value
# define AEND		env->a_end->value

typedef struct		s_elem
{
	int				value;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_env
{
	int				index;
	int				options;
	int				asize;
	int				bsize;
	int				tot;
	int				pivot;
	int				choice;
	t_elem			*a_start;
	t_elem			*b_start;
	t_elem			*a_end;
	t_elem			*b_end;
}					t_env;

void				move_sa(t_env *env);
void				move_sb(t_env *env);
void				move_ss(t_env *env);
void				move_pa(t_env *env);
void				move_pb(t_env *env);
void				move_ra(t_env *env);
void				move_rb(t_env *env);
void				move_rr(t_env *env);
void				move_revra(t_env *env);
void				move_revrb(t_env *env);
void				move_revrr(t_env *env);

int					get_pile(int argc, char **argv, t_env *env);
void				begin_sort(t_env *env);
void				first_optimization(t_env *env);

int					is_ordered(t_env *env);
void				free_pile(t_elem **start, t_elem **end);
void				print_option(t_env *env);
void				print_pause(t_env *env);

void				only_a_sort(t_env *env);
void				sort_from_front(t_env *env);
void				sort_from_back(t_env *env);
void				push_little(t_env *env);
void				quicksort(t_env *env);

int					ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strequ(char const *s1, char const *s2);

#endif

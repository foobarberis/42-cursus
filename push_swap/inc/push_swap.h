/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:07:22 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/28 14:18:07 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node		t_node;
typedef struct s_register	t_register;

struct s_node
{
	int		data;
	int		index;
	int		score;
	t_node	*next;
	t_node	*prev;
};

struct s_register
{
	int		size;
	int		topi;
	t_node	*head;
	t_node	*tail;
};

enum e_actions
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

enum e_stacks
{
	A,
	B
};

/* MAIN */
void		solve(t_register *ra, t_register *rb);

/* CHECK */
int			check_arguments(int argc, char **argv);

/* SETUP */
int			setup(t_register *ra, t_register *rb, int argc, char **argv);

/* ACTIONS */
void		perform_action(t_register *a, t_register *b, int action);

/* SOLVE_LARGE */
void		solve_large(t_register *ra, t_register *rb);

/* SOLVE_SMALL */
void		solve_small(t_register *ra, t_register *rb);

/* SOLVE_UTILS */
int			find_low_index(t_register *r);
int			find_low_score(t_register *r);
int			find_gap(t_register *r);
int			locate_index(t_register *r, int i);
void		to_top(t_register *ra, t_register *rb, int k, int stack);

/* SOLVE_UTILS_LARGE */
void		to_top_large(t_register *ra, t_register *rb, int k);
void		optimize_rotate(t_register *ra, t_register *rb, int action);

/* PUSH_SWAP_UTILS */
int			ft_isdigit(int c);
void		bubble_sort(int *arr, int size);
int64_t		ft_atoi(const char *nptr);

/* LIST_UTILS */
t_node		*new_node(int n, int rank);
void		free_all(t_register *r);
int			add_node(t_register *r, t_node *new);
int			is_sorted(t_register *r);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:24 by woonchoi          #+#    #+#             */
/*   Updated: 2022/02/15 02:19:32 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FALSE 0
# define TRUE 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define OPEN_MAX 10240
# define BUFFER_SIZE 1024

typedef struct s_deque
{
	int				num;
	struct s_deque	*prev;
	struct s_deque	*next;
}	t_deque;

typedef struct s_info
{
	int		size_a;
	int		size_b;
	t_deque	*bot_a;
	t_deque	*top_a;
	t_deque	*bot_b;
	t_deque	*top_b;
	int		*arr;
}	t_info;

typedef struct s_merge
{
	int		*b;
	int		left_index;
	int		right_index;
	int		b_index;
}	t_merge;

/*
** Parsing utility
*/

int			is_digit(char c);
int			ft_atoll(const char *str);
void		ft_parsing(int argc, char **argv, t_info *info);

/*
** Preprocessing utility
*/

void		make_array(t_info *info);
void		init_m_info(int left, int right, int end, t_merge *m_info);
void		merge(int *a, int left, int right, int end);
void		merge_sort(int *a, int start, int end);
void		preprocessing(t_info *info);

/*
** Error utility
*/

void		print_error(int n);

/*
** Libft utility
*/

void		ft_bzero(void *s, size_t n);
void		ft_putendl_fd(char *s, int fd);
size_t		ft_strlen(const char *src);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);
char		*ft_strdup(char *str);

/*
**Deque utility
*/

t_deque		*create_node(int num);
void		push_back(int num, t_deque **top, t_deque **bot);
void		push_front(int num, t_deque **top, t_deque **bot);
int			pop_back(t_deque **top, t_deque **bot, int *num);
int			pop_front(t_deque **top, t_deque **bot, int *num);

/*
**Push swap utility
*/

void		sa(t_info *info, int flag);
void		sb(t_info *info, int flag);
void		ss(t_info *info, int flag);
void		pa(t_info *info, int flag);
void		pb(t_info *info, int flag);
void		ra(t_info *info, int flag);
void		rb(t_info *info, int flag);
void		rr(t_info *info, int flag);
void		rra(t_info *info, int flag);
void		rrb(t_info *info, int flag);
void		rrr(t_info *info, int flag);

/*
** Free utility
*/

void		free_ptr(void *ptr);
void		free_vec(void **vec);
void		free_node(t_deque *node);
void		free_all(t_info *info);

/*
** Push_Swap
*/
int			is_between(int a, int b, int num);
void		find_pos_a(t_info *info, int num, int *a);
int			check_sorted(t_info *info);
void		check_move_direc(t_info *info, int *a_move, int *b_move);
int			compare_move(int min_a, int min_b, int a_move, int b_move);
void		set_min_move(int *min_a, int *min_b, int a_move, int b_move);
void		find_best_move(t_info *info, int *min_a, int *min_b);
int			find_max_stack(t_info *info);
void		ft_rotate_rrr(t_info *info, int min_a, int min_b);
void		ft_rotate_rr(t_info *info, int min_a, int min_b);
void		ft_rotate(t_info *info, int min_a, int min_b);
void		ft_finish(t_info *info);
void		init_info(t_info *info);
void		ft_sort_three(t_info *info);
void		ft_sort_big(t_info *info);
void		ft_sort(t_info *info);

#endif

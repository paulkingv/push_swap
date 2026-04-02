// Created with help from Claude Sonnet 4.6
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int *a;
    int	*b;
    int	a_size;
    int b_size;
    char **args;
}   t_stack;

// Parsing
char	**get_args(char **argv);
int	    is_valid(char **args);
int 	ft_count_array(char **args);
void 	fill_stack(t_stack *stack, char **args);
void 	init_stacks(t_stack *stack);
int	    is_duplicate(t_stack *stack, int *arr);
int	    is_array_sorted(int *arr, int size);

// Indexing
void	index_stack(t_stack *stack);

// Operations
void	swap(int *arr, char *name, int size);
void	rotate(int *arr, int size, char *name);
void	reverse_rotate(int *arr, int size, char *name);
void	push(int *src, int *src_size, int *dst, int *dst_size, char *name);

// Sorting
void	sort_three_size(t_stack *stack);
void	sort_four_to_five_size(t_stack *stack);
void	radix_sort(t_stack *stack);

// Utils
int	    error_msg(t_stack *stack);
void	free_all(t_stack *stack);
void	ft_putendl_fd(char *s, int fd);

// libft
char    **ft_split(char *s, char c);
char    *ft_strdup(char *s);
long    ft_atol(char *s);

#endif

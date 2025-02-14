#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack{
    int index;
    int number;
    struct s_stack *next;
}                t_stack;


void print_error(); //ft_errors.c

static int is_num(char *arg); //control1.c
static int is_exist(char **args);
void ft_join1(int argc, char *argv[], int total_size); 
void ft_control(int argc , char *argv[]);
void ft_control2(char *str);

void ft_control3(int is_num_flag , int is_exist_flag, char **args);  //control2.c
int result(int counter);
int is_in_range(long number);
void free_args(char **args);
void free_stack(t_stack **stack);

         
long ft_atoi(const char *str); //utils1.c   
size_t	ft_strlen(const char *s);
char *ft_join2(int argc, char **argv);
char *ft_join3(int argc,char **argv,char *str);

static void	*del(char **ptr, int len); //ft_split.c
char	*ft_substr(char const *s, unsigned int start, size_t len);  
static int	ft_count_words(char const *s, char c);
static int	ft_count_chars(char const *s, char c);
char	**ft_split(char const *s, char c);

t_stack **create_stack(t_stack **a, int argc, char *str); //stack_create.c
t_stack **index_assignment(t_stack **stack_a);
t_stack *get_next_min(t_stack **stack_a);
int	is_sorted(t_stack **stack);

t_stack	*ft_lstnew(int content); //utils2.c
int	ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast2(t_stack *lst);
t_stack	*ft_lstlast3(t_stack *lst);

void swap(t_stack **stack); //actions1.c
void sa(t_stack **stack_a);
void sb(t_stack **stack_a);
void ss(t_stack **a, t_stack **b);

void pa(t_stack **a, t_stack **b); //actions2.c
void pb(t_stack **a, t_stack **b); 

void rotate (t_stack **stack); //actions3.c
void ra (t_stack **stack_a);
void ra (t_stack **stack_a);
void rr (t_stack **stack_a, t_stack **stack_b);

void rrotate(t_stack **stack); //actions4.c
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);


void	sort_3else(t_stack **a, t_stack *current, int min);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);
void	sort_5(t_stack **a, t_stack **b);
void basic_sort(t_stack **a, t_stack **b);
int	get_max_bits(t_stack **stack);
void	radix_sort(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b, int size);
int	get_position(t_stack **stack, int inx);
int	get_min(t_stack **stack, int val);

#endif 
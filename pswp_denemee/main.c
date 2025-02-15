
#include "push_swap.h"
#include <stdio.h>


void stack_free(t_stack **a, t_stack **b){
    free_stack(a);
	free_stack(b);
    print_error();
}

int main (int argc, char **argv){

    if (argc < 2)
        return (0);
    ft_control(argc,argv);

    t_stack	**a;
	t_stack	**b;
    char	**args;
    
    args = join_args(argc,argv);
    a = (t_stack **)malloc(sizeof(t_stack *));
	b = (t_stack **)malloc(sizeof(t_stack *));
	if (a == NULL || b == NULL)
		stack_free(a,b);
	*a = NULL;
	*b = NULL;
	create_stack(a, args); //esas farkı args ' yi çift pointer olarak göndermesi.
    if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	ft_sort(a, b, ft_lstsize(*a));
    
	return (0);
}
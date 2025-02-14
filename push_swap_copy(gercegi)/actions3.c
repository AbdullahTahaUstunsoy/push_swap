#include "push_swap.h"


void rotate (t_stack **stack){

    if (ft_lstsize(*stack) < 2)
		return ;

    t_stack *last;
    t_stack *second_last;
    t_stack *first;

    last = ft_lstlast(*stack);
    second_last = ft_lstlast2(*stack);
    first = *stack;

    last -> next = first;
    second_last ->next = NULL;
    *stack = last;

}

void ra (t_stack **stack_a){
    rotate (stack_a);
    write (1, "ra\n", 3);
}

void rb (t_stack **stack_b){
    rotate (stack_b);
    write (1, "rb\n", 3);
}

void rr (t_stack **stack_a, t_stack **stack_b){
    rotate (stack_a);
    rotate (stack_b);
    write (1, "rr\n", 3);
}
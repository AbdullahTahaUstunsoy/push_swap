#include "push_swap.h"


void rev_rotate(t_stack **stack){

    t_stack *first = *stack;
    t_stack *last = ft_lstlast (*stack);

    *stack = (*stack) -> next;
    last -> next = first;
    first -> next = NULL;

}

void rra(t_stack **stack_a){
    rev_rotate (stack_a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b){
    rev_rotate (stack_b);
    write(1, "rra\n", 4);
}

void rrr(t_stack **stack_a, t_stack **stack_b){
    rev_rotate (stack_a);
    rev_rotate (stack_b);
    write(1, "rrr\n", 4);
}
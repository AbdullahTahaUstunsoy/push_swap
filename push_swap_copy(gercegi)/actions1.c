#include "push_swap.h"

void swap(t_stack **stack){

    if (*stack == NULL || (*stack)->next == NULL)
        return; // Eğer stack boşsa veya sadece 1 eleman varsa işlem yapma

    t_stack *last;     // Son eklenen elemanı bul
    t_stack *second_last; // Sondan bir önce eklenen elemanı bul
    t_stack *third_last; // Sondan eklenen 3. elemanı bul

    last = ft_lstlast(*stack); 
    second_last = ft_lstlast2(*stack);
    third_last = ft_lstlast3(*stack);

    if (ft_lstsize(*stack) == 2){
        second_last->next = NULL; // Sondan bir önceki elemanın next'ini NULL yap
        last->next = second_last; // Son eklenen elemanı sondan bir önceki elemanla değiştir        
        *stack = last;  
    }
    
    else{
        second_last->next = NULL; 
        last->next = second_last;
        third_last->next = last;
    }
}

void sa(t_stack **stack_a){
    swap(stack_a);
    write(1, "sa\n", 2);
}

void sb(t_stack **stack_b){
    swap(stack_b);
    write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b){
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}
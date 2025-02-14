#include "push_swap.h"


void pa(t_stack **a, t_stack**b){

    
    if (*b == NULL) // Eğer stack B boşsa işlem yapma
        return;
    t_stack *top_a;  //incelenecek case var mı ? a 'da eleman yoksa 1 eleman varsa .. vs
    t_stack *top_b;
    t_stack *before_top_b;

    top_a = ft_lstlast(*a);
    top_b = ft_lstlast(*b);
    before_top_b = ft_lstlast2(*b);

    top_a->next = top_b;
    before_top_b->next = NULL;

    write(1, "pa\n", 3);
}


void pb(t_stack **a, t_stack**b){

    if (*a == NULL) // Eğer stack A boşsa işlem yapma
        return;
        
    t_stack *top_a;
    t_stack *top_b;
    t_stack *before_top_a;

    top_b = ft_lstlast(*b);
    top_a = ft_lstlast(*a);
    before_top_a = ft_lstlast2(*a);

    top_b->next = top_a;
    before_top_a ->next = NULL;

    write(1, "pb\n", 3);
}

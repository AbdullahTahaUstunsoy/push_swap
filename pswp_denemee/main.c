
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

	char *args;
    args = ft_join2(argc,argv); //tüm argümanları tek string haline getirdik. //bununla işin bitince free'le.

    t_stack **a; //bunlarla işin bitince free'le.
    t_stack **b;

    a = (t_stack **)malloc(sizeof(t_stack *));
    b = (t_stack **)malloc(sizeof(t_stack *));

    if (a == NULL || b == NULL) //NULL iseler frelemek saçma sil bunu.
       stack_free(a,b);
    *a = NULL;
    *b = NULL;
    a = create_stack(a, argc, args); //argümanlar dizi şeklinde birbirine bağlılardı. bunları bağlı liste şeklinde birbirine bağlı olacak şekilde a stack'ine ekledik (a ve b aslında birer pointerlar). b stack'ine elemanlar sıralama esnasında gelecekler.
    a = index_assignment(a); //stack'e gelen node'lar tuttukları sayılara göre indekslendi.

    ft_sort(a, b, ft_lstsize(*a));
	free(a);
    free(b);
    free(args);

	return (0);
}
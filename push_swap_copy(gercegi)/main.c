
#include "push_swap.h"

//hangi fonksiyonlar static olmalı onu tespit et.

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
    // satırdan kaçmak için indeks assignemnt fonksiyonu create stack fonksiyonuna bağlanabilir.
    if (is_sorted(a))
	{
        free_stack(a);
        free_stack(b); //satırdan kaçmak için silinebilir , sıralıysa da tekrar sıralar.
		return (0); // direkt stack_free yazmamamızın sebebi bu koşulda error yazmasın diye.
	}
    //kalan kod kısımları : aksiyonlar yazılacak , ardından basic sort ve sonrasında radix.
	return (0);
}

#include "push_swap.h"
#include <stdio.h>

void free_args(char **args){ //splitten dönen değeri free'liyoruz.  stack'i free'lemek için ayrı bir fonksiyon yapacağız.
    int i;

    i = 0;
    while (args[i] != NULL){
        free(args[i]);
        i++;
    }
    free(args);
}

void free_stack(t_stack **stack){ //stack'i free'lemek için yaptığımız fonksiyon. (split'ten dönen değer ile stack'imizi oluşturduk ve bu fonksiyon ile de free'liyioruz.)

    t_stack *current;
    t_stack *temp;


    current = *stack;
    while (current != NULL){
        temp = current -> next;
        free(current); 
        *stack = NULL;             //free'ledigimiz seyi tekrar free'lersek double free hatası alırız. Ancak NULL olan bir şeyi free'lersek hata vermez.
        current = temp;        
    }       
    //eslem burada bir de *stack=NULL yapmış buna bence gerek yok zaten çıkışta NULL oluyor.
    free(stack);
    stack = NULL;
}



int is_in_range(long number){  //atoi (atol yaptık) den long değer dönüyor , integer'ın sınırlarını aşaması durumunda kontrol içn yaptık.

    if (number < -2147483648 || number > 2147483647)    
            return (1);
    return (0);
    
    /*if (ft_strlen(args[i]) > 13) gerekli mi ?
			print_error(ac, args);*/
}

void ft_control3(int is_num_flag , int is_exist_flag, char **args){
    int is_in_range_flag;
    int number;
    int i;

    is_in_range_flag = 0;
    number = 0;
    i = 0;
    while(args[i] != NULL){
        if (is_in_range(ft_atoi(args[i])) == 1) //verilen argümanlar arasında integer sınırlarını aşan sayı var demek.
                is_in_range_flag = 1;           //hiçbir argüman sınırları aşmıyorsa hiçbir zaman flag 1 olmaz.
        i++;            
    }
    //free_args(args); //args ile is_in_range flag'imizi de aldık ve args ile  args[i]'leri free'ledik.
                 


    if (is_num_flag == 1 || is_exist_flag == 1 || is_in_range_flag == 1 )
        print_error(); //burada error basıyor //free lazım mı ?
}
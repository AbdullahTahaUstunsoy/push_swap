#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	
		
	if(current == NULL)
		return (1);
		
		while (current->next){
			if (current->number > current->next->number)
				return (0);
			current = current->next;
		}	
	return (1);
}
t_stack *get_next_min(t_stack **stack_a){

    t_stack *temp;
	t_stack *last_found_min;


    
    temp = *stack_a;
	last_found_min = NULL; //tüm değerler indekslendikten sonra NULL dönüp index_assignment fonksiyonundaki döngüyü sonlandırması için NULL ile başlattık.


    while(temp != NULL){
		if((temp->index == -1) && (last_found_min == NULL || last_found_min ->number > temp->number))  // bu tespit edildikten sonra bu iki değer swap olsa adım sayısı optimize olur mu ?
			last_found_min = temp; 
		temp = temp -> next;		
    }	
	return (last_found_min);
  }


t_stack **index_assignment(t_stack **stack_a){

		t_stack *current_min;
		int index;

		index = 0;  

		while ((current_min = get_next_min(stack_a)) != NULL){
			current_min ->index = index;
			index++;
		}

		return (stack_a);
}

/* önceki create_stack fonksiyonum
t_stack **create_stack(t_stack **stack_a,int argc,char *args){
    int i;
    t_stack *new;

    i = 0;
    stack_a = (t_stack **)ft_split(args,' '); //split'ten char ** dönüyor ancak biz t_stack ** ile tutmak istiyoruz.

    while(stack_a[i] != NULL){
        new = ft_lstnew(ft_atoi((char *)stack_a[i])); //atoi'ye değişken char * türünde gitmeli //stack_a ' ya tam olarak nasıl eleman eklendigini bir düşünebilirim.
        if (new == NULL){
            free_args((char **)stack_a);
            print_error();
        }
        ft_lstadd_back(stack_a, new);
		i++;	
    }
    return (stack_a);
}*/

//güncellediğim create_stack fonksiyonum 


t_stack **create_stack(t_stack **stack_a, int argc, char *args) {
    int i;
    t_stack *new;
    char **split_args;  // ft_split ile dönen char **'yi burada tutacağız.

    i = 0;
    split_args = ft_split(args, ' ');  // args'ı boşluklara göre ayırıyoruz.

    if (split_args == NULL) {
        printf("ft_split returned NULL\n");
        return stack_a;
    }

    // split_args NULL değilse, her bir argümanı stack'a ekleyelim
    while (split_args[i] != NULL) {
        printf("Adding %s to stack\n", split_args[i]);  // Debugging çıktısı ekleyelim
        new = ft_lstnew(ft_atoi(split_args[i]));  // Elemanı oluşturuyoruz.
        if (new == NULL) {
            free_args(split_args);  // Bellek sızıntısı olmasın diye temizliyoruz.
            print_error();
        }
        ft_lstadd_back(stack_a, new);  // Yeni node'u stack'a ekliyoruz.
        i++;
    }

    // split_args'ı serbest bırakıyoruz.
    free_args(split_args);

    // Stack'ın başındaki elemanı kontrol edelim.
    if (*stack_a == NULL) {
        printf("Stack is NULL after creation.\n");
    } else {
        printf("Stack created successfully.\n");
    }

    return stack_a;  // stack_a'yı döndürüyoruz.
}

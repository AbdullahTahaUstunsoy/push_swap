#include "push_swap.h"
#include <stdio.h>

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


void index_assignment(t_stack **stack_a){

		t_stack *current_min;
		int index;

		index = 0;  

		while ((current_min = get_next_min(stack_a)) != NULL){
			current_min ->index = index;
			index++;
		}

}


void	create_stack(t_stack **stack_a, char **args)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	index_assignment(stack_a);
}
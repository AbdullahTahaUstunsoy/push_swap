#include "push_swap.h"


t_stack	*ft_lstnew(int content)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	if (head == NULL)
		return (NULL);
	head->number = content;
    head->index = -1;
	head->next = NULL;
	return (head);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}


void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (new == NULL)
		return ;
		
    t_stack	*ptr;

    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
        ptr = *lst;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = new;
        new->next = NULL;
}

t_stack	*ft_lstlast2(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	
	while (lst->next->next != NULL)  //swap işlemi için sondan bir önceki node'u bulmalıyız.
		lst = lst->next;
	return (lst);
}


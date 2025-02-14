#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
long ft_atoi(const char *str)
{
	int	sign;
	long result;
	int	i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] != '\0') && (str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

char *ft_join3(int argc,char **argv,char *str){

	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	while(i < argc){
        k = 0;
        while(argv[i] != NULL && argv[i][k] != '\0'){
            str[j] = argv[i][k++];
            j++;
    }
    if (i != argc - 1) //son argümanı eklerken sona space koymasın.
        str[j++] = ' '; // boşluk ekledikten sonra döngüye girerken doğru konumda olmak için. str [j++] yaptık      
    i++;
  }
    str[j] = '\0';

  	return (str);
}

char *ft_join2(int argc, char **argv){

	char *str;
	int i;
	int j;
	int size;

	i = 1;
	size = 0;

	while (i < argc){
        j = 0;
        while(argv[i] != NULL && argv[i][j] != '\0'){            
            size++;
            j++;
        }
        size--; // \0 saymasin birleştirirken ekleyeceğiz 
        i++;
    }

	str = (char *)malloc(sizeof(char) * size + 1 + (argc -1 -1));
	if (str == NULL)
		exit (0);
	return (ft_join3(argc,argv,str));
}

t_stack	*ft_lstlast3(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next->next != NULL)
		lst = lst->next;
	return (lst);
}





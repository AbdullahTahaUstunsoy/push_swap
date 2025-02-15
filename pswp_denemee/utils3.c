#include "push_swap.h"

char *join_with_space(char *joined , char *arg){
    char *temp;
    char *new_joined_str;

    temp = ft_strjoin(joined, " ");
    if (temp == NULL)
	{
		free(joined);
		print_error();
	}

    new_joined_str = ft_strjoin (temp,arg);
    //free(temp);
	//free(joined);
    if (new_joined_str == NULL)
		print_error();
	return (new_joined_str );
}
char **join_args(int argc, char **argv){
	
    char **args;
    char *joined_str;
    int i;

    joined_str = ft_strdup("");
	if (joined_str == NULL)
		print_error();
	i = 1;

    while (i < argc){
        joined_str = join_with_space(joined_str, argv[i]);
		i++;
    }
    args = ft_split(joined_str, ' ');
	free(joined_str);
	if (args == NULL)
		print_error();
	return (args);
}
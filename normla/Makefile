NAME = push_swap

SRCS = actions/actions1.c\
	   actions/actions2.c\
	   actions/actions3.c\
	   actions/actions4.c\
	   control_functions/control1.c\
	   control_functions/control2.c\
	   sort_functions/basicsort1.c \
	   sort_functions/sort1.c\
	   utils/ft_errors.c\
	   utils/ft_split.c\
	   utils/utils1.c\
	   utils/utils2.c\
	   utils/utils3.c\
	   main.c\
	   stack_create.c\

OBJS = $(SRCS:.c=.o)


RM = rm -f
CC = cc
LIB1 = ar -rc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
		
clean:
	$(RM) $(OBJS) ${OBJSB}

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY : all bonus clean fclean re
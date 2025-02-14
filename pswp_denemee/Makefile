NAME = push_swap

SRCS = ft_split.c control1.c control2.c ft_errors.c  main.c utils1.c\

OBJS = $(SRCS:.c=.o)


RM = rm -f
CC = cc
LIB1 = ar -rc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS)
		$(LIB1) $(NAME)  $(OBJS)
		
clean:
	$(RM) $(OBJS) ${OBJSB}

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY : all bonus clean fclean re
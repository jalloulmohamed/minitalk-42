CC = gcc

NAME = server client

BONUS = server_bonus client_bonus


FLAGS = -Wall -Wextra -Werror

SRCC = ./libft/ft_atoi.c ./libft/ft_putstr.c client.c  ./libft/ft_itoa.c 

SRCS=  ./libft/ft_putstr.c   ./libft/ft_itoa.c server.c

SRC_bnsC =  ./libft/ft_atoi.c  ./libft/ft_itoa.c ./minitalk_bonus/client.c\
			./libft/ft_putstr.c  
SRC_bnsS =    ./libft/ft_itoa.c ./libft/ft_putstr.c ./minitalk_bonus/server.c 


OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJBC = $(SRC_bnsC:.c=.o)
OBJBS = $(SRC_bnsS:.c=.o)


all : $(NAME) 

$(NAME) : $(OBJC) $(OBJS) minitalk.h
	$(CC) $(OBJS)  -o server
	$(CC) $(OBJC)  -o client

bonus: $(BONUS) 

$(BONUS) : $(OBJBC) $(OBJBS) minitalk.h
	$(CC) $(OBJBS)  -o server_bonus 
	$(CC) $(OBJBC)  -o client_bonus


		
%.o : %.c minitalk.h
	$(CC)  $(FLAGS) -c $< -o $@ 

clean :
	rm -rf $(OBJS) $(OBJC) $(OBJBC) $(OBJBS)
fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all
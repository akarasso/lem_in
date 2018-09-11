CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -g

NAME	= lem-in

HEADERS	= ./includes ./libft/includes

SOURCES	= ./srcs/ant.c			./srcs/error.c			./srcs/link.c				\
	./srcs/main.c			./srcs/path.c			./srcs/room.c				\
	./srcs/solve.c			./srcs/parser/parse.c		./srcs/parser/parse_ant.c		\
	./srcs/parser/parse_cmd.c	./srcs/parser/parse_com.c	./srcs/parser/parse_pipe.c		\
	./srcs/parser/parse_room.c	./srcs/util/count_str_tab.c	./srcs/util/free_str_tab.c		\
	./srcs/util/ft_atoll.c		./srcs/util/str_digit.c		

OBJ	= $(SOURCES:.c=.o)

HEADER_LIST	= $(addprefix -I,$(HEADERS))

all	: $(NAME)

makelib	: 
	make -C libft/

cleanlib	: 
	make clean -C libft/

fcleanlib	: 
	make fclean -C libft/

%.o	: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADER_LIST) -c -o $@ $<

$(NAME)	: $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(HEADER_LIST) -o $(NAME) $(OBJ) ./libft/libft.a

clean	: cleanlib
	rm -f $(OBJ)

re	: fcleanlib fclean all

fclean	: cleanlib clean
	rm -f $(NAME)


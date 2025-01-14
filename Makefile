NAME = minitalk

start:
	make -C libft
	cp libft/libft.a .
	make all

all: server client

client: src/client.c
	gcc -Wall -Wextra -Werror src/client.c -o client

server: src/server.c
	gcc -Wall -Wextra -Werror src/server.c -o server

$(NAME): server client

clean:
	rm -f server client
	make clean -C libft

fclean: clean
	rm libft/libft.a
	rm libft.a

re: clean all

.PHONY: all clean fclean re
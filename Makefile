NAME = minitalk

start:
	@make -C libft
	cp libft/libft.a .
	make server
	make client

all: start

server: src/server.c
	cc -Wall -Wextra -Werror src/server.c libft.a -o server -g

client: src/client.c
	cc -Wall -Wextra -Werror src/client.c libft.a -o client -g

$(NAME): server client

clean:
	rm -f server client
	make clean -C libft

fclean: clean
	make fclean -C libft
	@if [ -f libft.a ]; then rm libft.a; fi

re: clean all

.PHONY: all clean fclean re
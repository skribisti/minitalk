NAME = minitalk

start:
	make -C libft
	cp libft/libft.a .

all: start server client

server: src/server.c
	cc -Wall -Wextra -Werror src/server.c libft.a -o server -g

client: src/client.c
	cc -Wall -Wextra -Werror src/client.c libft.a -o client -g

$(NAME): server client

clean:
	rm -f server client
	make clean -C libft

fclean: clean
	@if [ -f libft/libft.a ]; then rm libft/libft.a; fi
	@if [ -f libft.a ]; then rm libft.a; fi

re: clean all

.PHONY: all clean fclean re
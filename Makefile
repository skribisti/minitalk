NAME = minitalk

start:
	make server
	make client

all: start

server: src/server.c
	if [ ! -f libft.a ]; then make -C libft ; cp libft/libft.a . ; fi
	cc -Wall -Wextra -Werror src/server.c libft.a -o server -g

client: src/client.c
	if [ ! -f libft.a ]; then make -C libft ; cp libft/libft.a . ; fi
	cc -Wall -Wextra -Werror src/client.c libft.a -o client -g

$(NAME): server client

clean:
	rm -f libft.a
	make clean -C libft

fclean: clean
	rm -f server client
	make fclean -C libft

re: clean all

dev:
	git add .;
	git commit -m "dev" ;
	git push --force;
	git status;

.PHONY: all clean fclean re dev
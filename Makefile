NAME = minitalk

all: server client

server: src/server.c
	cc -Wall -Wextra -Werror src/server.c -o server -g

client: src/client.c
	cc -Wall -Wextra -Werror src/client.c -o client -g

clean:
	rm -f server client

fclean: clean

re: clean all

dev:
	git add .;
	git commit -m "dev" ;
	git push --force;
	git status;

.PHONY: all clean fclean re dev
all : libft/libft.a client server

libft/libft.a :
	@make -C libft/
client : client.c
	cc -Wall -Wextra -Werror client.c libft/libft.a -o client
	
server : server.c
	cc -Wall -Wextra -Werror  server.c libft/libft.a -o server

fclean :
	rm client
	rm server


clean :

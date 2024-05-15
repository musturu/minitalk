NAME = server
NAME2 = client

all : libft/libft.a client server

libft/libft.a :
	@make -C libft/
$(NAME2) : client.c
	cc -Wall -Wextra -Werror client.c libft/libft.a -o $(NAME2) 
	
$(NAME) : server.c
	cc -Wall -Wextra -Werror  server.c libft/libft.a -o $(NAME) 

bonus :
	cc -Wall -Wextra -Werror  server_bonus.c libft/libft.a -o $(NAME)_bonus
	cc -Wall -Wextra -Werror client_bonus.c libft/libft.a -o $(NAME2)_bonus

clean : 

fclean : clean
	rm server
	rm client
	@rm server_bonus
	@rm client_bonus

re : fclean all
	

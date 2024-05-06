# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmoricon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 09:13:33 by lmoricon          #+#    #+#              #
#    Updated: 2024/01/15 18:01:32 by lmoricon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_striteri.c

BSRCS = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OUTFILE = $(SRCS:.c=.o)

BOUTFILE = $(BSRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OUTFILE)
		ar rcs $(NAME) $(OUTFILE)

bonus: 	$(BOUTFILE)
		ar rcs $(NAME) $(BOUTFILE)

all:	$(NAME)

clean:
		$(RM) $(OUTFILE) $(BOUTFILE)

fclean: clean
		$(RM) $(NAME)

re: 	fclean all

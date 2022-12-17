# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jportier <jportier@42.student.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 12:07:15 by jportier          #+#    #+#              #
#    Updated: 2022/11/27 14:29:09 by jportier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c \

BONUS_SRCS	= ft_lstadd_front.c \
	  ft_lstadd_back.c \
	  ft_lstclear.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstlast.c \
	  ft_lstnew.c \
	  ft_lstsize.c \
	  ft_lstmap.c \

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS_SRCS:.c=.o)

NAME = libft.a

%.o:%.c
	cc -Wall -Wextra -Werror -c $< -o $@

$(NAME):	$(OBJS)
			ar -src $@ $^

bonus:	$(OBJS_BONUS)
	@make OBJS="${OBJS_BONUS}" all

all:	$(NAME)

clean:
		rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	 all clean fclean re

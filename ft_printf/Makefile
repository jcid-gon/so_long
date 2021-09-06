# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcid-gon <jcid-gon@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 11:47:29 by jcid-gon          #+#    #+#              #
#    Updated: 2021/08/18 11:47:30 by jcid-gon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c			\
		ft_int2base.c		\
		ft_int2baseupp.c	\
		ft_putchar_fd.c		\
		ft_putnbr_fd.c		\
		ft_putstr_fd.c


NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC = clang

CC_FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@clang $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar -rv $(NAME) $(OBJECTS_PREFIXED)
	@echo "Printf Done !"

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

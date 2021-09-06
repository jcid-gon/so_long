
NAME = so_long.a

SRCS_MAIN = so_long.c

SRCS =	srcs/map_reader.c		\
		srcs/map_reader_utils.c	\
		srcs/initial_setup.c	\
		srcs/image_manager.c	\
		srcs/player_movement.c

OBJS = $(SRCS:.c=.o)
OBJS_MAIN = $(SRCS_MAIN:.c=.o)
CC = clang
CCFLAGS = -Wall -Werror -Wextra
RM = rm -rf
MLX_PATH = ./mlx/
PRINTF_PATH = ./ft_printf

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJS_MAIN) $(OBJS)
	$(MAKE) -C $(MLX_PATH)
	mv ./mlx/libmlx.a .
	$(MAKE) -C $(PRINTF_PATH)
	mv ./ft_printf/libftprintf.a .
	$(CC) $(CCFLAGS) $(OBJS_MAIN) $(OBJS) -L . -lmlx -lftprintf -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(MLX_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_MAIN)

fclean: clean
	$(RM) $(NAME)
	$(RM) libmlx.a
	$(RM) libftprintf.a

re: fclean all

.PHONY: all clean fclean re

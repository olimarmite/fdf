NAME = test

MLX_DIR = mlx_linux
MLX_FILE = libmlx.a

MLX_LIB = $(MLX_DIR)/$(MLX_FILE)

SRC_DIR = src
OBJ_DIR = obj

SRCS = \
	$(addprefix map/,				\
		map_line_add.c				\
		map_print.c					\
		point_create.c				\
		map_destroy.c				\
	)								\
	$(addprefix utils/,				\
		$(addprefix split/,			\
			ft_split.c				\
			ft_substr.c				\
		)							\
		$(addprefix	get_next_line/,	\
			get_next_line_utils.c	\
			get_next_line.c			\
			get_next_line_close.c	\
		)							\
		$(addprefix vectors/,		\
			$(addprefix vect2d/,	\
				vect2d_add.c		\
				vect2d_multiply.c	\
				vect2d_divide.c		\
				vect2d.c			\
			)						\
			$(addprefix vect3d/,	\
				vect3d_add.c		\
				vect3d_multiply.c	\
				vect3d_divide.c		\
				vect3d.c			\
			)						\
		)							\
	)								\
	main.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
RM = rm -rf
MKDIR = mkdir -p

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(info CREATED $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) -Wall -Wextra -Werror -Imlx_linux -c -g -o $@ $<
	$(info CREATED $@)

clean:
	$(MAKE) clean -sC $(MLX_DIR)
	$(RM) $(OBJS) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(MLX_LIB):
	$(MAKE) -sC $(MLX_DIR)

.PHONY: all clean fclean re

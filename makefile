NAME = fdf
TEST_NAME = unit_test

MLX_DIR = mlx_linux
MLX_FILE = libmlx.a

MLX_LIB = $(MLX_DIR)/$(MLX_FILE)

OBJ_COMMON_DIR	= obj
SRC_DIR			= src
OBJ_DIR			= $(OBJ_COMMON_DIR)/fdf

TEST_SRC_DIR 	= tests
TEST_OBJ_DIR 	= $(OBJ_COMMON_DIR)/tests

SRCS = \
	$(addprefix map/,							\
		map_line_add.c							\
		map_print.c								\
		point_create.c							\
		map_destroy.c							\
	)											\
	$(addprefix graphics/,						\
		$(addprefix transformers/,				\
			isometry.c							\
		)										\
		$(addprefix drawing/,					\
			draw_line.c							\
			draw_pixel.c						\
			fill_image.c						\
			refresh.c							\
		)										\
		$(addprefix models/,					\
			pixel_create.c						\
			line_create.c						\
		)										\
		$(addprefix mlx_utils/,					\
			drawable_window_create.c			\
			image_wrapper_create.c				\
			drawable_window_destroy.c			\
			image_wrapper_destroy.c				\
		)										\
	)											\
	$(addprefix parsing/,						\
		parse_file.c							\
	)											\
	$(addprefix events/,						\
		events.c								\
	)											\
	$(addprefix fdf_logic/,						\
		core.c									\
		tiles_calcs.c							\
		redraw_map.c							\
		$(addprefix controls/,					\
			controls.c							\
		)										\
	)											\
	$(addprefix exit/,							\
		fdf_exit.c								\
	)											\
	$(addprefix utils/,							\
		$(addprefix exception_management/,		\
			ft_error.c							\
		)										\
		$(addprefix memory/,					\
			ft_memset.c							\
		)										\
		$(addprefix color/,						\
			color_channel.c						\
			color_lerp.c						\
			color_to_int.c						\
		)										\
		$(addprefix math/,						\
			ft_min.c							\
			ft_lerp.c							\
		)										\
		$(addprefix split/,						\
			ft_split.c							\
			ft_substr.c							\
		)										\
		$(addprefix	get_next_line/,				\
			get_next_line_utils.c				\
			get_next_line.c						\
			get_next_line_close.c				\
		)										\
		$(addprefix vectors/,					\
			$(addprefix vect2d/,				\
				vect2d_add.c					\
				vect2d_multiply.c				\
				vect2d_divide.c					\
				vect2d.c						\
			)									\
			$(addprefix vect3d/,				\
				vect3d_add.c					\
				vect3d_multiply.c				\
				vect3d_divide.c					\
				vect3d.c						\
			)									\
		)										\
		$(addprefix strings/,					\
			ft_atoi.c							\
			ft_atoi_base.c						\
			ft_atoi_hex.c						\
			ft_isdigit.c						\
			ft_isspace.c						\
			ft_strncmp.c						\
			ft_strichr.c						\
			ft_putstr_fd.c						\
		)										\
	)

SRCS_MAIN = main.c

TEST_SRCS = \
	$(addprefix munit/,							\
		munit.c									\
	)											\
	$(addprefix tests/,							\
		test_atoi.c								\
		test_strichr.c							\
		test_atoi_base.c						\
	)											\
	main.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_MAIN := $(SRCS_MAIN:%=$(SRC_DIR)/%)
OBJS_MAIN = $(SRCS_MAIN:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_SRCS := $(TEST_SRCS:%=$(TEST_SRC_DIR)/%)
TEST_OBJS = $(TEST_SRCS:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.o)

CC = cc
RM = rm -rf
MKDIR = mkdir -p

CFLAGS = -Wall -Wextra -g #-Werror

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS_MAIN) $(OBJS)
	$(CC) $(OBJS_MAIN) $(OBJS) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(info CREATED $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -Imlx_linux -c -g -o $@ $<
	$(info CREATED $@)

$(TEST_NAME): $(OBJS) $(TEST_OBJS)
	$(CC) $^ -o $@
	$(info CREATED $@)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -Imlx_linux -c -g -o $@ $<
	$(info CREATED $@)

clean:
	$(MAKE) clean -sC $(MLX_DIR)
	$(RM) $(OBJ_DIR) $(TEST_OBJ_DIR) $(OBJ_COMMON_DIR)

fclean: clean
	$(RM) $(NAME) $(TEST_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

test: $(TEST_NAME)
	./$(TEST_NAME)

$(MLX_LIB):
	$(MAKE) -sC $(MLX_DIR)

malloc_test: $(MLX_LIB) $(OBJS_MAIN) $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic $(OBJS_MAIN) $(OBJS) -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz  -L. -lmallocator -o $@

.PHONY: all clean fclean re test

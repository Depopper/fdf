NAME = fdf

SRC = 	main.c \
		parser.c \
		lst_point.c \


INCLUDES = -Ilibft/includes -Iminilibx -Iinclude
LIB_FLAGS =  -Llibbsd -Llibft -Lminilibx  -lbsd -lft -lmlx
FLAGS = $(INCLUDES)

OBJ_DIR = obj
DIRS = 	$(OBJ_DIR)

SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(DIRS) $(OBJS)
	@make -C libft
	@make -C minilibx
	@gcc $(OBJS) $(FLAGS) $(LIB_FLAGS) -o $(NAME) -Ofast
	@echo "\n✅  FDF BUILT !"

$(DIRS):
	@mkdir  $@

$(OBJ_DIR)/%.o: %.c
	@gcc  $(FLAGS) -c $< -o $@ -g3
	@echo "$(NAME) => \e[33;32m$@\e[33;0m"

clean:
	rm -rf $(DIRS)

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

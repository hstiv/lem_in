NAME = libvizu.a

LFT = $(LFT)

SRC = ft_newmlx.c run_window.c bresenham.c circle.c mappaint.c \
		ft_rec.c ft_newlst.c triple_split.c ft_triplefree.c adj_list.c \
		free_lem.c link_make.c key_press.c mouse_press.c mouse_move.c \
		mouse_release.c mappaint_tools.c

OBJECT = ft_newmlx.o run_window.o bresenham.o circle.o mappaint.o \
		ft_rec.o ft_newlst.o triple_split.o ft_triplefree.o adj_list.o \
		free_lem.o link_make.o key_press.o mouse_press.o mouse_move.o \
		mouse_release.o mappaint_tools.o

INCLUDES = libft/

FLAGS = -Wall -Wextra -Werror

LMLX = ./.libmlx/

all: $(NAME)

$(NAME):
	@make -C $(INCLUDES) re
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) -I $(LMLX)
	@ar -r -c -s $(NAME) $(OBJECT)
	@mkdir obj && mv $(OBJECT) obj/

norm:
	norminette *.c
	norminette *.h

clean:
	@rm -rf obj
	@make -C $(INCLUDES) fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all

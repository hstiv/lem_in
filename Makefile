NAME = lem_in

VIZU = vizu-hex

HEAD = includes/

WWW = -Wall -Wextra -Werror

LFT = libft/libft.a

SRC = src/lem_in.c src/ft_rec.c src/ft_newlst.c src/split_free.c \
src/switch_links.c src/adj_list.c src/free_lem.c src/link_make.c \
src/utils.c src/groups.c src/dijkstra_shortest_path_.c src/path.c \
src/intersection_handling.c src/queue.c src/rec_tools.c src/run_ants.c \
src/recursive_pathfinder.c $(LFT)

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ $@ is compiling... Wait a sec."
	@make -C libft re && gcc $(WWW) -g -o $@ $(SRC) -I $(HEAD)
	@rm -rf lem_in.dSYM
	@echo "(•̀ᴗ•́)و $@ generated!".

$(VIZU):
	@make -C vizu re
	@mv vizu/vizu-hex ./
clean:
	@rm -rf src/*.o
	@rm -rf vizu-hex
	@make -C vizu fclean
	@make -C libft fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

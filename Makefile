NAME = lem_in

VIZU = vizu-hex

HEAD = includes/

WWW = -Wall -Wextra -Werror

LFT = libft/libft.a

SRC = src/lem_in.c src/ft_rec.c src/ft_newlst.c src/triple_split.c \
src/ft_triplefree.c src/adj_list.c src/free_lem.c src/link_make.c $(LFT)

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

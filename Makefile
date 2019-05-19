NAME = lem_in

HEAD = includes/

WWW = -Wall -Wextra -Werror

LFT = libft/libft.a

SRC = src/lem_in.c src/ft_rec.c $(LFT) 

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ $@ is compiling... Wait a sec."
	@make -C libft re && gcc $(WWW) -g -o $@ $(SRC) -I $(HEAD)
	@echo "(•̀ᴗ•́)و $@ generated!".

clean:
	@rm -rf src/*.o
	@make -C libft fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

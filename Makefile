NAME = lem_in

HEAD = includes/

WWW = -Wall -Wextra -Werror

LFT = libft/libft.a

SRC = $(LFT)

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ $@ is compiling... Wait a sec."
	@make -C libft re && gcc $(WWW) -g -o $@ $(SRC) -I $(HEAD)
	@mkdir obj
	@mv src/*.o obj/
	@echo "(•̀ᴗ•́)و $@ generated!".

clean:
	@rm -rf obj
	@make -C libft fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all

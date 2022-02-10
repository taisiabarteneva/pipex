NAME = pipex

SRC =	cmd_handle.c	error.c		exec.c\
			here_doc.c		init.c		main.c\
			parse.c			pipes.c

D_SRC	= src
D_OBJ	= obj
INCL	= pipex.h

SRC 	:= $(SRC:%.c=$(D_SRC)/%.c)
OBJ 	= $(SRC:$(D_SRC)/%.c=$(D_OBJ)/%.o)
LIB = libft/libft.a
DIR_LIB = libft

FLAGS = -Wall -Wextra -Werror

PINK 		=  \033[1;35m
NO_COLOR 	=	\033[0m 

all : $(NAME)

lib :
	$(MAKE) -sC $(DIR_LIB)

$(NAME) : lib $(OBJ) $(LIB)
	gcc $(OBJ) $(LIB) -I. -o $(NAME)
	@echo "$(PINK)You compiled the mandatory part of the project.$(NO_COLOR)"

$(D_OBJ)/%.o : $(D_SRC)/%.c $(INCL)
	@mkdir -p $(D_OBJ)
	gcc $(FLAGS) -I. -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rm -rf $(D_OBJ)
	@$(MAKE) clean -C $(DIR_LIB)

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(DIR_LIB)

re : fclean all

.PHONY :
	all clean fclean re lib
##
## Makefile for BSQ in /home/amaury/delivery/CPE_2016_BSQ
## 
## Made by Amaury Bernard
## Login   <amaury.bernard@epitech.eu>
## 
## Started on  Mon Dec  5 15:58:00 2016 Amaury Bernard
## Last update Fri May 19 21:47:40 2017 Nicolas Marsan
##
##

SRC	=	src/main.c		\
		src/str_equal.c		\
		src/get_sys_cmds.c	\
		src/path_failure.c	\
		src/shell.c		\
		src/cmd_env.c		\
		src/cmd_exit.c		\
		src/cmd_setenv.c	\
		src/cmd_cd.c		\
		src/cmd_echo.c		\
		src/my_get_nbr.c	\
		src/my_str_isnum.c	\
		src/my_str_isalphanum.c	\
		src/my_strdup.c		\
		src/my_2str_in1.c	\
		src/get_var_env.c	\
		src/exec_cmds.c		\
		src/get_input_argv.c	\
		src/char_allowed.c	\
		src/get_input_cmd.c	\
		src/get_in_handle_sep.c	\
		src/init_env.c		\
		src/use_env.c		\
		src/rt_with_msg.c	\
		src/replace_home_char.c	\
		src/father.c		\
		src/control_c.c		\
		src/handler.c		\
		src/handle_redir.c

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L./lib -lget_next_line -lmy_printf

CFLAGS	=	-Wall -Wextra -I./include

CC	=	gcc

NAME	=	42sh

all: 		$(NAME)

$(NAME): 	$(OBJ)
	make -s -C lib/my_printf/
	make -s -C lib/get_next_line/
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

debug: CFLAGS += -g -g3
debug: fclean $(NAME)

clean:
	rm -f $(OBJ)
	make clean -s -C lib/my_printf/
	make clean -s -C lib/get_next_line/

fclean: clean
	rm -f $(NAME)
	make fclean -s -C lib/my_printf/
	make fclean -s -C lib/get_next_line/

re: fclean all

.PHONY: clean fclean all re

NAME	=	philo

SRC_DIR	=	./src/

OBJ_DIR	=	./.obj/

INC_DIR	=	./include/

LIST_SRC	=	philo.c ft_check_input.c ft_malloc.c ft_init.c \
				ft_init_mutex.c utils.c ft_create_thread.c \
				ft_philo.c 

LIST_OBJ	=	$(LIST_SRC:.c=.o)

LIST_INC	=	philo.h

SRC		=	$(addprefix $(SRC_DIR), $(LIST_SRC))

OBJ		=	$(addprefix $(OBJ_DIR), $(LIST_OBJ))

INC		=	$(addprefix $(INC_DIR), $(LIST_INC))

MAKEFILE	=	Makefile

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror 

all: $(NAME)

$(NAME)	:	$(OBJ_DIR) $(OBJ) $(INC) $(MAKEFILE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -pthread

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INC) 
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean : 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY: clean fclearn re all bonus

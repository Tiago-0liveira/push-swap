NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

SRC =	main.c

includefolder = include
libdir = libft
libname = libft.a
LIBFT = $(libdir)/$(libname)
INCLUDES = -I $(includefolder) -I $(libdir)
OBJ_DIR = obj
SRCS = $(addprefix src/, $(SRC))
OBJS = $(patsubst src/%, $(OBJ_DIR)/%, $(SRCS:%.c=%.o))

# Reset

Color_Off='\033[0m'       # Text Reset

IRed='\033[0;91m'         # Red
IGreen='\033[0;92m'       # Green
IYellow='\033[0;93m'      # Yellow
ICyan='\033[0;96m'        # Cyan

MSG1 = @echo ${IGreen}"Compiled Successfully ✔︎"${Color_Off}
MSG2 = @echo ${IYellow}"Cleaned Successfully ✔︎"${Color_Off}
MSG3 = @echo ${ICyan}"Cleaned ${NAME} Successfully ✔︎"${Color_Off}

all: $(NAME)

$(LIBFT):
	@make -s -C $(libdir)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(LIBFT) -L $(libdir) -lft -o $(NAME)
	$(MSG1)

$(OBJ_DIR)/%.o: $(SRCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean --no-print-directory -C $(libdir)
	$(MSG2)

fclean: clean
	@/bin/rm -rf $(NAME) ${OBJ_DIR} $(LIBFT)
	$(MSG3)

re: fclean all
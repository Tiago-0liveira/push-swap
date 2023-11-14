NAME = push_swap

CC = @cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c

# Paths
LIB_FOLDER = printf
INCLUDE_FOLDERS = -I include -I $(LIB_FOLDER)

OBJ_DIR = obj
SRCS = $(addprefix src/, $(SRC))
OBJS = $(patsubst src/%, $(OBJ_DIR)/%, $(SRCS:%.c=%.o))

# Library Files
LIB_SRCS = $(wildcard $(LIB_FOLDER)/*.c)
LIB_OBJS = $(patsubst $(LIB_FOLDER)/%.c, $(OBJ_DIR)/$(LIB_FOLDER)/%, $(LIB_SRCS:%.c=%.o))

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

$(NAME): $(OBJS) $(LIB_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) $^ -o $(NAME)
	$(MSG1)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) -o $@ -c $<

$(OBJ_DIR)/$(LIB_FOLDER)/%.o: $(LIB_FOLDER)/%.c
	@mkdir -p $(OBJ_DIR)/$(LIB_FOLDER)
	@$(CC) $(CFLAGS) $(INCLUDE_FOLDERS) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJ_DIR)
	$(MSG2)

fclean: clean
	@/bin/rm -rf $(NAME)
	$(MSG3)

re: fclean all

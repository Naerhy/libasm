NAME = libasm.a

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.s)
OBJ = $(patsubst $(SRC_DIR)/%.s,$(OBJ_DIR)/%.o,$(SRC))

NASM = nasm
NFLAGS = -f elf64

RM = rm -rf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(@D)
	$(NASM) $(NFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

CXX=c++
CXXFLAGS=-std=c++98
NAME=phonebook
OBJ_DIR=obj
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))
HEADERS=$(wildcard *.hpp)

ifndef LENIENT
	CXXFLAGS += -Wall -Wextra -Werror -Wpedantic
endif

ifdef DEBUG
	CXXFLAGS += -g
endif

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(HEADERS) -o $(NAME) $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)

valgrind: all
	echo -e "bleurgh\nADD\n\nfirst\nlast\nnick\n123\nyou'll never know\nSEARCH\n1\nb\n0\nEXIT\n" | valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2>&1 | ../../eval.sh

.PHONY:
	all clean fclean re test valgrind

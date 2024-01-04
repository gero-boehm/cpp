CXX=c++
CXXFLAGS=-std=c++98
NAME=bureaucrat
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
	$(CXX) $(CXXFLAGS) -o $(NAME) $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2>&1 | ../../eval.sh

.PHONY:
	all clean fclean re test valgrind

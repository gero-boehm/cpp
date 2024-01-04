CXX=c++
CXXFLAGS=-std=c++98
NAME=replace
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
	echo "hello how are you?" > tmp.txt; valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) tmp.txt " " "_" 2>&1 | ../../eval.sh; rm -f tmp.txt
	echo -n "" > tmp.txt; valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) tmp.txt " " "_" 2>&1 | ../../eval.sh; rm -f tmp.txt
	echo "this is a test with no match" > tmp.txt; valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) tmp.txt "strawberry" "jam" 2>&1 | ../../eval.sh; rm -f tmp.txt

.PHONY:
	all clean fclean re test valgrind

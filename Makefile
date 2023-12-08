CXX=c++
CXXFLAGS=
NAME=
OBJ_DIR=obj
SRC=$(wildcard *.cpp)
OBJ=$(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))
HEADERS=$(wildcard *.hpp)

ifndef LENIENT
	CXXFLAGS += -Wall -Wextra -Werror
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

.PHONY:
	all bonus clean fclean test
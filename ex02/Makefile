CXX=c++

CXXFLAGS=-Werror -Wall -Wextra -std=c++98

NAME=RTTI

SRC=main.cpp A.cpp B.cpp C.cpp Base.cpp

OBJ_DIR=obj

OBJ=$(SRC:%.cpp=$(OBJ_DIR)/%.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o:%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all


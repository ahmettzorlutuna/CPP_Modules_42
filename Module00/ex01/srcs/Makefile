CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = phonebook

SRCS = main.cpp Validator.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

# Link stage: .o -> megaphone
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# .cpp -> .o rule (compiling)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
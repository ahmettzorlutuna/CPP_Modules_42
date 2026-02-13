# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/22 22:11:14 by azorlutu          #+#    #+#              #
#    Updated: 2026/01/22 22:11:14 by azorlutu         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = replace

SRCS = main.cpp Replace.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

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
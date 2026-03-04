# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: azorlutu <azorlutu@student.42istanbul.com.tr>   +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/03 22:21:19 by azorlutu          #+#    #+#              #
#    Updated: 2026/03/04 22:01:51 by azorlutu         ###   ########.tr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME  = iter

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

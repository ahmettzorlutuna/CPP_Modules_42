# $@ → o an üretilen hedefin adı
# $^ → tüm bağımlılıklar
# $< → ilk bağımlılıklar (özellikle pattern rule’da)

# Build flow summary
# You type make → the default target is all: $(NAME) → so megaphone is requested.
# make checks: “megaphone depends on megaphone.o.”
# If megaphone.o does not exist (or is older than the source), the pattern rule %.o: %.cpp is triggered.
# megaphone.cpp is compiled → produces megaphone.o.
# Then megaphone.o is linked → produces the final executable megaphone.

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRCS = megaphone.cpp
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

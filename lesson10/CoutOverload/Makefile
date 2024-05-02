CXX     = g++
FLAGS   = -std=C++11
NAME    = out

SRCS    = main.cpp
HDRS    = TwoNumbers.hpp
INCL    = .

OBJS    = $(SRCS:%.cpp=%.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -I $(INCL) -o $(NAME)

$(OBJS): $(HDRS)

%.o: %.cpp
	$(CXX) -c $<
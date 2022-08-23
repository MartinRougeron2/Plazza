NAME	= plazza

CXX	= clang++

RM	= rm -f

SRCS	=	$(wildcard $(addprefix src/, *).cpp)					\
			$(wildcard $(addprefix src/reception/, *).cpp)			\
			$(wildcard $(addprefix src/reception/command/, *).cpp)	\
			$(wildcard $(addprefix src/kitchen/, *).cpp)			\
			$(wildcard $(addprefix src/pizza/, *).cpp)


SRCS_TEST	=  $(filter-out src/main.cpp, $(SRCS)) \
			$(wildcard $(addprefix unit_tests/, *).cpp)

OBJS	= $(SRCS:.cpp=.o)

OBJS_TESTS	= $(SRCS_TEST:.cpp=.o)

CXXFLAGS = -I ./include/
CXXFLAGS += -Wall -Wextra -Wno-unused-command-line-argument
CXXFLAGS += -lpthread -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

unit_tests: $(OBJS_TESTS)
	 $(CXX) $(OBJS_TESTS) -o unit_test $(CXXFLAGS) -lgtest

.PHONY: all clean fclean re unit_tests

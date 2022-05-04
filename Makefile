NAME = pipex

HEADER =  pipex.h \

SRCS =   pipex.c \

OBJS =   $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

CC = gcc

CFLAGS = -MMD #-Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:  $(NAME)

clean:
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@$(RM) $(NAME)

re:   fclean all

.PHONY:  all clean fclean re

include $(wildcard $(DEPS))
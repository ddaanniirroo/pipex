NAME = pipex

HEADER =  pipex.h \

SRCS =   pipex.c \
   ft_split.c \
   pipex_help.c \
   utils.c \

OBJS =   $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o:  %.c pipex.h
   $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADER)
   $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:  $(NAME)

clean:
   @$(RM) $(OBJS)

fclean: clean
   @$(RM) $(NAME)

re:   fclean all

.PHONY:  all clean fclean re
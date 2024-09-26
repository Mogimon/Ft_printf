NAME			= libftprintf.a

SOURCES 		= ft_printchar.c \
					ft_printf.c \
					ft_printnbr.c \
					ft_printptr.c \
					ft_printstr.c \
					ft_unsigned.c \
					ft_hex.c \

HEADERS 		= .

OBJECTS 		= $(SOURCES:.c=.o)


CC				= cc

FLAGS			= -Wall -Werror -Wextra

AR				= ar -rsc

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJECTS) ft_printf.h Makefile
				$(AR) $(NAME) $(OBJECTS)

%.o:%.c
				$(CC) -I $(HEADERS) $< -o $@ -c $(FLAGS)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
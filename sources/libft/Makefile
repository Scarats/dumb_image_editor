SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
        ft_isascii.c ft_strlen.c ft_memset.c \
        ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
        ft_strlcat.c ft_calloc.c ft_strncmp.c ft_strchr.c \
        ft_strrchr.c ft_atoi.c ft_isprint.c ft_memchr.c \
        ft_memcmp.c ft_strnstr.c ft_tolower.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_toupper.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		./ft_printf/ft_printf.c ./ft_printf/type_c.c \
		./ft_printf/type_s.c ./ft_printf/type_i.c \
		./ft_printf/type_p.c ./ft_printf/to_hexa.c \
		./ft_printf/type_xx.c ./ft_printf/type_u.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c ft_strstr.c \
        ./get_next_line/get_next_line_bonus.c \
        ./get_next_line/get_next_line.c \
        ./get_next_line/get_next_line_utils_bonus.c \
        ./get_next_line/get_next_line_utils.c \
		arraylen.c ft_strcpy.c my_malloc.c get_extension.c \

FLAGS	= -Wall -Wextra -Werror 

CC		= cc
AR		= ar rcs
RM		= rm -f
OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

.c:.o
			${CC} ${FLAGS} -c $< -o $@

${NAME}: 	${OBJS}
			${AR} ${NAME} ${OBJS}

all: 		${NAME}

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME} 

re:			fclean all
	
.PHONY:		all bonus clean fclean re 
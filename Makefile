SRCS	= ./sources/fdf.c ./sources/image_editor/export.c ./sources/image_editor/file_name.c ./sources/utils/draw.c \
    ./sources/utils/parsing.c ./sources/image_editor/pen_mode.c ./sources/utils/hooks.c ./sources/utils/init.c ./sources/image_editor/import.c \
    ./sources/image_editor/eraser.c ./sources/utils/3Dto2D.c ./sources/utils/print_fdf.c ./sources/utils/error_handler.c ./sources/utils/scale_and_offset.c \
    ./sources/utils/utils.c

FLAGS	= -Wall -Wextra -Werror 

CC		= cc
RM		= rm -f
OBJ_DIR = dot_o
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME	= fdf

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -Imlx_linux -Ilibft -c $< -o $@

${NAME}: 	${OBJS}
	@make -C ./sources/libft
	@make -C ./mlx
	${CC} ${OBJS} -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -L./sources/libft -lft -o ${NAME} 

all: 		${NAME}

clean:	
	@make fclean -C ./sources/libft
	@make clean -C mlx
	${RM} -r ${OBJ_DIR}

fclean:		clean
	${RM} ${NAME} 

re:			fclean all

bonus: re
    
.PHONY:		all bonus clean fclean re
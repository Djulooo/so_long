.PHONY:					all $(NAME) lib minilibx clean fclean re bonus

NAME					=	so_long

HEADER_DIR				=	sources/so_long.h
HEADER_DIR_BONUS		=	sources/so_long_bonus.h

DIR						=	sources/
DIR_BONUS				=	sources_bonus/
SRC						=	main.c	error.c	parse_map.c	parse_map_bis.c	init.c	key_hooks.c	display_map.c	player_movements.c \
							path_finding.c	path_finding_utils.c
SRC_BONUS				=	main_bonus.c	error_bonus.c	parse_map_bonus.c	parse_map_bis_bonus.c	init_bonus.c	\
							key_hooks_bonus.c	display_map_bonus.c	player_movements_bonus.c	animations_bonus.c	\
							path_finding_bonus.c	path_finding_utils_bonus.c player_move_else_bonus.c	animation_str_bonus.c

OBJS					= $(SRC:%.c=$(DIR)%.o)
OBJS_BONUS				= $(SRC_BONUS:%.c=$(DIR_BONUS)%.o)

LIBFT					= libft.a
LIB_DIR					= lib/libft/

GCC						= cc
CFLAGS					= -Wall -Wextra -Werror

RM						= rm -rf

MINILIB					= libmlx.a
MINILIB_DIR				= lib/minilibx_macos/
MAC						= -framework OpenGL -framework AppKit

%.o:					$(DIR)%.c $(HEADER_DIR)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -O3 -c $< -o $@

all:					lib minilibx $(HEADER_DIR) $(NAME)

$(NAME):				$(OBJS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(OBJS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) ft_printf/libftprintf.a get_next_line/gnl.a $(MAC)

bonus:					${OBJS_BONUS} lib minilibx
						$(GCC) $(OBJS_BONUS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) ft_printf/libftprintf.a get_next_line/gnl.a $(MAC)

lib:
						@make -C $(LIB_DIR)
						@make -C get_next_line/
						@make -C ft_printf/


minilibx:
						@make -C $(MINILIB_DIR)

clean:
						@${RM} $(OBJS)
						@${RM} $(OBJS_BONUS)
						@make clean -C $(LIB_DIR)
						@make clean -C $(MINILIB_DIR)
						@make clean -C get_next_line/
						@make clean -C ft_printf/

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)
						@make fclean -C get_next_line/
						@make fclean -C ft_printf/

re:						fclean all
						$(MAKE) all
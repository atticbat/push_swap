# -*- MakeFile -*-

VPATH	=	bonus mandatory helper
NAME	=	push_swap
BNAME	=	checker
FUNCTS	=	push_swap.c push_operation.c \
			rotate_operation.c swap_operation.c user_friendly.c reindex.c \
			insertion_sort.c finished_checks.c find_index.c find_keys.c \
			insertion_sort_p2.c general_functions.c reinsertion_sort.c \
			get_move.c push_all.c longest_increasing_subsequence.c \
			parsing.c find_insertion_point.c get_weight.c find_path_to_top.c
BFUNCTS	=	get_next_line.c get_next_line_utils.c parsing.c finished_checks.c \
			swap_operation.c rotate_operation.c push_operation.c checker.c \
			general_functions.c user_friendly.c glossary.c append.c
LIBFTNAME =	ft
PTFNAME	=	ftprintf
PTFPATH	=	./ft_printf/
OBJS	=	$(addprefix $(OBJ_PATH),$(notdir $(FUNCTS:.c=.o)))
BOBJS	=	$(addprefix $(BOBJ_PATH),$(notdir $(BFUNCTS:.c=.o)))
CC		=	cc
CFLAGS	= 	-Wall -Werror -Wextra
OBJ_PATH =	./obj/
BOBJ_PATH =	./obj_bonus/
MLXPATH	=	./minilibx
LIBFTPATH =	./libft/
IFLAGS	=	-I ./includes
RM 		=	/bin/rm -f
RMR		=	/bin/rm -rf
DEPEND	=	-MMD -MP

all: $(NAME)

bonus: $(BNAME)

$(OBJ_PATH) :
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: %.c | $(OBJ_PATH)
	$(CC) $(CLFAGS) $(IFLAGS) $(DEPEND) -c $< -o $@

$(BOBJ_PATH) :
	mkdir $(BOBJ_PATH)

$(BOBJ_PATH)%.o: %.c | $(BOBJ_PATH)
	$(CC) $(CFLAGS) $(IFLAGS) $(DEPEND) -c $< -o $@

$(NAME): $(OBJ_PATH) $(OBJS)
	make -C $(LIBFTPATH)
	make -C $(PTFPATH)
	$(CC) -o $(NAME) $(IFLAGS) $(DEPEND) $(OBJS) -L $(PTFPATH) -l $(PTFNAME) \
		-L $(LIBFTPATH) -l $(LIBFTNAME)

$(BNAME): $(BOBJ_PATH) $(BOBJS)
	make -C $(LIBFTPATH)
	make -C $(PTFPATH)
	$(CC) -o $(BNAME) $(IFLAGS) $(DEPEND) $(BOBJS) -L $(PTFPATH) -l $(PTFNAME) \
		-L $(LIBFTPATH) -l $(LIBFTNAME)

clean:
	make clean -C $(LIBFTPATH)
	make clean -C $(PTFPATH)
	$(RMR) $(OBJ_PATH)
	$(RMR) $(BOBJ_PATH)

fclean: clean
	make fclean -C $(LIBFTPATH)
	make fclean -C $(PTFPATH)
	$(RM) $(NAME)
	$(RM) $(BNAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(OBJ_PATH):%.o=%.d

NAME			=	day5

SRC_DIR		=	./src/
OBJ_DIR		=	obj/

INCS_DIR	=	./includes
MAIN_INC	= -I $(INCS_DIR)
INCS		=	$(shell find $(INCS_DIR) -type f -name "*.hpp")

SRC			=	main.cpp   \
				
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC				=	clang++

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(INCS)
		@mkdir -p $(OBJ_DIR)
		$(CC) ${CFLAGS}  $(MAIN_INC) -o $@ -c $<

$(NAME)		:	$(OBJ) $(INCS)
		$(CC) $(CFLAGS) $(OBJ) $(MAIN_INC) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf $(OBJ_DIR)

fclean		:	clean
		@rm -rf $(NAME)

re			:	fclean	all

.PHONY		:	all clean fclean re
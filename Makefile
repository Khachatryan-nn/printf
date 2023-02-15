NAME			=	lbiftprintf.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs

SRCS			=	ft_printf_nmbs.c ft_printf_strs.c ft_printf.c
OBJS			=	$(SRCS:.c=.o)

# BONUS			=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c		\
# 				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
# BONUS_OBJS		=	$(BONUS:.c=.o)
.DEFAULT_GOAL	=	all
HEADER			= 	ft_printf.h
all:			$(NAME)

%.o:			%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@


$(NAME):		$(OBJS)
					$(AR) $(NAME) $?

# bonus:			$(BONUS_OBJS)
# 					$(AR) $(NAME) $?

clean:
					$(RM) $(OBJS) #$(BONUS_OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re #bonus

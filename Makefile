NAME			=	libftprintf.a
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs

LIBFT_P			=	libft
LIBFT			=	$(LIBFT_P)/libft.a
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

$(NAME):		$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME)
					$(AR) $(NAME) $?

$(LIBFT):
					make -C $(LIBFT_P) all

# bonus:			$(BONUS_OBJS)
# 					$(AR) $(NAME) $?

clean:
					make -C $(LIBFT_P) clean
					$(RM) $(OBJS)

fclean:			clean
					make -C $(LIBFT_P) fclean
					$(RM) $(NAME)

re:				fclean all

.PHONY:	all clean fclean re libft #bonus

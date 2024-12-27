CC = cc

CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_itoa.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
	ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_split.c \
	get_next_line.c get_next_line_utils.c

BONUS_CFILES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
	ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c \
	ft_lstiter_bonus.c ft_lstmap_bonus.c

#creates object files from the c files given
OFILES = $(CFILES:.c=.o)
BONUS_OFILES = $(BONUS_CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# all compiles all the c files into o files and archive them into libft.a
all: $(NAME)

#flags rcs: r adds o files to archive, c creates the archive if it doesnt exist yet, s for the index
$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

#does the same as the one up but for bonus
bonus: $(BONUS_OFILES)
	ar -rcs $(NAME) $(BONUS_OFILES)

#gets rid of all o files after creating application
clean:
	rm -f $(OFILES) $(BONUS_OFILES)

#removes o files and library
fclean: clean
	rm -f $(NAME)

#to rebuild the whole project after cleaning everything
re: fclean all

.PHONY: all clean re fclean

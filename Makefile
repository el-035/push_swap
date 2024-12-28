CC = cc

CFILES = push_swap.c utils.c struct_utils.c error.c rules.c \
		
FT_PRINTF_FILES = ft_printf/ft_printf.c ft_printf/ft_printmore.c ft_printf/ft_printstuff.c 
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

#creates object files from the c files given
OFILES = $(CFILES:.c=.o)

FT_PRINTF_OFILES = $(FT_PRINTF_FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

FT_PRINTF = -I./ft_printf

NAME = push_swap

# this sets the rule to compile all c files into o files $< is the prerequisite (aka the c files) and $@ is the target (aka the o files)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  

# all compiles all the c files into o files and archive them into libft.a
all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OFILES) $(FT_PRINTF_OFILES) $(LIBFT)
	$(CC) $(OFILES) $(FT_PRINTF_OFILES) $(LIBFT) -o $(NAME)

#gets rid of all o files after creating application
clean:
	rm -f $(OFILES) $(FT_PRINTF_OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

#removes o files and library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

#to rebuild the whole project after cleaning everything
re: fclean all

#tells make that all, clean, re, and fclean should always be treated as commands and not as files to be created.
.PHONY: all clean re fclean
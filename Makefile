# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fleblanc <fleblanc@student.42angoulem      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 15:21:28 by fleblanc          #+#    #+#              #
#    Updated: 2022/06/10 14:01:46 by fleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Names

SERVER		= server
#SERVER_B	= server_bonus
CLIENT		= client
#CLIENT_B	= client_bonus
LIBNAME		= libft.a

# **************************************************************************** #
# Compilation

CC		= gcc -ggdb
IFLAGS	= -I $(INCDIR) -I $(LIBDIR)/$(INCDIR)
WFLAGS	= -Wall -Wextra -Werror 

# **************************************************************************** #
# System commands

MAKE		= make -sC
MKDIR		= mkdir -p
NORMINETTE	= /usr/bin/norminette
NORMFLAG_C	= -R CheckForbiddenSourceHeader
NORMFLAG_H	= -R CheckDefine
RM			= rm -rf

# **************************************************************************** #
# Directories

INCDIR	= ./inc
LIBDIR	= libft
OBJDIR	= ./obj
SRCDIR	= ./src

# **************************************************************************** #
# List of sources files

SRC_CLIENT		= client.c 

SRC_SERVER		= server.c 

#SRC_CLIENT_B	= bonus/client_bonus.c

#SRC_SERVER_B	= bonus/server_bonus.c

# **************************************************************************** #
# Variables where are listed the names of sources and objects files

LFT		= $(addprefix $(LIBDIR)/, $(LIBNAME))
SRC_CL	= $(addprefix $(SRCDIR)/, $(SRC_CLIENT))
SRC_CLB	= $(addprefix $(SRCDIR)/, $(SRC_CLIENT_B))
SRC_SV	= $(addprefix $(SRCDIR)/, $(SRC_SERVER))
SRC_SVB	= $(addprefix $(SRCDIR)/, $(SRC_SERVER_B))
OBJ_CL	= $(addprefix $(OBJDIR)/, $(SRC_CLIENT:.c=.o))
OBJ_CLB	= $(addprefix $(OBJDIR)/, $(SRC_CLIENT_B:.c=.o))
OBJ_SV	= $(addprefix $(OBJDIR)/, $(SRC_SERVER:.c=.o))
OBJ_SVB	= $(addprefix $(OBJDIR)/, $(SRC_SERVER_B:.c=.o))

# **************************************************************************** #
# Extra

BASENAME	= `basename $(PWD)`
CR			= "\r"$(CLEAR)
CLEAR		= "\\033[0K"
EOC			= "\033[0;0m"
GREY		= "\033[0;30:"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"

# **************************************************************************** #
# Rules

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
		@$(MKDIR) $(dir $@)
		@$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@
		@printf $(CR)"[ $(BASENAME)/%s ]"$(CLEAR) $@

all: $(LFT) $(CLIENT) $(SERVER)

$(LFT):
		@$(MAKE) $(LIBDIR)

$(SERVER): $(LFT) $(OBJ_SV)
		@$(CC) $(WFLAGS) $(OBJ_SV) $(LFT) -o $(SERVER)
		@printf $(CR)$(GREEN)"✓ $(SERVER) is created\n"$(EOC)

$(CLIENT): $(LFT) $(OBJ_CL)
		@$(CC) $(WFLAGS) $(OBJ_CL) $(LFT) -o $(CLIENT)			
		@printf $(CR)$(GREEN)"✓ $(CLIENT) is created\n"$(EOC)

#$(SERVER_B): $(LFT) $(OBJ_SVB)
#		@$(CC) $(WFLAGS) $(OBJ_SVB) $(LFT) -o $(SERVER_B)
#		@mv $(SERVER_B) $(SERVER)
#		@printf $(CR)$(GREEN)"✓ $(SERVER_B) is created\n"$(EOC)

#$(CLIENT_B): $(LFT) $(OBJ_CLB)
#		@$(CC) $(WFLAGS) $(OBJ_CLB) $(LFT) -o $(CLIENT_B)
#		@mv $(CLIENT_B) $(CLIENT)
#		@printf $(CR)$(GREEN)"✓ $(CLIENT_B) is created\n"$(EOC)

clean:
		@if [ -d $(OBJDIR) ]; then \
			$(RM) $(OBJDIR) \
			&& printf $(CR)$(YELLOW)"✗ The objects files of $(CLIENT) " \
			&& printf "and $(SERVER) are cleaned\n"$(EOC)\
			&& $(MAKE) $(LIBDIR) clean; \
		fi

fclean:	clean
		@$(MAKE) $(LIBDIR) fclean
		@if [ -e $(CLIENT) ]; then \
			$(RM) $(CLIENT) \
			&& printf $(CR)$(RED)"✗ $(CLIENT) is cleaned\n"$(EOC); \
		fi
		@if [ -e $(SERVER) ]; then \
			$(RM) $(SERVER) \
			&& printf $(CR)$(RED)"✗ $(SERVER) is cleaned\n"$(EOC); \
		fi

re:		fclean all

#bonus: fclean $(LFT) $(CLIENT_B) $(SERVER_B)

norm:
		@$(NORMINETTE) $(NORMFLAG_C) $(SRCDIR) $(LIBDIR)/sources
		@$(NORMINETTE) $(NORMFLAG_H) $(INCDIR) $(LIBDIR)/includes

.PHONY: all clean fclean re norm #bonus

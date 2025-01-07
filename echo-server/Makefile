SERVER_PROGRAM = server
CLIENT_PROGRAM = client

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(CLIENT_PROGRAM) $(SERVER_PROGRAM)

clean:

fclean: clean
  rm -f $(SERVER_PROGRAM) $(CLIENT_PROGRAM)

re: fclean all

.PHONY: all clean fclean re
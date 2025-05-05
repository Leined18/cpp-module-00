NAME = phonebook
CPP = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98 -g3 -fsanitize=address -fno-inline 
FILES = main.cpp PhoneBook.cpp Contact.cpp Utils.cpp
HEADERS = PhoneBook.hpp Contact.hpp 
OBJDIR = obj


OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADERS)
	mkdir -p $(OBJDIR)
	$(CPP) $(CPPFLAGS) -I. -c $< -o $@

clean:
	@rm -rf $(NAME) $(OBJDIR)

fclean: clean

re: fclean all

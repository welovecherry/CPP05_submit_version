CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
Bureaucrat.cpp \
AForm.cpp \
PresidentialPardonForm.cpp \
RobotomyRequestForm.cpp \
ShrubberyCreationForm.cpp

OBJS = $(SRC:.cpp=.o)
NAME = ex02

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
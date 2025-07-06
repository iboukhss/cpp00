CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: phonebook

phonebook: main.o PhoneBook.o Contact.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f phonebook

re: fclean all

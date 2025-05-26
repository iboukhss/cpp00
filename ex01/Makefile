CXX = c++
CXXFLAGS = -Wall -Wextra -Werror --std=c++98

SRCS = test.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: phonebook

phonebook: $(OBJS)
	$(CXX) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o phonebook

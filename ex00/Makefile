CXX = c++
CXXFLAGS = -Wall -Wextra -Werror --std=c++98

all: megaphone

megaphone: megaphone.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f megaphone

re: fclean all

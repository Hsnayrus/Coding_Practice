CPPFLAGS= -Wall -Werror -pedantic -std=gnu++11 -ggdb3
solution: Solution.cpp myHeader.hpp
	g++ $(CPPFLAGS) -o solution Solution.cpp

.PHONY: clean
clean:
	rm -rf *~ *.dSYM* solution *.cpp~ *.hpp~

CC = g++
FLAGS = -std=c++11 -Wall -Wno-sign-compare -Wno-unused-result -g
FILES = ~/Documents/oop/lab_4/*.cpp
PROG = run
TFILES = TListItem.cpp TList.cpp test.cpp

all:
	$(CC) $(FLAGS) -o $(PROG) $(FILES)

clean:
	rm -f *.o run
test:
	$(CC) $(FLAGS) -o test $(TFILES)

# Makefile for priority queue template class

#target: dependencies
#	command to create the target

CPPOPTIONS = -Wall -g

all: test_rbtree #test_dict #imdb

test_rbtree.o: test_rbtree.cpp rbtree.h rbtree.cpp
	g++ $(CPPOPTIONS) -c test_rbtree.cpp

test_rbtree: test_rbtree.o
	g++ $(CPPOPTIONS) -o test_rbtree test_rbtree.o
#
# test_dict.o: test_dict.cpp dict.h rbtree.h rbtree.cpp dict.cpp
# 	g++ $(CPPOPTIONS) -c test_dict.cpp
#
# test_dict: test_dict.o
# 	g++ $(CPPOPTIONS) -o test_dict test_dict.o
#
# imdb.o: imdb.cpp dict.h dict.cpp rbtree.h rbtree.cpp
# 	g++ $(CPPOPTIONS) -c imdb.cpp
#
# imdb: imdb.o
# 	g++ $(CPPOPTIONS) -o imdb imdb.o


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a

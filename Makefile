main: main.o knights.o 
	g++ -o main main.o knights.o 

main.o: main.cpp

knights.o: knights.cpp

clean: 
	rm -f *.o  main
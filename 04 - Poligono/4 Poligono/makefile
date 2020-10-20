poligono: poligonoMain.o poligono.o
	g++ -o poligono poligonoMain.o poligono.o 

poligonomain.o: poligonoMain.cpp poligono.h
	g++ -c poligonoMain.cpp

poligono.o: poligono.cpp poligono.h
	g++ -c poligono.cpp

clean:
	rm *.o poligono
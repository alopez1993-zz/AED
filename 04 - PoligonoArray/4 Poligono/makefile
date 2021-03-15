poligonoarray: poligonoarraytest.o poligonoarray.o
	g++ -o poligonoarray poligonoarraytest.o poligonoarray.o 

poligonoarraytest.o: poligonoarraytest.cpp poligonoarray.h
	g++ -c oligonoarraytest.cpp

poligonoarray.o: poligonoarray.cpp poligonoarray.h
	g++ -c poligonoarray.cpp

clean:
	rm *.o poligono
aceite:	main.o abastecedor.o trabajador.o sirviente.o robot.o
	g++ main.o abastecedor.o trabajador.o sirviente.o robot.o -o aceite

main.o: main.cpp abastecedor.h trabajador.h sirviente.h robot.h
	g++ -c main.cpp

abastecedor.o:	abastecedor.cpp abastecedor.h robot.h
	g++ -c abastecedor.cpp

trabajador.o:	trabajador.cpp trabajador.h robot.h
	g++ -c trabajador.cpp

sirviente.o:	sirviente.cpp sirviente.h robot.h
	g++ -c sirviente.cpp

robot.o:	robot.cpp robot.h
	g++ -c robot.cpp
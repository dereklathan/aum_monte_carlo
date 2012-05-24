work : tester.o cube.o Atom.o infile_reader.o outfile_writer.o sim_actions.o 
	gcc tester.o cube.o Atom.o infile_reader.o outfile_writer.o sim_actions.o -o work

tester.o : tester.cpp
	gcc -c tester.cpp

cube.o : cube.cpp cube.h
	gcc -c cube.cpp

Atom.o : Atom.cpp Atom.h
	gcc -c Atom.cpp

infile_reader.o : infile_reader.cpp infile_reader.h
	gcc -c infile_reader.cpp

outfile_writer.o : outfile_writer.cpp outfile_writer.h
	gcc -c outfile_writer.cpp

sim_actions.o : sim_actions.cpp
	gcc -c sim_actions.cpp

clean : 
	rm *.o

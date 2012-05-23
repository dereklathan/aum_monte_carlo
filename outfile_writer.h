#ifndef OUTFILE_WRITER_H
#define OUTFILE_WRITER_H
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "infile_reader.h"
#include "cube.h"
#include "Atom.h"

class outfile_writer{
	private:
		ofstream outfile;
	public:
		outfile_writer(){};
		//default constructor
		outfile_writer(string);
		//constructor. string is vtf filename for output.
		void open_file(string);
		//opens output file for writing
		void close_file();
		//closes output file
		void define_atoms(list<Atom>);
		//defines all atoms in list<Atom>
		void set_initial_positions(Cube,list<Atom>);
		//sets initial positions of atoms and unitcell params
		void add_timestep(list<Atom>);
		//increments one timestep
};
#endif

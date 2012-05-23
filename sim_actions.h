#ifndef SIM_ACTIONS_H
#define SIM_ACTIONS_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Atom.h"
#include "cube.h"
#include "infile_reader.h"
#include "outfile_writer.h"
using namespace std;

class sim_actions{
	private:
		outfile_writer writer;
		list<Atom> atomlist;
	public:
		sim_actions(string);
		//constructor seeds random number generator opens file for outfile_writer
		list<Atom> fill_cube(Cube, float);
		//fills cube according to percentage to fill and returns list of atoms added to cube
		void add_timestep(Cube, list<Atom>);

};
#endif

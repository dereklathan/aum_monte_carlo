#ifndef SIM_ACTIONS_H
#define SIM_ACTIONS_H
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Atom.h"
#include "cube.h"
#include "infile_reader.h"
using namespace std;

class sim_actions{
	public:
		sim_actions();
		//constructor seeds random number generator
		list<Atom> fill_cube(Cube, float);
		//fills cube according to percentage to fill and returns list of atoms added to cube
		void add_timestep(Cube, list<Atom>);

};
#endif

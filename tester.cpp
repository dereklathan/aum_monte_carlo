#include "Atom.h"
#include "cube.h"
#include "infile_reader.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include "sim_actions.h"
using namespace std;

int main(){
	Infile_reader reader("infile");
	Cube c;
	reader.setData();
	c.set_domain(reader.getunitcellsize()[0], reader.getunitcellsize()[1], reader.getunitcellsize()[2]);
	sim_actions action(reader.getoutfilename());
	list<Atom> atomlist = action.fill_cube(c, reader.getpercentdomainfill());
	for(int d=0; d<reader.gettimesteps(); d++)
		action.add_timestep(c, atomlist);
	action.close_writer();
	return 0;
}

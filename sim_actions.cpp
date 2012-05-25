#include "sim_actions.h"
using namespace std;

sim_actions::sim_actions(string filename){
	srand(time(NULL));
	writer.open_file(filename);
}

list<Atom> sim_actions::fill_cube(Cube cube, float percent_to_fill){
	int cubevolume = cube.get_domain_x() * cube.get_domain_y() * cube.get_domain_z();
	Atom atom("0.5");
	int x=rand()%cube.get_domain_x();
	int y=rand()%cube.get_domain_y();
	int z=rand()%cube.get_domain_z();
	atom.set_x_pos(x);
	atom.set_y_pos(y);
	atom.set_z_pos(z);
	for(int c=0;c < (cubevolume * (percent_to_fill/100));c++){
		atomlist.push_back(atom);
		cube.set_occupy_space(x,y,z,true);
		while(cube.get_occupy_space(x,y,z)){
			x=rand()%cube.get_domain_x();
			y=rand()%cube.get_domain_y();
			z=rand()%cube.get_domain_z();
		}
		atom.set_x_pos(x);
		atom.set_y_pos(y);
		atom.set_z_pos(z);
	}	
	writer.define_atoms(atomlist);
	writer.set_initial_positions(cube, atomlist);
	writer.close_file();
	return atomlist;
}


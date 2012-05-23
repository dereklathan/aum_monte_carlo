#include "sim_actions.h"
using namespace std;

sim_actions::sim_actions(){
	srand(time(NULL));
}

list<Atom> sim_actions::fill_cube(Cube cube, float percent_to_fill){
	list<Atom> atomlist;
	float cubevolume = cube.get_domain_x() * cube.get_domain_y() * cube.get_domain_z();
	Atom atom(0.5);
	float atomvolume = (4/3) * 3.1459 * atom.getradius() * atom.getradius() * atom.getradius();
	int x,y,z;
	float totalvolume = 0;
	while(totalvolume + atomvolume <= cubevolume * (percent_to_fill/100)){
		atomlist.push_back(atom);

	}	
	
}

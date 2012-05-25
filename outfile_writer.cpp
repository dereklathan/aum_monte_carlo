#include "outfile_writer.h"
#include <cstring>
using namespace std;

outfile_writer::outfile_writer(string filename){
	outfile.open(filename.c_str(), ios::out);
}

void outfile_writer::open_file(string filename){
	outfile.open(filename.c_str(), ios::out);
}

void outfile_writer::close_file(){
	outfile.close();
}

void outfile_writer::define_atoms(list<Atom> atomlist){
	list<Atom>::iterator it = atomlist.begin();

	for(int c=0;c<atomlist.size();c++){
		outfile << "Atom " << c << "\tradius " << it->get_radius() << endl;
		++it;
	}
}

void outfile_writer::set_initial_positions(Cube c, list<Atom> atomlist){
	list<Atom>::iterator it = atomlist.begin();
	outfile << "timestep ordered\npbc " << c.get_domain_x() << ".0 " << c.get_domain_y() << ".0 ";
	outfile << c.get_domain_z() << ".0\n";
	for(int c=0;c<atomlist.size();c++){
		outfile << it->get_x_pos() << ".0 " << it->get_y_pos() << ".0 " << it->get_z_pos() << ".0\n";
		it++;
	}
}

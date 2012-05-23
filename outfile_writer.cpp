#include "outfile_writer.h"
using namespace std;

outfile_writer::outfile_writer(string filename){
	outfile.open(filename);
}

void outfile_writer::open_file(string filename){
	outfile.open(filename);
}

void outfile_writer:close_file(){
	outfile.close();
}

void outfile_writer::define_atoms(list<Atom> atomlist){
	list<Atom>::iterator it = atomlist.begin();
	for(int c=0;c<atomlist.size();c++){
		outfile << "Atom " << c << "\tradius " << *it.get_radius() << endl;
	}
}

#include <"timestep_graph_writer.h">
using namespace std;

void timestep_graph_writer::write_timestep_graph_x(string vtf_filename, Cube cube, list<Atom> atomlist, int timestep_number){
	int layer_atom_count;
	stringstream convert;
	string timestep_number_string;
	convert << timestep_number;	
	timestep_number_string = convert.str();
	for(int c=timestep_number_string.size();c<5;c++)
		timestep_number_string.insert(0,"0");
	ofstream outfile;
	list<Atom>::iterator it;
	outfile.open("graphs/" + vtf_filename + "_x_" + timestep_number_string);
	for(int c=0;c<cube.get_domain_z;c++){
		layer_atom_count=0;
		it=atomlist.begin();
		for(int d=0;d<atomlist.size();d++){
			if(it->get_x_pos()==c)
				layer_atom_count++;
		}
		outfile << c << " " << layer_atom_count << endl;
	}
	outfile.close();	
}

void timestep_graph_writer::write_timestep_graph_y(string vtf_filename, Cube cube, list<Atom> atomlist, int timestep_number){
	int layer_atom_count;
	stringstream convert;
	string timestep_number_string;
	convert << timestep_number;	
	timestep_number_string = convert.str();
	for(int c=timestep_number_string.size();c<5;c++)
		timestep_number_string.insert(0,"0");
	ofstream outfile;
	list<Atom>::iterator it;
	outfile.open("graphs/" + vtf_filename + "_y_" + timestep_number_string);
	for(int c=0;c<cube.get_domain_z;c++){
		layer_atom_count=0;
		it=atomlist.begin();
		for(int d=0;d<atomlist.size();d++){
			if(it->get_y_pos()==c)
				layer_atom_count++;
		}
		outfile << c << " " << layer_atom_count << endl;
	}
	outfile.close();	
}

void timestep_graph_writer::write_timestep_graph_z(string vtf_filename, Cube cube, list<Atom> atomlist, int timestep_number){
	int layer_atom_count;
	stringstream convert;
	string timestep_number_string;
	convert << timestep_number;	
	timestep_number_string = convert.str();
	for(int c=timestep_number_string.size();c<5;c++)
		timestep_number_string.insert(0,"0");
	ofstream outfile;
	list<Atom>::iterator it;
	outfile.open("graphs/" + vtf_filename + "_z_" + timestep_number_string);
	for(int c=0;c<cube.get_domain_z;c++){
		layer_atom_count=0;
		it=atomlist.begin();
		for(int d=0;d<atomlist.size();d++){
			if(it->get_z_pos()==c)
				layer_atom_count++;
		}
		outfile << c << " " << layer_atom_count << endl;
	}
	outfile.close();	
}

#ifndef TIMESTEP_GRAPH_WRITER_H
#define TIMESTEP_GRAPH_WROTER_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <"cube.h">
#include <"Atom.h">
using namespace std;

class timestep_graph_writer{

	public:
		timestep_graph_writer(){};
		//constructor
		void write_timestep_graph_x(string, list<Atom>, int);
		//creates graph for xmgrace of number of particles in layer vs layer number for a timestep
		//along x axis. string is the vtf filename, list<Atom> is list of atoms, int is timestep number
		void write_timestep_graph_y(string, list<Atom>, int);
		//creates graph for xmgrace of number of particles in layer vs layer number for a timestep
		//along y axis. string is the vtf filename, list<Atom> is list of atoms, int is timestep number
		void write_timestep_graph_z(string, list<Atom>, int);
		//creates graph for xmgrace of number of particles in layer vs layer number for a timestep
		//along z axis. string is the vtf filename, list<Atom> is list of atoms, int is timestep number


}
#endif

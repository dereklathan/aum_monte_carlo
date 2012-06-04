#ifndef ATOM_H
#define ATOM_H
#include <iostream>
#include <string>
using namespace std;

class Atom{
	private:
		unsigned int x_pos, y_pos, z_pos;
		unsigned int mass;
		unsigned int grav_pot_energy;
		unsigned int internal_pot_energy;
		bool attempted;
		string radius;
		int j;

	public:
		Atom(string, unsigned int);
		//constructor
		void set_x_pos(unsigned int);
		//sets x coordinate of atom center
		void set_y_pos(unsigned int);
		//sets y coordinate of atom center
		void set_z_pos(unsigned int);
		//sets z coordinate of atom center
		unsigned int get_x_pos();
		//gets x coordinate of atom center
		unsigned int get_y_pos();
		//gets y coordinate of atom center
		unsigned int get_z_pos();
		//gets z coordinate of atom center
		void set_grav_pot_energy();
		unsigned int get_grav_pot_energy();
		void set_j(int);
		//sets j value
		int get_j();
		//returns j value
		void set_attempted(bool);
		//if attempt to move has been made for timestep, should be true. false otherwise
		bool get_attempted();
		//returns true if attempt has been made, false otherwise
		string get_radius();
		
};

#endif

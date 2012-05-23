#ifndef ATOM_H
#define ATOM_H
#include <iostream>
using namespace std;

class Atom{
	private:
		int x_pos, y_pos, z_pos;
		bool attempted;
		float radius;
	public:
		Atom(float);
		//constructor
		void set_x_pos(int);
		//sets x coordinate of atom center
		void set_y_pos(int);
		//sets y coordinate of atom center
		void set_z_pos(int);
		//sets z coordinate of atom center
		int get_x_pos();
		//gets x coordinate of atom center
		int get_y_pos();
		//gets y coordinate of atom center
		int get_z_pos();
		//gets z coordinate of atom center
		void set_attempted(bool);
		//if attempt to move has been made for timestep, should be true. false otherwise
		bool get_attempted();
		//returns true if attempt has been made, false otherwise
		float get_radius();
};

#endif

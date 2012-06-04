#include "Atom.h"
using namespace std;

Atom::Atom(string atom_radius, unsigned int atom_mass){
	radius = atom_radius;
	mass = atom_mass;
	attempted = false;
}

void Atom::set_x_pos(unsigned int x){
	x_pos=x;
}

void Atom::set_y_pos(unsigned int y){
	y_pos=y;
}

void Atom::set_z_pos(unsigned int z){
	z_pos=z;
}

unsigned int Atom::get_x_pos(){
	return x_pos;
}

unsigned int Atom::get_y_pos(){
	return y_pos;
}

unsigned int Atom::get_z_pos(){
	return z_pos;
}

void Atom::set_grav_pot_energy(){
	grav_pot_energy = mass * get_z_pos();
}

unsigned int Atom::get_grav_pot_energy(){
	return grav_pot_energy;
}

void Atom::set_attempted(bool hasattempted){
	attempted=hasattempted;
}

bool Atom::get_attempted(){
	return attempted;
}

string Atom::get_radius(){
	return radius;
}

void Atom::set_j(int j_val){
	j=j_val;
}

int Atom::get_j(){
	return j;
}





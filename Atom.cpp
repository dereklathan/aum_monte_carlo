#include "Atom.h"
using namespace std;

Atom::Atom(string atom_radius){
	radius = atom_radius;
	attempted = false;
}

void Atom::set_x_pos(int x){
	x_pos=x;
}

void Atom::set_y_pos(int y){
	y_pos=y;
}

void Atom::set_z_pos(int z){
	z_pos=z;
}

int Atom::get_x_pos(){
	return x_pos;
}

int Atom::get_y_pos(){
	return y_pos;
}

int Atom::get_z_pos(){
	return z_pos;
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





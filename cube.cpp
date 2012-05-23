#include "cube.h"
#include <iostream>
using namespace std;

Cube::Cube(){}

void Cube::set_domain(int x, int y, int z){
	domain_x=x;
	domain_y=y;
	domain_z=z;
	atomlocation = new bool**[x+1];
	for(int c=0;c<=x;c++){
		atomlocation[c] = new bool*[y+1];
	}
	for(int c=0;c<=x;c++){
		for(int d=0;d<=y;d++)
			atomlocation[c][d] = new bool[z+1];
	}

	for(int c=0;c<=x;c++){
		for(int d=0;d<=y;d++){
			for(int e=0;e<=z;e++)
				atomlocation[c][d][e]=0;
		}
	}	
}

int Cube::get_domain_x(){
	return domain_x;
}

int Cube::get_domain_y(){
	return domain_y;
}

int Cube::get_domain_z(){
	return domain_z;
}

void Cube::set_occupy_space(int x, int y, int z, bool occupied){
	atomlocation[x][y][z]=occupied;
}

bool Cube::get_occupy_space(int x, int y, int z){
	if(atomlocation[x][y][z]==1)
		return true;
	else
		return false;
}


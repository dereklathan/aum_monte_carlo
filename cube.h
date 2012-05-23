#ifndef CUBE_H
#define CUBE_H
#include <iostream>

class Cube{
	private:
		bool *** atomlocation;
		int domain_x, domain_y, domain_z;
	public:		
		Cube();
		//constructor
		
		void set_domain(int, int, int);
		//sets size of cube

		int get_domain_x();
		//returns length of x axis
		int get_domain_y();
		//returns length of y axis
		int get_domain_z();
		//returns length of z axis
		void set_occupy_space(int, int, int, bool);
		//given x,y,z coordinates respectively, sets space occupied(true) or vacant(false)
		bool get_occupy_space(int, int, int);
		//checks if a space is occupied given x,y,z coordinates respectively
};
#endif

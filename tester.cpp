#include "Atom.h"
#include "cube.h"
#include "infile_reader.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
using namespace std;

int main(){
	Atom a;
	Cube c;
	Infile_reader reader("infile");
	reader.setData();
	c.set_domain(reader.getunitcellsize()[0], reader.getunitcellsize()[1], reader.getunitcellsize()[2]);
	cout << c.get_domain_x();
	
	return 0;
}

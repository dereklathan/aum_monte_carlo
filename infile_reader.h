#ifndef INFILE_READER_H
#define INFILE_READER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Infile_reader{
	private:
		ifstream reader;
		string outfilename;
		int unitcellsize[3];
		float percentdomainfill;
		int timesteps;
		int graph_interval;
	public:
		Infile_reader();
		//default constructor
		Infile_reader(string);
		//constructor. string is filename to be read
		void setData();
		//sets data based on input file
		string getoutfilename();
		//returns string for output vtf filename
		int* getunitcellsize();
		//returns array containing x,y,z params for unit cell respectively
		float getpercentdomainfill();
		//returns percentage of domain to fill with atoms
		int gettimesteps();
		//returns number of timesteps 	
		int get_graph_interval();		
};
#endif

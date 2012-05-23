#include "infile_reader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Infile_reader::Infile_reader(string filename){
	reader.open(filename.c_str(), ifstream::in);	
}

void Infile_reader::setData(){
	outfilename="";
	while(reader.peek()!='#')
		outfilename += (char)reader.get();
	outfilename += ".vtf";
	while(reader.peek()!='\n')
		reader.get();
	for(int c=0;c<3;c++)
		reader >> unitcellsize[c];
	while(reader.peek()!='\n')
		reader.get();
	reader >> percentdomainfill;
	while(reader.peek()!='\n')
		reader.get( );
	reader >> timesteps;
	reader.close();
}

int* Infile_reader::getunitcellsize(){
	int* pointer = unitcellsize;
	return pointer;
}

float Infile_reader::getpercentdomainfill(){return percentdomainfill;}

int Infile_reader::gettimesteps(){return timesteps;}

string Infile_reader::getoutfilename(){return outfilename;}

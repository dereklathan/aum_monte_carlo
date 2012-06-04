#include "sim_actions.h"
using namespace std;

sim_actions::sim_actions(string filename){
	srand(time(NULL));
	writer.open_file(filename);
}

void sim_actions::close_writer(){
	writer.close_file();
}

list<Atom> sim_actions::fill_cube(Cube &cube, float percent_to_fill){
	int cubevolume = cube.get_domain_x() * cube.get_domain_y() * cube.get_domain_z();
	Atom atom("0.5", 1);
	int x=rand()%cube.get_domain_x();
	int y=rand()%cube.get_domain_y();
	int z=rand()%cube.get_domain_z();
	atom.set_x_pos(x);
	atom.set_y_pos(y);
	atom.set_z_pos(z);
	for(int c=0;c < (cubevolume * (percent_to_fill/100));c++){
		atomlist.push_back(atom);
		cube.set_occupy_space(x,y,z,true);
		while(cube.get_occupy_space(x,y,z)){
			x=rand()%cube.get_domain_x();
			y=rand()%cube.get_domain_y();
			z=rand()%cube.get_domain_z();
		}
		atom.set_x_pos(x);
		atom.set_y_pos(y);
		atom.set_z_pos(z);
	}	
	writer.define_atoms(atomlist);
	writer.write_timestep(cube, atomlist);
	return atomlist;
}

void sim_actions::add_timestep(Cube &cube, list<Atom> &atomlist){
	list<Atom>::iterator it;
	int rand_atom_index;
	int rand_axis;
	int rand_dir;
	while(!sim_actions::all_attempted(atomlist)){
		it=atomlist.begin();
		rand_atom_index=rand()%atomlist.size();
		rand_axis=rand()%3;
		rand_dir=rand()%2;
		for(int c=0;c<rand_atom_index;c++)
			it++;
		if(rand_axis==0 && !it->get_attempted()){
			if(rand_dir==0 && it->get_x_pos()==cube.get_domain_x()-1 && !cube.get_occupy_space(0,it->get_y_pos(), it->get_z_pos()))
			{
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(0, it->get_y_pos(), it->get_z_pos(), true);
				it->set_x_pos(0);
			}
			else if(rand_dir==0 && it->get_x_pos()+1<cube.get_domain_x() && !cube.get_occupy_space(it->get_x_pos()+1, it->get_y_pos(), it->get_z_pos())){
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos()+1, it->get_y_pos(), it->get_z_pos(), true);
				it->set_x_pos(it->get_x_pos()+1);
			}
			else if(rand_dir==1 && it->get_x_pos()==0 && !cube.get_occupy_space(cube.get_domain_x()-1, it->get_y_pos(), it->get_z_pos()))
			{
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(cube.get_domain_x()-1, it->get_y_pos(), it->get_z_pos(), true);
				it->set_x_pos(cube.get_domain_x()-1);
			}
			else if(rand_dir==1 && it->get_x_pos()>0 && !cube.get_occupy_space(it->get_x_pos()-1, it->get_y_pos(),it->get_z_pos())){
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos()-1, it->get_y_pos(), it->get_z_pos(), true);
				it->set_x_pos(it->get_x_pos()-1);
			}
		}	
		else if(rand_axis==1 && !it->get_attempted()){
			if(rand_dir==0 && it->get_y_pos()==cube.get_domain_y()-1 && !cube.get_occupy_space(it->get_x_pos(), 0, it->get_z_pos()))
			{
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), 0, it->get_z_pos(), true);
				it->set_y_pos(0);
			}
			else if(rand_dir==0 && it->get_y_pos()+1<cube.get_domain_y() && !cube.get_occupy_space(it->get_x_pos(), it->get_y_pos()+1, it->get_z_pos())){
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos()+1, it->get_z_pos(), true);
				it->set_y_pos(it->get_y_pos()+1);
			}
			else if(rand_dir==1 && it->get_y_pos()==0 && !cube.get_occupy_space(it->get_x_pos(), cube.get_domain_y()-1, it->get_z_pos()))
			{
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), cube.get_domain_y()-1, it->get_z_pos(), true);
				it->set_y_pos(cube.get_domain_y()-1);
			}
			else if(rand_dir==1 && it->get_y_pos()>0 && !cube.get_occupy_space(it->get_x_pos(), it->get_y_pos()-1,it->get_z_pos())){
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos()-1, it->get_z_pos(), true);
				it->set_y_pos(it->get_y_pos()-1);
			}
		}
		else if(rand_axis==2 && !it->get_attempted()){
			if(rand_dir==0 && it->get_z_pos()==cube.get_domain_z()-1 && !cube.get_occupy_space(it->get_x_pos(), it->get_y_pos(), 0))
			{
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), 0, true);
				it->set_z_pos(0);
			}
			else if(rand_dir==0 && it->get_z_pos()+1<cube.get_domain_z() && !cube.get_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos()+1)){
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos()+1, true);
				it->set_z_pos(it->get_z_pos()+1);
			}
			else if(rand_dir==1 && it->get_z_pos()==0 && !cube.get_occupy_space(it->get_x_pos(), it->get_y_pos(), cube.get_domain_z()-1))
			{
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), cube.get_domain_z()-1, true);
				it->set_z_pos(cube.get_domain_z()-1);
			}
			else if(rand_dir==1 && it->get_z_pos()>0 && !cube.get_occupy_space(it->get_x_pos(), it->get_y_pos(),it->get_z_pos()-1)){
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos(), false);
				cube.set_occupy_space(it->get_x_pos(), it->get_y_pos(), it->get_z_pos()-1, true);
				it->set_z_pos(it->get_z_pos()-1);
			}
		}
		it->set_attempted(true);
	}
	it=atomlist.begin();
	for(int c=0;c<atomlist.size();c++){
		it->set_attempted(false);
		it++;
	}
	writer.write_timestep(cube, atomlist);
}

bool sim_actions::all_attempted(list<Atom> atomlist){
	for(list<Atom>::iterator it = atomlist.begin(); it != atomlist.end();++it){
		if(!it->get_attempted())
			return false;
	}
	return true;
	
}

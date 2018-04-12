//Queen 912602059
//Domain.cpp

#include "Domain.h"
#include "Shape.h"
#include <list>
#include <iostream>
#include <stdexcept>
using namespace std;

Domain::Domain(int sx, int sy) : size_x(sx), size_y(sy){}

void Domain::addShape(char type, int x, int y){
	//type is the type of shape
	//checks if shape fits - if it doesnt then return (use fits function)
	//free space taken up by that shape?
	//if it fits and does not overlap with shapes in the domain already
	//- create the shape and add it to the domain

	Shape *newshape;
	newshape = Shape::makeShape(type, x, y);

	if (this->fits(*newshape) == true) {

		if ((int)sList.size() == 0) {
			sList.push_back(newshape);
		}
		else{
			for (int i = 0; i < (int)sList.size(); ++i) {
			//for every shape in the list
				if (newshape->overlap(*sList[i]) == true) {
					return;
				} 
			}
			sList.push_back(newshape);
		}
	}
		
	else { 
		//cout << "im deleting the shape" << endl;
		delete newshape;
		return;
	}
}
	
	

bool Domain::fits(const Shape &s) const{
	//returns true if shape s fits inside domain
	//coordinates of all its cells (for loop) satisfy x>=0, x < size_x, y >=0, y < size_y

	for (int i = 0; i < s.size(); i++){ //I size = 2
		if ((s.getX(i) >= 0) && (s.getX(i) < size_x)){
			if ((s.getY(i) >= 0) && (s.getY(i) < size_y)){
				//return true;
				continue;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	return true;
}

void Domain::draw(void) const{

	//fix formatting so each info column is aligned

	cout << "<?xml version=\"1.0\" encoding=\"utf-8\"  standalone=\"no\"?>" << endl << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" <<
	endl << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << endl 
	<< "<svg width=\"670\" height=\"670\" viewBox=\"0 0 650 650\"" << endl << "xmlns=\"http://www.w3.org/2000/svg\"" << endl << "xmlns:xlink=\"http://www.w3.org/1999/xlink\" >" << endl << "<g transform=\"matrix(1,0,0,-1,50,650)\">" << endl;
	

	cout << "<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\"  width=\"" << (size_x * 40) << //2 spaces to fit formatting
    "\" height=\"" << (size_y * 40) << "\"/>" << endl;

	//call each shape's draw function
	for (int i = 0; i < (int)sList.size(); ++i){
		sList[i]->draw(); //free space
	}

	cout << "</g>" << endl;
	cout << "</svg>" << endl;

	/*for (int i = 0; (int)sList.size(); ++i){
		delete sList[i];
	}*/
}

bool Domain::full(void) const{
	//returns true if the domain is full
	//if sum of all the sizes of the shapes present in the 
	//domain is equal to the total number of cells

	int count = 0;

	for (int i = 0; i < (int)sList.size(); ++i){ //go through whole list
		count += sList[i]->size();
		//cout << "count = " << count << endl;
	}	

	if (count >= (size_x * size_y)) {
		return true;
	}
	else{
		return false;
	}
}
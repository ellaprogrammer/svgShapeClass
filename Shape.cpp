//Queen 912602059
//Shape.cpp


#include "Shape.h"
#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;

Shape::~Shape(void){
    delete x;
    delete y;
}

void Shape::draw(void) const{
    
    //char colordraw[] = " ";
    //strcpy(colordraw, this->color());

    
    //cout << "<rect fill=\"" << this->color() << "\" stroke=\"black\" x=\"" 
    //<< (getX(0) * 40) << "\" y=\"" << (getY(0) * 40) << "\" width=\"40\" height=\"40\"/>" << endl;

    for (int i = 0; i < this->size(); i++){
        cout << "<rect fill=\"" << this->color() << "\" stroke=\"black\" x=\"" 
        << (getX(i) * 40) << "\" y=\"" << (getY(i) * 40) << "\" width=\"40\" height=\"40\"/>" << endl;
    }

}

void Shape::print(void) const {
    cout << this->name() << ' '; 
    cout << "at ";

    for (int i = 0; i < (this->size() - 1); ++i){
        cout << "(" << x[i] << "," << y[i] << ") ";
    }

    cout << "(" << x[this->size() - 1] << "," << y[this->size() - 1] << ")";

    cout << endl;

}

void Shape::move(int dx, int dy) {
    
    for (int i = 0; i < this->size(); ++i){
        this->x[i] += dx;
        this->y[i] += dy;
    }
}

bool Shape::overlap(const Shape &t) const {
    //return true if there is overlap
    for (int i = 0; i < this->size(); ++i){
        for (int j = 0; j < t.size(); ++j){
            //cout << this->x[i] << "and " << this->y[j] << "other one: " << t.x[i] << "and " << t.y[j] << endl;
            if ((this->getX(i) == t.x[j]) && (this->getY(i) == t.y[j])){
                //cout << "im in overlap checking condition" << endl;
                return true;
            }
            else {
                continue;
            }
        }
    } 

    return false;
}

Shape *Shape::makeShape(char ch, int posx, int posy) {

    if (ch == 'O') return new O(posx,posy);
    if (ch == 'I') return new I(posx,posy);
    if (ch == 'L') return new L(posx,posy);
    if (ch == 'S') return new S(posx,posy);
    if (ch == 'X') return new X(posx,posy);
    if (ch == 'U') return new U(posx,posy);
    else{
        throw invalid_argument("invalid type");
    }
}

int Shape::getX(int i) const {
    //cout << "x value is: " << this->x[i] << endl;
    return this->x[i];
}
int Shape::getY(int i) const{
    //cout << "y value is: " << this->y[i] << endl;
    return this->y[i];
}

O::O(int posx, int posy){
    //create array

    x = new int [1]();
    y = new int [1]();

    x[0] = posx;
    y[0] = posy;

}
char O::name(void) const{
    return 'O';
}
int O::size(void) const {
    return 1;
}
const char* O::color(void) const {
    char str[] = "cyan";
    char* tempptr = str;
    return tempptr;
}


I::I(int posx, int posy){
    //create array

    x = new int[2]();
    y = new int[2]();

    x[0] = posx;
    y[0] = posy;
    x[1] = posx;
    y[1] = posy + 1;
}
char I::name(void) const{
    return 'I';
}
int I::size(void) const {
    return 2;
}

const char* I::color(void) const {
    char str[] = "yellow";
    char* tempptr = str;
    return tempptr;
}


L::L(int posx, int posy){
    //create array

    x = new int[3]();
    y = new int[3]();

    x[0] = posx;
    y[0] = posy;
    x[1] = posx + 1;
    y[1] = posy;
    x[2] = posx;
    y[2] = posy + 1;

}
char L::name(void) const{
    return 'L';
}
int L::size(void) const {
    return 3;
}

const char* L::color(void) const {
    char str[] = "purple";
    char* tempptr = str;
    return tempptr;
}


S::S(int posx, int posy){
    //create array

    x = new int[4]();
    y = new int[4]();

    x[0] = posx;
    y[0] = posy;
    x[1] = posx + 1;
    y[1] = posy;
    x[2] = posx + 1;
    y[2] = posy + 1;
    x[3] = posx + 2;
    y[3] = posy + 1;
}
char S::name(void) const{
    return 'S';
}
int S::size(void) const {
    return 4;
}

const char* S::color(void) const {
    char str[] = "blue";
    char* tempptr = str;
    return tempptr;
}


X::X(int posx, int posy){
    //create array

    x = new int[5]();
    y = new int[5]();

    x[0] = posx;
    y[0] = posy;
    x[1] = posx - 1;
    y[1] = posy + 1;
    x[2] = posx;
    y[2] = posy + 1;
    x[3] = posx + 1;
    y[3] = posy + 1;
    x[4] = posx;
    y[4] = posy + 2;
}
char X::name(void) const{
    return 'X';
}
int X::size(void) const {
    return 5;
}

const char* X::color(void) const {
    char str[] = "orange";
    char* tempptr = str;
    return tempptr;
}

U::U(int posx, int posy){
    //create array
    x = new int[7]();
    y = new int[7]();

    x[0] = posx;
    y[0] = posy;
    x[1] = posx + 1;
    y[1] = posy;
    x[2] = posx + 2;
    y[2] = posy;
    x[3] = posx;
    y[3] = posy + 1;
    x[4] = posx + 2;
    y[4] = posy + 1;
    x[5] = posx;
    y[5] = posy + 2;
    x[6] = posx + 2;
    y[6] = posy + 2;
}
char U::name(void) const{
    return 'U';
}
int U::size(void) const {
    return 7;
}

const char* U::color(void) const {
    char str[] = "red";
    char* tempptr = str;
    return tempptr;
}

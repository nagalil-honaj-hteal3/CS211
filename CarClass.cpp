#include <iostream> 
#include <string>
using namespace std;

enum direc {NORTH, EAST, SOUTH, WEST};

class Car {
 
  private:
  string model;
  int year, mileage;
  int X;
  int Y;
  direc direction;

  public: 
  Car (string md, int yr);
  void goForward(int blk);
  int getX() const;
  int getY() const;
  string getModel() const;
  void turnRight();
  string getDirection() const;
  void turnLeft();
  int getMileage()const;
  //string getModel(string md) const;

};

Car::Car(string md, int yr) {
  model = md;
  year = yr;
  mileage = 0;
  X = 0;
  Y = 0;
  direction = NORTH;
}

int Car::getMileage() const{
  
  return mileage;
}

void Car::goForward(int blk) {

  if(direction == NORTH)
    Y += blk;
  else if (direction == EAST)
    X += blk;
  else if (direction == SOUTH)
    Y -= blk;
  else //west directiom
    X -= blk;

  mileage += blk;
}


int Car::getX() const{

  return X;

}

int Car::getY() const{

  return Y;

}

void Car::turnRight() {
  
  if (direction == WEST)
    direction == SOUTH;
  else 
    direction = (direc)(direction + 1);

}

void Car::turnLeft() {

  if (direction == EAST)
    direction == NORTH;
  else 
    direction = (direc)(direction - 1);

}

string Car::getModel() const {
  
  //md = model;
  return model;

  }

string Car::getDirection() const{

  switch (direction) {

  case NORTH: return "North";
  case EAST: return "East";
  case SOUTH: return "South";
  case WEST: return "West";
    //no need for break since there is return
  }

}

void showInfo(const Car& c);
//client program -- outside the car class
int main () {

  Car c1("Camry", 2021);
  Car c2("Neon", 2020);

  c1.getModel();
  c1.goForward(3);
  c1.turnRight();
  c1.goForward(5);
  c1.turnRight();
  c1.goForward(7);
  c1.turnRight();
  c1.goForward(6);
  c1.turnLeft();
  c1.goForward(1);
  //cout << "Car class output\nGo forward 3 blocks.";
    //cout << " -> ends up at (" << c1.getX() << ", " << c1.getY() << ")";
  //cout << "\nTurn Right.";
    //cout << "          -> facing " << c1.getDirection() << endl;
  //cout << "Go forward 5 blocks.";
    //cout << " -> ends up at (" << c1.getX() << ", " << c1.getY() << ")";
  //cout << "\nTurn Right.";
    //cout << "          -> facing " << c1.getDirection() << endl;
  //cout << "Go forward 7 blocks.";
    //cout << " -> ends up at (" << c1.getX() << ", " << c1.getY() << ")";
  //cout << "\nTurn Right.";
    //cout << "          -> facing " << c1.getDirection() << endl;
  //cout << "Go forward 6 blocks.";
    //cout << " -> ends up at (" << c1.getX() << ", " << c1.getY() << ")";
  //cout << "\nTurn Left.";
    //cout << "           -> facing " << c1.getDirection() << endl;
  //cout << "Go forward 1 block.";
    //cout << "  -> ends up at (" << c1.getX() << ", "  << c1.getY() << ")" << endl;
    //cout << "\nExpected output: " << c1.getMileage() << endl;
  showInfo(c1);
  return 0;

}

void showInfo(const Car& c) { //const stays the same  
  
  cout << c.getModel() << " " << /*c.yr << */" is located at (" << c.getX() << "," << c.getY() << ") facing " << c.getDirection() << ". It has " << c.getMileage() << " miles on it." << endl;

}

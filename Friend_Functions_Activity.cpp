#include <bits/stdc++.h>
using namespace std;

/*
Friend Functions
Created by Juan Pablo Dueñas & Mauricio González (October 10th, 2023)
Modified by Juan Pablo Dueñas & Mauricio González (October 17th, 2023)

The teacher's code was used as a basis.


Program that calculates the weight of a body in Newtons.
*/

class Body{

  private:
    //The mass is in kilograms
    float Mass;

  public:

    //Constructors
    Body(float mass){
      this-> Mass = mass;
    }

    Body(){
      Mass = 1;
    }

    //Copy Constructor
    Body(const Body &c){
      Mass = c.Mass;
    }

    //Destructor
    ~Body(){
      cout << "The body has been destroyed" << endl;
    }

    //Setter
    void setMass(float mass){
      this-> Mass = mass;
    }

    public:
      //Friend function
      friend void calculateWeightEarth(Body c);

      //Friend Class
      friend class Moon;
};

  //Friend function that calculates weight on Earth
  void calculateWeightEarth (Body c){
    
    cout << "The weight of the object on Earth: " << c.Mass * 9.81 << " N" << endl;
    //9.81 m/s^2: gravity on Earth
  }

//Friend Class
class Moon {
  public:
    
    //Constructor
    Moon(){}

    //Destructor
    ~Moon(){
      cout << "Calculations for weight on the moon were destroyed." << endl;
    }

    //Friend function that calculates weight on the Moon
    void calculateWeightMoon(Body c){
      cout << "The weight of the object on the Moon: " << c.Mass * 1.622 << " N" << endl;
      //1.622 m/s^2: gravity on the Moon
    }
};

int main() {

  //Calculating weights
  cout << "3.5 kilogram Box: " << endl;
  Body Box (3.5);
  calculateWeightEarth(Box);
  Moon LunarBox;
  LunarBox.calculateWeightMoon(Box);

  cout << endl;

  //Empty Constructor Object (with specified mass)
  cout << "2.3 kilogram Block: " << endl;
  Body block;
  block.setMass(2.3);
  calculateWeightEarth(block);
  Moon LunarBlock;
  LunarBlock.calculateWeightMoon(block);

  cout << endl;

  //Empty Constructor Object (without specified mass)
  cout << "1 kilogram Bottle: " << endl;
  Body bottle;
  calculateWeightEarth(bottle);
  Moon LunarBottle;
  LunarBottle.calculateWeightMoon(bottle);

  cout << endl;
}
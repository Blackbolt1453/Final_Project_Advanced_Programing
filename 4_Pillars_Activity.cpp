#include <bits/stdc++.h>

using namespace std;

/*
4 Pillars
Created by Juan Pablo Dueñas & Mauricio González (October 4th, 2023)
Modified by Juan Pablo Dueñas & Mauricio González (October 17th, 2023)

The teacher's code was used as a basis.
*/

//Abstract Class Device
class Device{
  virtual void funcionality() = 0;
};

//Parent Class HomeDevice (daughter Class of Device)
class HomeDevice:Device{ 
  private: //Atributes
    string  NameDev;
    string  Type;
    int     Power;
    float   Mass;
    bool    Resistance;

  public:

    //Default Constructor
    HomeDevice(){}

    //Constructor with parameters
    HomeDevice(string NameDev, string Type, int Power, float Mass, bool Resistance){
      this->NameDev = NameDev;
      this->Type = Type;
      this->Power = Power;
      this->Mass = Mass;
      this->Resistance = Resistance;
    }

    //Constructor Copia
    HomeDevice(const HomeDevice  &obj){
      this->NameDev = obj.NameDev;
      this->Type = obj.Type;
      this->Power = obj.Power;
      this->Mass = obj.Mass;
      this->Resistance = obj.Resistance;
    }

    //Getters & Setters
    string getNameDev(){return NameDev;}

    void setNameDev(string NameDev){this->NameDev = NameDev;}

    string getType(){return Type;}

    void setType(string Type){this->Type = Type;}

    int getPower(){return Power;}

    void setPower(int Power){this->Power = Power;}

    float getMass(){return Mass;}

    void setMass(float Mass){this->Mass = Mass;}

    bool getResistance(){return Resistance;}

    void setResistance(bool Resistance){this->Resistance = Resistance;}
      
    //Methods

    //Abstract Method Implemented
    void funcionality (){
      cout << "The home device " << getNameDev() << " works properly." << endl;
    }

    void heavy (){
      if(getMass() >= 5){
        cout << "The mass of the home device " << getNameDev() << " is more than 5 kilograms." << endl;
      }
      else {
        cout << "The home device " << getNameDev() << " is a light device." << endl;
      }
    }

    //Virtual Method
    virtual void giveData (){
      cout << "Name: " << getNameDev() << endl;
      cout << "Type: " << getType() << endl;
      cout << "Power: " << getPower() << " watts" << endl;
      cout << "Mass: " << getMass() << " kg" << endl;
      if(getResistance()== true){
        cout << "The device is durable." << endl;
      }
      else {
        cout << "The device is fragile." << endl;
      }
      
    }
};

//Parent Class OtherDevice (daughter Class of Device)
class OtherDevice:Device{ 
  private: //Atributes
    string NameDev;
    string Use;
    string Fuel;
    float  Volume;
    bool   HighConsumption;

  public:

    //Default Constructor
    OtherDevice(){}

    //Constructor with parameters
    OtherDevice(string NameDev, string Use, string Fuel, float Volume, bool HighConsumption){
      this->NameDev = NameDev;
      this->Use = Use;
      this->Fuel = Fuel;
      this->Volume = Volume;
      this->HighConsumption = HighConsumption;
    }
    
    //Getters & Setters
    string getNameDev(){return NameDev;}

    void setNameDev(string NameDev){this->NameDev = NameDev;}

    string getUse(){return Use;}

    void setUse(string Use){this->Use = Use;}

    string getFuel(){return Fuel;}

    void setFuel(string Fuel){this->Fuel = Fuel;}

    float getVolume(){return Volume;}

    void setVolume(float Volume){this->Volume = Volume;}

    bool getHighConsumption(){return HighConsumption;}

    void setHighConsumption(bool HighConsumption){this->HighConsumption = HighConsumption;}

    //Methods
    virtual void verifyFuel (){
      cout << "The device " << getNameDev() << " works by using " << getFuel() << endl;
    }

    void verifyConsumption (){
      if(getHighConsumption()== true){
        cout << "The device " << getNameDev() << " consumes a lot of energy." << endl;
      }
      else {
        cout << "The device " << getNameDev() << " consumes a minimal amount of energy." << endl;
      }
      
    }

    //Abstract Method Implemented
    void funcionality (){
      cout << "The other device " << getNameDev() << " works properly." << endl;
    }
};

//GameConsole (daughter Class of HomeDevice)
class GameConsole: public HomeDevice{
  //Atributes
  private:  

  bool Portable;
  string Brand;

  public:
    //Default Constructor
    GameConsole(){}

    //Constructor with parameters
    GameConsole(string NameDev, string Type, int Power, float Mass, bool Resistance, bool Portable, string Brand): HomeDevice(NameDev, Type, Power, Mass, Resistance){
      this->Portable = Portable;
      this->Brand = Brand;
    }

    //Getters & Setters
    bool getPortable(){return Portable;}

    void setPortable(bool Portable){this->Portable = Portable;}

    string getBrand(){return Brand;}

    void setBrand(string Brand){this->Brand = Brand;}

    //Methods

    //Virtual Method giveData Implemented (Polimorfism)
    void giveData (){
      cout << "Name of the console: " << getNameDev() << endl;
      cout << "Power of the console: " << getPower() << " watts" << endl;
      cout << "Mass of the console: " << getMass() << " kg" << endl;
      if(getResistance()== true){
        cout << "The console is durable." << endl;
      }
      else {
        cout << "The console is fragile." << endl;
      }
    }

    void giveBrand () {
      cout << "The console " << getNameDev() << " is a " << getBrand() << " console." << endl;
    }
    
    void verifyPortable (){
      
      if(getPortable()== true){
        cout << "The console " << getNameDev() << " is portable." << endl;
      }
      else {
        cout << "The console " << getNameDev() << " is not portable." << endl;
      }
    }

    void play (){
      cout << "The game has started. Good luck!" << endl;
    }
};

//Car (daughter Class of OtherDevice)
class Car: public OtherDevice{
  //Atributes
  private:

    bool   Tank;
    string Model;

    public:

      //Default Constructor
      Car(){}

      //Constructor with parameters
      Car (string nameDev, string use, string fuel, float volume, bool highConsumption, string model, bool tank):OtherDevice(nameDev, use, fuel, volume, highConsumption){
        this-> Tank = tank;
        this-> Model = model;
      }
      
      //Getters & Setters
      void setTanque (bool tank){
        Tank = tank;
      }

      bool getTank (){
        return Tank;
      }

      string getModel (){
        return Model;
      }

      void setModel (string model){
        Model = model;
      }

      //Methods

      void fillTank (){
        if(getTank()== true){
          cout << "The tank of the " << getNameDev() << " car is full." << endl;
        }
        else {
          cout << "The tank of the " << getNameDev() << " car is empty." << endl;
        }
      }

      void giveModel (){
        cout << "The vehicle " << getNameDev() << " is a " << getModel() << endl;
      }

//Virtual Method verifyFuel Implemented (Polimorfism)
      void verifyFuel (){
        cout << "The vehicle " << getNameDev() << " works with gasoline" << endl;
      }
};

//No Member Function
void duplicateMass (HomeDevice &homeDevice){
  int masaDoble = homeDevice.getMass() * 2;
  homeDevice.setMass(masaDoble);
  cout << "The duplicated mass of " << homeDevice.getNameDev() << " is: " << homeDevice.getMass() << " kg" << endl;
}

//Main
int main() {

  //Objets of each class with their methods
  HomeDevice screen ("television", "Smart TV", 150, 25, true);
  screen.giveData();
  screen.heavy();
  screen.funcionality();

  cout << endl;

  //Copy Object of Screen HomeDevice
  HomeDevice screen2(screen);
  screen2.giveData();
  screen2.heavy();
  screen2.funcionality();

  cout << endl;
  
  OtherDevice pc ("Supercomputer", "computing", "electricity", 400, true);
  pc.verifyFuel();
  pc.verifyConsumption();
  pc.funcionality();

  cout << endl;

  //OtherDevice Example with Empty Constructor
  OtherDevice other;
  other.verifyFuel();
  other.verifyConsumption();
  other.funcionality();

  cout << endl;

  GameConsole xbox ("Xbox 360", "consola", 120, 6, true, false, "Microsoft");
  xbox.giveBrand();
  xbox.giveData();
  xbox.verifyPortable();
  xbox.play();

  cout << endl;

  Car car1 ("Ferrari", "automobile", "gasoline", 11.96, true, "Ferrari Roma", true);
  car1.fillTank();
  car1.giveModel();

  cout << endl;

  //Implementation of the no member munction
  duplicateMass(screen);

  cout << endl;

  //Pointers and execution of the virtual method with these
  OtherDevice* p1 = &pc;
  OtherDevice* p2 = &car1;

  p1->verifyFuel();
  cout << endl;
  p2->verifyFuel();

  cout << endl;

  HomeDevice* p3 = &screen;
  HomeDevice* p4 = &xbox;

  p3->giveData();
  cout << endl;
  p4->giveData();
  
  cout << endl;
  cout << "End of the Program.";
  return 0;
}
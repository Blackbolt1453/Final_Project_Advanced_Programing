/*
Constructors 

The teacher's code was used as a basis.

Edited by:  
    - Juan Pablo Dueñas García
    - Mauricio González Angelino

Date:
    - December 6th, 2023
*/

#include<bits/stdc++.h>
using namespace std;

class Employee{                  // Inherits from the EmployeeAbstract class
protected:
    string name;                 // Encapsulated with a getter and setter

private:  
    string company;              
    int age;

public:
    // Method
    void presentation(){
        cout << "Name: " << name << endl;
        cout << "Company: " << company << endl;
        cout << "Age: " << age << endl;
    }

    // Constrcuctor
    Employee(){
        name   = "Undefined.";
        company = "Undefined.";
        age     = 0;
    };

    Employee (string name, string company, int age){
        this->name    = name;
        this->company = company;
        this->age     = age;
    }

    // Getters and Setters
    void name (string name){
        this->name = name;
    }

    string getname (){
        return name;
    }

    void setcompany (string company){
        this->company = company;
    }

    string getcompany (){
        return company;
    }

    void setage (int age){
        this->age = age;
    }

    int getage (){
        return age;
    }
    // Implementation of the abstract class method
    void getRaise(){
        if(age >= 30)
            cout << "Congratulations " << name << ". ¡You received a raise!" << endl;
        else
            cout << "Sorry, you have to wait for the raise." << endl;
    }

    // new function 
    virtual void work(){                                                                                   
        cout << "Working... Attending to pending tasks, checking the agenda..." << endl;                        
    }
};

// Child class
class MechatronicEngineer: public Employee{
public:
    string Favoritelenguaje;

    // Contructor of the child class
    MechatronicEngineer(string name, string company, int age, string Favoritelenguaje): Employee(name, company, age){          // It uses advantage of the parent's constructor
            this->Favoritelenguaje = Favoritelenguaje;                                                                          
        }
    
    // Own method of the child class
    void programMicros(){
        cout << "The engineer " << name << " program microcontroller in " << Favoritelenguaje << "." << endl;
    }

    void work(){
        cout << "The engineer " << name << " is working with PLC." << endl;
    }
};

// Another child class 
class BioelectronicEngineer: public Employee{
public:
    string Favoritedisign;

    // Constructor of the child class
    BioelectronicEngineer(string name, string company, int age, string Favoritedisign)
        :employee(name, company, age){                                                              
            this->Favoritedisign = Favoritedisign;                                                  
        }
    
    // Own method of the child class
    void design(){
        cout << "The engineer " << name << " design in " << Favoritedisign << "." << endl;
    }

    // Another example of polymorphism 
    void work(){
        cout << "The engineer " << name << " is designing a bioinstrumentation circuit." << endl;
    }
};

// Method not member of any class
void increaseAge(Employee &employee){ 
    int newage = employee.getage() + 1;
    cout << "New age: " << newage << endl;
    employee.setage(newage);
}

int main(){

    Employee employye = Employee("Juan", "UP", 27);
    employye1.presentation();

    cout << employye1.getname() << " is " << employee1.getage() << " years old and works in " << employee1.getcompany() << endl;

    employee1.getRaise();
    cout << endl;

    // Creating a new object of the MechanicalEngineer class
    MechatronicEngineer mec = MechatronicEngineer("Juan", "Bonaterra", 15, "Phyton");
    mec.programMicros();

    // Creating a new object of the BioelectronicEngineer class
    BioelectronicEngineer bio = BioelectronicEngineer("Mauricio", "Laboratory", 45, "AutoCAD");
    bio.disign();

    Employee newemployee; 
    newemployee.presentation();                         // The newemployee object does not have information provided by the user
    
    // Using the non-member function
    increaseAge(employee1);
    employee.presentation(); 

    increaseAge(bio);
    bio.presentation();

    return 0;
}
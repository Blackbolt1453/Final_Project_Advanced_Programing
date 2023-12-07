/*
Created by:
    - Juan Pablo Dueñas García
    - Mauricio González Angelino

Date:
    - November 3rd, 2023

Links:
    - Code shown in class
    - HEKTOR DOCS. (9 de mayo de 2022). Manejo de excepcioines y errores en C++. Recuperado de https://docs.hektorprofe.net/cpp/13-manejo-excepciones/
    - Universidad Carlos III de Madrid. (s.f.). La función printf. Recuperado de https://www.it.uc3m.es/pbasanta/asng/course_notes/input_output_printf_es.html

Instructions: 
    - Generate a program, using exceptions, in which division by zero is carried out
*/

#include <bits/stdc++.h>
using namespace std;

double division (double n1, double n2){
    if(n2 == 0){
        throw runtime_error("Division by 0 is not allowed.");
    }else{
        return n1/n2;
    }
}

int main(){
    double n1, n2; 
    
    cout<<"Enter the first number: "; 
    cin>>n1;
    cout<<"Enter the second number: ";
    cin>>n2;
    cout<<endl;

    try{
        double r = division (n1, n2);
        printf("%g  %c  %g  =   %g \n", n1, 246, n2, r);         // " %g " imprime un número double o float usando la notación que requiera menor espacio
    }
    catch (const runtime_error& e) {
        cerr<<"ERROR: "<< e.what();                              //Muestra la excepcion de runtime_error arrojada si el denominador es igual a  0
    }
    cout<<endl<<"End of program.";
    return 0;
}
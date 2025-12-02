#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool f(long int i){
    std::string cadena=std::to_string(i);
    return cadena.substr(0,cadena.length()/2)==cadena.substr(cadena.length()/2,cadena.length());
}
int main(){
    std::string cadena;

    std::ifstream fich("entrega");
    if (!fich){
        std::cout << "Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE);
    }
    long int inicio,fin;
    std::string guion;
    long int res=0;
    while(std::getline(fich, cadena, ',')){
        std::stringstream ss(cadena);
        ss >> inicio >> guion;
        fin=stol(guion.substr(1));
        
        for(long int i=inicio;i<=fin;i++){
            if(f(i)){
                res+=i;
                std::string cadena=std::to_string(i);
                std::cout <<i <<" "<< cadena.substr(0,cadena.length()/2)<<" " <<cadena.substr(cadena.length()/2,cadena.length())<<"\n";
            }
        }
    }
    std::cout << "El resultado es: " << res;
}
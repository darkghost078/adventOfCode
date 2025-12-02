#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool f(long int i){
    std::string cadena=std::to_string(i);
    for(int j=1;j<=cadena.length()/2;j++){
        bool res=true;
        for(int k=0;k<cadena.length();k+=j){
            if(cadena.substr(k,j)!=cadena.substr(0,j)){
                res=false;
                break;
            }
        }
        if(res)
            return true;
    }
    return false;
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
            }
        }
    }
    std::cout << "El resultado es: " << res;
}
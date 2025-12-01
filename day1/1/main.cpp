#include <fstream>
#include <iostream>
#include <string>

int main(){
    int actual=50,contador=0;
    std::string valor;
    std::ifstream fich("entrega");
    if (!fich){
        std::cout << "Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE);
    }
    while(std::getline(fich,valor)){
        if(valor[0]=='R'){
            valor.erase(0,1);
            actual=actual+std::stoi(valor);
            actual=actual%100;
        }
        else{
            valor.erase(0,1);
            actual=actual-std::stoi(valor);
            actual=actual%100;
        }

        if(actual==0)
            contador++;
    }

    std::cout << "0 ha salido: " << contador;
}
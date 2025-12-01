#include <fstream>
#include <iostream>
#include <string>

int main(){
    int actual=50,contador=0,num;
    std::string valor;
    std::ifstream fich("entrega");
    if (!fich){
        std::cout << "Error al abrir\n";
        exit(EXIT_FAILURE);
    }
    while(std::getline(fich,valor)){
        contador+=(std::stoi(valor.substr(1)))/100;
        num=(std::stoi(valor.substr(1)))%100;
        std::cout << contador <<" "<<actual <<" "<< valor<<"\n";
        
        if(valor[0]=='R'){
            actual=actual+num;
            if(actual>=100){
                contador++;
                actual=actual-100;
            }
        }
        else{
            int anterior=actual;
            actual=actual-num;
            if(actual==0){
                contador++;
            }
            if(actual<0){
                if(anterior!=0){
                    contador++;
                }
                actual+=100;
            }
        }

    }

    std::cout << "0 ha pasado: " << contador;
}
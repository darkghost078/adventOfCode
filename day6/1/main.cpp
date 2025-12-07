#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

    
void mostrarMatriz(std::vector<std::vector<std::string>>&matriz){
    for(int i=0;i<matriz.size();i++){
        for(int j=0;j<matriz[i].size();j++)
            std::cout << matriz[i][j] << " ";
        std::cout << "\n";
    }
}

void mostrarVector(std::vector<std::string>&v){
    for(int i=0;i< v.size();i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}


long long int procesarVector(std::vector<std::string>&v){
    int posOp=0;
    for(int i=0;i<v.size();i++){
        if(v[i]=="*" || v[i]=="+")
            posOp=i;
    }
    long long int contador;
    if(v[posOp]=="+"){
        contador=0;
        for(int i=0;i<posOp;i++){
            contador+=stoll(v[i]);
        }
    }
    else if(v[posOp]=="*"){
        contador=1;
        for(int i=0;i<posOp;i++){
            contador*=stoll(v[i]);
        }
    }
    return contador;

}

int main(){
    std::string valor;
    std::ifstream fich("test");
    std::string num;
    if (!fich){
        std::cout << "Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE);
    }
    std::vector<std::vector<std::string>>matriz;
    std::vector<std::string> fila;
    while(getline(fich,valor)){
        std::istringstream ss (valor);
        while (ss >> num)
            fila.push_back(num);
        matriz.push_back(fila);
        fila.clear();
    }

mostrarMatriz(matriz);
long long int contador=0;
std::vector <std::string>aux;
    for(int i=0;i<matriz[0].size();i++){
        for(int j=0;j<matriz.size();j++){
            aux.push_back(matriz[j][i]);
        }
        mostrarVector(aux);
        long long num=procesarVector(aux);
        std::cout << "Resultado: " << num<< "\n";
        contador+=num;
        aux.clear();
    }
    std::cout << "El total es : " << contador;
}
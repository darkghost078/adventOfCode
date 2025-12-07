#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

    

void mostrarVector(std::vector<std::string>&v){
    for(int i=0;i< v.size();i++){
        std::cout << v[i] << "\n";
    }
}


long long int procesarCadena(std::string &c){
    std::vector<long long int> nums;
    std::string op;
    std::istringstream ss(c);
    long long int num;
    std::string valor;
    while(ss >> valor){
        if(valor!="*" && valor!="+"){
            num=stoll(valor);
            nums.push_back(num);
        }
        else
            op=valor;
    }

    long long int contador;
    if(op == "*"){
        contador=1;
        for(int i=0;i<nums.size();i++){
            contador*=nums[i];
        }
    }
    else if(op == "+"){
        contador=0;
        for(int i=0;i<nums.size();i++){
            contador+=nums[i];
        }
    }
    std::cout <<"\n"<< c << " = " << contador;
    return contador;
}

int main(){
    std::string valor;
    std::ifstream fich("entrega");
    
    if (!fich){
        std::cout << "Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE);
    }
    std::vector<std::vector<std::string>>matriz;
    std::vector<std::string> fila;
    while(getline(fich,valor,'\n')){
        fila.push_back(valor);
    }



    long long int contador=0;
    std::string num="";
    std::vector<std::string> nums;
    for(int i=fila[0].size()-1;i>=0;i--){
        for(int j=0;j<fila.size();j++){
            if(fila[j][i]=='*'||fila[j][i]=='+')
                num+=" ";

            num+= fila[j][i];
        }
        if(num[num.size()-1]=='*'||num[num.size()-1]=='+'){
            nums.push_back(num);
            num.clear();
        }
    }
    mostrarVector(nums);
    for(int i=0;i<nums.size();i++){
        contador+=procesarCadena(nums[i]);
    }
    std::cout << "\nEl resultado es: " << contador;
}
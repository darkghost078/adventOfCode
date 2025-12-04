import copy
fich = open('entrega', 'r')

def obtener8vecinos(matriz,fila,columna):
    vecinos=0
    if columna==0:
        vecinos+=matriz[fila][columna+1]
        if fila==0:
            vecinos+=matriz[fila+1][columna]
            vecinos+=matriz[fila+1][columna+1]
        elif fila==len(matriz)-1:
            vecinos+=matriz[fila-1][columna]
            vecinos+=matriz[fila-1][columna+1]
        else:
            vecinos+=matriz[fila-1][columna]
            vecinos+=matriz[fila+1][columna]
            vecinos+=matriz[fila-1][columna+1]
            vecinos+=matriz[fila+1][columna+1]
    elif columna==len(matriz[fila])-1:
        vecinos+=matriz[fila][columna-1]
        if fila==0:
            vecinos+=matriz[fila+1][columna]
            vecinos+=matriz[fila+1][columna-1]
        elif fila==len(matriz)-1:
            vecinos+=matriz[fila-1][columna]
            vecinos+=matriz[fila-1][columna-1]
        else:
            vecinos+=matriz[fila-1][columna]
            vecinos+=matriz[fila+1][columna]
            vecinos+=matriz[fila-1][columna-1]
            vecinos+=matriz[fila+1][columna-1]

    elif fila==0:
        vecinos+=matriz[fila+1][columna]
        vecinos+=matriz[fila][columna-1]
        vecinos+=matriz[fila][columna+1]
        vecinos+=matriz[fila+1][columna-1]
        vecinos+=matriz[fila+1][columna+1]
    elif fila==len(matriz)-1:
        vecinos+=matriz[fila][columna-1]
        vecinos+=matriz[fila][columna+1]
        vecinos+=matriz[fila-1][columna]
        vecinos+=matriz[fila-1][columna-1]
        vecinos+=matriz[fila-1][columna+1]
    else:
        vecinos+=matriz[fila+1][columna]
        vecinos+=matriz[fila-1][columna]
        vecinos+=matriz[fila][columna+1]
        vecinos+=matriz[fila][columna-1]
        vecinos+=matriz[fila-1][columna-1]
        vecinos+=matriz[fila-1][columna+1]
        vecinos+=matriz[fila+1][columna-1]
        vecinos+=matriz[fila+1][columna+1]


    return vecinos


def matrizVecinos(matriz):
    matrizres=copy.deepcopy(matriz)
    for fila in range(len(matriz)):
        for col in range(len(matriz[fila])):
            vecinos=obtener8vecinos(matriz,fila,col)
            matrizres[fila][col]=vecinos
    return matrizres


matriz=[]
for fila in fich:
    fila.strip()
    print(fila)
    num=[]
    for i in fila:
        if i=='@':
            num.append(1)
        elif i!='\n':
            num.append(0)

    matriz.append(num)

for fila in matriz:
    print(fila)


for fila in range(len(matriz)):
    for col in range(len(matriz[fila])):
        print(matriz[fila][col], end="")
    print()

print()



papelQuitado=True

contador=0
while(papelQuitado):
    papelQuitado=False
    matrizres=matrizVecinos(matriz)
    for fila in range(len(matrizres)):
        for col in range(len(matrizres[fila])):
            if(matrizres[fila][col]<4 and matriz[fila][col]!=0):
                contador+=1
                matriz[fila][col]=0
                papelQuitado=True

print(contador)
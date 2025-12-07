fich = open('entrega', 'r')

ranges=[]
fresh=[]

for fila in fich:
    linea=fila.strip()
    if '-' in linea:
        partes=linea.split('-')
        partesi=int(partes[0]),int(partes[1])
        ranges.append(tuple(partesi))
    elif linea !='':
        num=int(linea)
        for i in ranges:
            if i[0]<=num and i[1] >= num and num not in fresh:
                fresh.append(num)
        

print(ranges)
print(fresh)
print(f"Tamaño: {len(fresh)}")

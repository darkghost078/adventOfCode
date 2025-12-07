fich = open('entrega', 'r')

ranges=[]

for fila in fich:
    linea=fila.strip()
    if '-' in linea:
        partes=linea.split('-')
        partesi=int(partes[0]),int(partes[1])
        ranges.append(tuple(partesi))
    else:
        break;

ranges.sort();
listo=[]
listo.append(ranges[0])
finalant=listo[0][1]
for i in range(1,len(ranges)):
    inicio=ranges[i][0]
    final=ranges[i][1]
    print(f"Final Ant:{finalant} Inicio: {inicio}")
    if inicio<= finalant:
        print("xd")
        inicio=finalant+1
    if final>=finalant:
        listo.append(tuple([inicio,final]))
        finalant=final

count=0
for i in range(len(listo)):
    count+=(listo[i][1]-listo[i][0]+1)
print(ranges)
print(listo)
print(f"Elementos: {count}")

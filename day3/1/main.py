fich = open('entrega', 'r')


def max(num,pos,final):
    max=num[pos]
    newpos=pos
    for i in range (pos+1,final):
        if(num[i]>max):
            max=num[i]
            newpos=i
    return max, newpos

res=""
vec=[]
for num in fich:
    print(num)
    dig=0
    pos=0
    i=1
    limit=i+1
    while(dig<limit):
        final=len(num)-i-1
        newdig, newpos=max(num,pos,final)
        pos=newpos+1
        i-=1
        res= res + newdig
        dig+=1
    print(res)
    vec.append(res)
    res=""
print(vec)
sum=0
for i in range(len(vec)):
    sum+=int(vec[i])
print(f"Res: {sum}")

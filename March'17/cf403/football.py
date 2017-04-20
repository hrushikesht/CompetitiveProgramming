
n=input()
n=int(n)

name1=[]
name2=[]

for i in range(n):
    x=input()
    x=list(x.split())
    # print(x)
    name1.append(x[0][0:3])
    name2.append(x[0][0:2] + x[1][0])




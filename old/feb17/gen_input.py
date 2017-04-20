import random

n = 1000
l = 10000
r = int(1e12)

a=[]

for i in range(0,1000):
    a.append(int(random.uniform(1,1e15)))

f = open('input.txt','w')
f.truncate()

f.write(str(n)+' '+str(l)+' '+str(r)+'\n')

for x in a:
    f.write(str(x)+' ')

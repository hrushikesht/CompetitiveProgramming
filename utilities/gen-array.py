import random

f=open("input.txt","w")

test_cases=1
n= int(1e3)

f.truncate()

f.write(str(test_cases)+"\n")
f.write(str(n)+"\n")

for i in range(n-1):
    f.write(str(random.randint(1,1e4))+" ")

f.write("\n")

for i in range(n-2):
    f.write(str(random.randint(1,1e4))+" ")

f.write("\n")

for i in range(n-3):
    f.write(str(random.randint(1,1e4))+" ")

f.write("\n")
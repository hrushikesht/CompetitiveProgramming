import random

f=open("tidy_my_input.txt","w")

test_cases=100
n= int(1e3)

f.truncate()

f.write(str(test_cases)+"\n")
# f.write(str(n)+"\n")

for i in range(test_cases):
    f.write(str(random.randint(1,1e18))+"\n")

f.write("\n")

# for i in range(n-2):
#     f.write(str(random.randint(1,1e4))+" ")

# f.write("\n")

# for i in range(n-3):
#     f.write(str(random.randint(1,1e4))+" ")

f.write("\n")
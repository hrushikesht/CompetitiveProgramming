import math

n=int(input())
k=int(input())

dig = math.floor(math.log(n,10))
div = 10**(dig+1)

# print('dig',dig)
# print('div',div)

ans=0
index=0

while k!=0:
    # print('k',k)
    temp=int(k%div)
    # print('temp',temp)
    # print('n',n);
    # print('bro',temp<n)
    if temp<n:
        # print('new temp',temp)
        ans+=temp*(n**index)
        k=math.floor(k/div)
        index=index+1
    else:
        temp=k%(math.floor(div/10))
        # print('new temp',temp)
        ans+=temp*(n**index)
        k=math.floor(k*10/(div))
        index=index+1
    # print('ans',ans)        

print(ans)
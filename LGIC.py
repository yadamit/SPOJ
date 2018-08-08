n=int(input())

fact=1;
for i in range(2,n+1):
    fact=fact*i;
# print(fact)

x=5;
for i in range(4,n+1):
    x=x*2+i-2;
# print(x)

print(fact+x);

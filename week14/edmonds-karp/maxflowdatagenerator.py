
import random
# import faker

test_cases = 3

print(test_cases)
for t in range(0,test_cases):
    N = random.randint(5,7) # 6
    E = random.randint(7,9) # 9
    Cmax = 9
    Cmin = 3 
    print(f"{N} {E}")
    for i in range(0,E):
        a = random.randint(0,N-1)
        b = random.randint(0,N-1)
        w = random.randint(Cmin,Cmax)
        print(a,b,w)



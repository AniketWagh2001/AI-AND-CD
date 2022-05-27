import numpy as np
N = int(input("Enter N for NxN matrix : "))

X = np.zeros((N,N), dtype=int)

n=1
i=0
j=N//2

while n<=N**2:
    X[i,j] = n
    n += 1
    testi = (i-1)%N
    testj = (j+1)%N

    if X[testi, testj]:
        i += 1
    
    else:
        i, j = testi, testj


print(X)
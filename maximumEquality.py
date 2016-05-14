def answer(x):
    # your code here
    
    n = len(x)
    S = sum(x)
    res = 1
    MAX = 1000000
    if S <= n:
        res = S
        return res
    
    for m in range(0, n):
        if (S - (n-m)*min(int(S / (n-m)), MAX)) <= m*MAX:
            res = n-m
            break
    
    return res


x = [1, 4, 1]
ans = answer(x)
print ans

x = [1, 2]
ans = answer(x)
print ans

def answer(population, x, y, strength):
    # your code here
    
    import copy
    ans = copy.deepcopy(population)
    yLen = len(ans)
    xLen = len(ans[0])
    
    spreadInfection(ans, x, y, strength, xLen, yLen)
    
    return ans
    

def spreadInfection(ans, x, y, strength, xLen, yLen):
    
    # Check if it goes out of bound
    if x >= xLen or x < 0 or y < 0 or y >= yLen:
        return
    
    # Return if it can't be infected or it has been infected
    if strength < ans[y][x] or ans[y][x] == -1:
        return
    
    ans[y][x] = -1
        
    spreadInfection(ans, x+1, y, strength, xLen, yLen)
    spreadInfection(ans, x-1, y, strength, xLen, yLen)
    spreadInfection(ans, x, y+1, strength, xLen, yLen)
    spreadInfection(ans, x, y-1, strength, xLen, yLen)

population = [[1, 2, 3], [2, 3, 4], [3, 2, 1]]
x = 0
y = 0
strength = 2

ans = answer(population, x, y, strength)
print ans

population = [[6, 7, 2, 7, 6], [6, 3, 1, 4, 7], [0, 2, 4, 1, 10], [8, 1, 1, 4, 9], [8, 7, 4, 9, 9]]
x = 2
y = 1
strength = 5

ans = answer(population, x, y, strength)
print ans

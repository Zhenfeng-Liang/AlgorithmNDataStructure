'''
Carrotland
==========

The rabbits are free at last, free from that horrible zombie science experiment. They need a happy, safe home, where they can recover. 

You have a dream, a dream of carrots, lots of carrots, planted in neat rows and columns! But first, you need some land. And the only person who's selling land is Farmer Frida. Unfortunately, not only does she have only one plot of land, she also doesn't know how big it is - only that it is a triangle. However, she can tell you the location of the three vertices, which lie on the 2-D plane and have integer coordinates.

Of course, you want to plant as many carrots as you can. But you also want to follow these guidelines: The carrots may only be planted at points with integer coordinates on the 2-D plane. They must lie within the plot of land and not on the boundaries. For example, if the vertices were (-1,-1), (1,0) and (0,1), then you can plant only one carrot at (0,0).

Write a function answer(vertices), which, when given a list of three vertices, returns the maximum number of carrots you can plant.

The vertices list will contain exactly three elements, and each element will be a list of two integers representing the x and y coordinates of a vertex. All coordinates will have absolute value no greater than 1000000000. The three vertices will not be collinear.

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit solution.java

Test cases
==========

Inputs:
    (int) vertices = [[2, 3], [6, 9], [10, 160]]
Output:
    (int) 289

Inputs:
    (int) vertices = [[91207, 89566], [-88690, -83026], [67100, 47194]]
Output:
    (int) 1730960165
'''
from fractions import gcd

def answer(vertices):
    # your code here
    
    x1 = vertices[0][0]
    y1 = vertices[0][1]
    
    x2 = vertices[1][0]
    y2 = vertices[1][1]

    x3 = vertices[2][0]
    y3 = vertices[2][1]

    rho = (y2 - y1) / (x2 - x1)

    # Triangle area: http://www.mathopenref.com/coordtrianglearea.html
    area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2))

    # Boundary points on three sides, http://math.stackexchange.com/questions/628117/how-to-count-lattice-points-on-a-line
    B = abs(gcd(x2-x1, y2-y1)) + abs(gcd(x1-x3, y1-y3)) + abs(gcd(x2-x3, y2-y3))

	# Pick's theorem: http://jwilson.coe.uga.edu/EMAT6680Fa05/Schultz/6690/Pick/Pick_Main.htm
    I = area - 0.5 * B + 1

    return int(I)


vertices = [[0, 1], [-1, -1], [1, 0]]
print answer(vertices)

vertices = [[2, 3], [6, 9], [10, 160]]
print answer(vertices)

vertices = [[91207, 89566], [-88690, -83026], [67100, 47194]]
print answer(vertices)
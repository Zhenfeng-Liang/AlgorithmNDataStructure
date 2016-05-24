'''
Minion's bored game
===================

There you have it. Yet another pointless "bored" game created by the bored minions of Professor Boolean.

The game is a single player game, played on a board with n squares in a horizontal row. The minion places a token on the left-most square and rolls a special three-sided die. 

If the die rolls a "Left", the minion moves the token to a square one space to the left of where it is currently. If there is no square to the left, the game is invalid, and you start again.

If the die rolls a "Stay", the token stays where it is. 

If the die rolls a "Right", the minion moves the token to a square, one space to the right of where it is currently. If there is no square to the right, the game is invalid and you start again.

The aim is to roll the dice exactly t times, and be at the rightmost square on the last roll. If you land on the rightmost square before t rolls are done then the only valid dice roll is to roll a "Stay". If you roll anything else, the game is invalid (i.e., you cannot move left or right from the rightmost square).

To make it more interesting, the minions have leaderboards (one for each n,t pair) where each minion submits the game he just played: the sequence of dice rolls. If some minion has already submitted the exact same sequence, they cannot submit a new entry, so the entries in the leader-board correspond to unique games playable. 

Since the minions refresh the leaderboards frequently on their mobile devices, as an infiltrating hacker, you are interested in knowing the maximum possible size a leaderboard can have.

Write a function answer(t, n), which given the number of dice rolls t, and the number of squares in the board n, returns the possible number of unique games modulo 123454321. i.e. if the total number is S, then return the remainder upon dividing S by 123454321, the remainder should be an integer between 0 and 123454320 (inclusive).

n and t will be positive integers, no more than 1000. n will be at least 2.


Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit solution.java

Test cases
==========

Inputs:
    (int) t = 1
    (int) n = 2
Output:
    (int) 1

Inputs:
    (int) t = 3
    (int) n = 2
Output:
    (int) 3
'''

def answer(t, n):
	#​ ​your​ ​code​ ​here

	pos = 1
	hashTable = {}
	res = count_games(pos, t, n, hashTable)

	return res

# Use dynamic programming
def count_games(pos, t, n, hashTable):

	key = str(pos) + ',' + str(t) + ',' + str(n)

	if key in hashTable.keys():
		return hashTable[key]

	if n == pos:
		return 1;

	if n - pos > t:
		return 0;

	count = 0

	# Right move
	if pos < n:
		count = count + count_games(pos+1, t-1, n, hashTable)

	# Left move, we don't need to check the rightmost position since we make sure when the pos=n, it only returns 1
	if pos > 1:
		count = count + count_games(pos-1, t-1, n, hashTable)

	# Stay
	count = count + count_games(pos, t-1, n, hashTable)

	count = count % 123454321
	hashTable[key] = count 

	return count


# TOO SLOW!!!
def move(loc, remainingSteps, n, count):

	if loc == n:
		count[0] = count[0] + 1	

	if n - loc > remainingSteps or remainingSteps == 0:
		return

	# Move left only when it is currently not on the leftmost or rightmost squares
	if loc != 1 and loc != n:
		move(loc - 1, remainingSteps - 1, n, count)

	# Stay
	move(loc, remainingSteps - 1, n, count)

	# Move right only when it is not on the rightmost squares
	if loc != n:
		move(loc + 1, remainingSteps - 1, n, count)


def moveOld(loc, remainingSteps, n, leaderboards, currRoute):

	currRoute.append(loc)

	if remainingSteps == 0:
		if loc == n:
			leaderboards.append(currRoute)
			return
		else:
			return

	# Move left only when it is currently not on the leftmost or rightmost squares
	if loc != 1 and loc != n:
		move(loc - 1, remainingSteps - 1, n, leaderboards, currRoute[:])

	# Stay
	move(loc, remainingSteps - 1, n, leaderboards, currRoute[:])

	# Move right only when it is not on the rightmost squares
	if loc != n:
		move(loc + 1, remainingSteps - 1, n, leaderboards, currRoute[:])


t = 1
n = 2
ans = answer(t, n)
print ans


t = 3
n = 2
ans = answer(t, n)
print ans

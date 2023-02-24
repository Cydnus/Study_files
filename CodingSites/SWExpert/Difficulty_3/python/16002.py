#import sys
#sys.stdin = open("not_input_16002.txt", "r")
#sys.stdout = open("not_output_16002.txt", "w")

import random

def isCombine(num) -> bool:
    if num %2 == 0 :
        return True
    else:
        limit = int(num**0.5) + 1
        for i in range(3, limit, 2 ):
            if num % i == 0:
                return True
        return False


T = int(input())

for test_case in range(1,T+1):

    n = int(input())
    y = 4
    x = y + n
    
    while not (isCombine(y) and isCombine(x)):
        y += 1
        x += 1

    print("#{0} {1} {2}".format(test_case,x, y))


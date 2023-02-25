import sys
sys.stdin = open("not_input_16003.txt", "r")

def getFileNames(cnt, num=1, end=50,  file=[]):
    if len(file) >= end :
        return file
    start = 0
    while num+start <= cnt and start < 10 and len(file) < end:
        file.append(start+num)
        file = getFileNames(cnt, num=(num+start)*10, file=file)
        start += 1
    return file



if __name__ == '__main__':
    
    T = int(input())
    
    for test_case in range(1,T+1):
        
        n = int(input())

        filename = []
        endCnt = 50 if (n > 50) else n
        filename = getFileNames(cnt=n, end=endCnt)

        print("#{0} ".format(test_case), end="")

        for i in filename:
            print("{}.png".format(i), end=" ")

        print("")
        filename.clear()


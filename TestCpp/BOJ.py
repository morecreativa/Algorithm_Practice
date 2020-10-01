import sys

# 5052
if 1:
    def ret(listStr):
        listStr.sort()
        for i in range(len(listStr)-1):
            if len(listStr[i]) < len(listStr[i+1]) and listStr[i]==listStr[i+1][:len(listStr[i])]:
                #print(listStr[i+1][:len(listStr[i])])
                print('NO')
                return
        print('YES')
    
    n=int(input())
    for i in range(n):
        test_case=int(input())
        listStr=[]
        for i in range(test_case):
            listStr.append(sys.stdin.readline().strip())
        ret(listStr)

# ~
if 0:
    def solution():
        return 1
    

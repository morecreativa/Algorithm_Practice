import sys
from itertools import permutations

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

# programmers Find prime numbers
if 1:
    def solution(n):
        a = set()
        for i in range(len(n)):
            a |= set(map(int, map("".join, permutations(list(n), i + 1))))
        a -= set(range(0, 2))
        for i in range(2, int(max(a) ** 0.5) + 1):
            a -= set(range(i * 2, max(a) + 1, i))
        return len(a)

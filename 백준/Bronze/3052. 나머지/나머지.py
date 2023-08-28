import sys
ans = set([])
for i in range(10):
    n = int(sys.stdin.readline())
    ans.add(n % 42)
print(len(ans))
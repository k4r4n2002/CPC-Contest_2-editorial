import sys
import bisect
input = sys.stdin.readline 


def main():
   n, q = map(int, input().split())
   r = list(map(int, input().split()))
   r.sort()
   for i in range(1, n):
       r[i] += r[i - 1]

   for _ in range(q):
       X = int(input())
       index = bisect.bisect_right(r, X)  # Equivalent to upper_bound in C++
       print(index)

main()
import sys
input = sys.stdin.readline  

N = 1000100

def subsequence(s1, s2):
   n = len(s1)
   m = len(s2)
   i = 0
   j = 0
   while i < n and j < m:
       if s1[i] == s2[j]:
           j += 1
       i += 1
   return j == m

def main():
   s = input().rstrip()
   p = input().rstrip()

   n = len(s)
   a = list(map(int, input().split()))
   for i in range(n):
       a[i] -= 1  

   def check(mid):
       temp = ""
       v = []
       for i in range(mid, n):
           v.append(a[i])
       v.sort()
       for x in v:
           temp += s[x]
       return subsequence(temp, p)

   lo = 0
   hi = n
   ans = -1
   while lo <= hi:
       mid = (lo + hi) // 2
       if check(mid):
           ans = mid
           lo = mid + 1
       else:
           hi = mid - 1

   print(ans)


main()

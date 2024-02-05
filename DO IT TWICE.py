import sys
input = sys.stdin.readline  

def main():
    t = int(input())
    for _ in range(t):
        n, q = map(int, input().split())
        a = [0] * (n + 2)  # Initialize array with zeros
        queries = []

        for _ in range(q):
            l, r = map(int, input().split())
            queries.append((l, r))
            a[l] += 1
            a[r + 1] -= 1

        for i in range(1, n + 1):
            a[i] += a[i - 1]  

        for x, y in queries:
            a[y + 1] -= (y - x + 1)  

        for i in range(1, n + 1):
            a[i] += a[i - 1]  

        print(*a[1:n + 1])  # Print elements from index 1 to n


main()

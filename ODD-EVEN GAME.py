import sys
input = sys.stdin.readline  

def main():
    n = int(input())
    f = 0
    for _ in range(n):
        x = int(input())
        f |= (x & 1)  # Check for odd numbers

    print("first" if f else "second")


main()

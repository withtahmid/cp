import sys 
import os
import math

LOCAL = os.getenv('LOCAL') == 'true'

def dbg(*args):
    if LOCAL:
        print(*args, file=sys.stderr)

def solve(tc):
    dbg(f"Case: {tc}")

if __name__ == "__main__":
    if LOCAL:
        path = '/home/withtahmid/cp/IOFiles/'
        sys.stdin = open(f"{path}input.txt", 'r')
        sys.stdout = open(f"{path}output.txt", 'w')
        sys.stderr = open(f"{path}error.txt", 'w')

    t = 1
    # t = int(input())
    for tc in range(1, t + 1):
        solve(tc)

    dbg("\nReturned 0")

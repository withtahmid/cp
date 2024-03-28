import sys 
import os
import math
import time
import datetime

LOCAL = os.getenv('LOCAL') == 'true'

def dbg(*args):
    if LOCAL:
        print(*args, file=sys.stderr)

INT = lambda: int(input())
SPLIT = lambda: map(int, input().split())
LIST = lambda: list(SPLIT())

def run_case(tc:int):
    dbg(f"---- Case {tc} ---------\n")
    

    return
# END OF run_case
if __name__ == "__main__":
    start_time = time.time()
    if LOCAL:
        path = '/home/withtahmid/cp/IOFiles/'
        sys.stdin = open(f"{path}input.txt", 'r')
        sys.stdout = open(f"{path}output.txt", 'w')
        sys.stderr = open(f"{path}error.txt", 'w')
    dbg(datetime.datetime.now().strftime("%a %b %d %H:%M:%S %Y\n"))
    t = 1
    # t = INT()
    for tc in range(1, t + 1):
        run_case(tc)
    dbg(f"\n\nElapsed time: {((time.time() - start_time)) * 1000:.2} millisecond ")

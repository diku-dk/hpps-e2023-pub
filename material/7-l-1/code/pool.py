import multiprocessing
import time

data = (
    ['A', '2'], ['B', '1'], 
    ['C', '3'], ['D', '2']
)

def mp_worker(args):
    print(f"{args[0]} Waiting for {args[1]}s")
    time.sleep(int(args[1]))
    print(f"{args[0]} DONE")

p = multiprocessing.Pool(2)
p.map(mp_worker, data)
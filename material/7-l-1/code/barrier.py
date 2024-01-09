import multiprocessing
import select
import time

def producer(name, sleepy_time, to_consumer):
    print(f"{name} sleep for {sleepy_time}")
    time.sleep(sleepy_time)
    print(f"{name} awoken")
    to_consumer.put(1)

def consumer(in_1, in_2):
    barrier = [False, False]
    while True:
        (inputs, _, _) = select.select([in_1._reader, in_2._reader], [], [])
        if in_1._reader in inputs:
             _ = in_1.get()
             barrier[0] = True
        elif in_2._reader in inputs:
             _ = in_2.get()
             barrier[1] = True 
        if all(i for i in barrier):
             print("Barrier passed")
             return

q1 = multiprocessing.Queue()
q2 = multiprocessing.Queue()
process_list = [
    multiprocessing.Process(target=producer, args=("A", 1, q1)),
    multiprocessing.Process(target=producer, args=("B", 2, q2)),
    multiprocessing.Process(target=consumer, args=(q1, q2))
]

for p in process_list:
    p.start()

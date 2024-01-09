import multiprocessing
import select
import time

def producer(name, to_consumer):
    for i in range(3):
        time.sleep(0.5)
        to_consumer.put(f"{name} {i}")

def consumer(in_1, in_2):
    while True:
        (inputs, _, _) = select.select([in_1._reader, in_2._reader], [], [])
        if in_1._reader in inputs:
             message = in_1.get()
        elif in_2._reader in inputs:
             message = in_2.get()
        print(f"{message}")

q1 = multiprocessing.Queue()
q2 = multiprocessing.Queue()
process_list = [
    multiprocessing.Process(target=producer, args=("A", q1)),
    multiprocessing.Process(target=producer, args=("B", q2)),
    multiprocessing.Process(target=consumer, args=(q1, q2))
]
for p in process_list:
    p.start()

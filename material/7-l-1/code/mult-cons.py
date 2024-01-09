import multiprocessing
import time

PRODUCTION_COUNT = 4
KILL = "kill"

def producer(to_consumer):
    for i in range(PRODUCTION_COUNT):
        #time.sleep(0.5)
        to_consumer.put(f"Message {i}")
    to_consumer.put(KILL)
    to_consumer.put(KILL)

def consumer(name, from_producer):
    while True:
        message = from_producer.get()
        if message == KILL:
             print(f"{name} killed")
             return
        print(f"{name}: {message}")

q = multiprocessing.Queue()
process_list = [
    multiprocessing.Process(target=producer, args=(q,)),
    multiprocessing.Process(target=consumer, args=("A", q)),
    multiprocessing.Process(target=consumer, args=("B", q))
]

for p in process_list:
    p.start()
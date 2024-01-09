import multiprocessing
import time

PRODUCTION_COUNT = 4

def producer(to_consumer):
    for i in range(PRODUCTION_COUNT):
        time.sleep(0.5)
        to_consumer.put(f"Message {i}")

def consumer(from_producer):
    while True:
        message = from_producer.get()
        print(message)

q = multiprocessing.Queue()
process_list = [
    multiprocessing.Process(target=producer, args=(q,)),
    multiprocessing.Process(target=consumer, args=(q,))
]

for p in process_list:
    p.start()

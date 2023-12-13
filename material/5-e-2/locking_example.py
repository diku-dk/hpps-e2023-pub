
import threading
import time

def my_thread(my_i, my_lock):
    my_lock.acquire()
    print(f"Thread {my_i} is starting")
    time.sleep(1)
    print(f"Thread {my_i} is done")
    my_lock.release()


lock = threading.Lock()
threads = [threading.Thread(target=my_thread, args=(i, lock)) for i in range(2)]
for thread in threads:
    thread.start()
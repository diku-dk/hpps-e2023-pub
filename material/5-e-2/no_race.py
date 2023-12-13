
import random
import socket
import threading
import time

def client_thread():
    while (1):
        time.sleep(random.randint(1, 10))
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
            client_socket.connect(("127.0.01", 12345))
            client_socket.sendall(b'1')

            msg = client_socket.recv(4)
            handle_count = int.from_bytes(msg, 'big')
            handle_count += 1
            msg = handle_count.to_bytes(4, 'big')

            client_socket.sendall(msg)

def server_thread():
    handle_count = 0

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind(("127.0.0.1", 12345))
        server_socket.listen()
    
        while 1:
            connection, _ = server_socket.accept()
            with connection:
                _ = connection.recv(1)

                msg = handle_count.to_bytes(4, 'big')
                connection.sendall(msg)
                msg = connection.recv(4)
                handle_count = int.from_bytes(msg, 'big')
                handle_count = handle_count
                print(handle_count)

if __name__ == "__main__":
    client_and_server = [
        threading.Thread(target=client_thread, args=()),  
        threading.Thread(target=server_thread, args=())
    ]
    for thread in client_and_server:
        thread.start()

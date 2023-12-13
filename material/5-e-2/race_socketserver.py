
import random
import socket
import socketserver
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
            # Depending on your system, you might need to induce a race condition by 
            # uncommenting the following sleep statement. This is the only change 
            # you're allowed to make to this function
            #time.sleep(1)
            msg = handle_count.to_bytes(4, 'big')

            client_socket.sendall(msg)


class MyHandler(socketserver.StreamRequestHandler):
    def handle(self) -> None:
        _ = self.request.recv(1)

        msg = self.server.handle_count.to_bytes(4, 'big')
        self.request.sendall(msg)
        msg = self.request.recv(4)
        handle_count = int.from_bytes(msg, 'big')
        self.server.handle_count = handle_count

        print(self.server.handle_count)

class MyServer(socketserver.ThreadingTCPServer):
    def __init__(self, server_address, request_handler_class):
        super().__init__(server_address, request_handler_class)
        self.handle_count = 0
        self.lock = threading.Lock()

if __name__ == "__main__":
    clients = [
        threading.Thread(target=client_thread, args=()) for _ in range(12)
    ]
    for client in clients:
        client.start()
    with MyServer(("127.0.0.1", 12345), MyHandler) as my_server:
        try:
            my_server.serve_forever()
        finally:
            my_server.server_close()
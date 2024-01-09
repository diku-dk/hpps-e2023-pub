import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5678
MSG_MAX_SIZE = 256

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((SERVER_IP, SERVER_PORT))
    request = bytearray("Hello World".encode())
    s.sendall(request)
    response = s.recv(MSG_MAX_SIZE)
    print(response)
    s.close()

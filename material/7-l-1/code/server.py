import socket

SERVER_IP = "127.0.0.1"
SERVER_PORT = 5678
MSG_MAX_SIZE = 256

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((SERVER_IP, SERVER_PORT))
    s.listen(1)
    while True:
        conn, addr = s.accept()
        with conn:
            data = conn.recv(MSG_MAX_SIZE)
            conn.sendall(data)

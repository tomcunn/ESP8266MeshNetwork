#!/usr/bin/env python

import socket
import time


TCP_IP = '192.168.0.173'
TCP_PORT = 10000
BUFFER_SIZE = 3  # Normally 1024, but we want fast response
data_to_send = bytearray(b'\x65\x66\x67\x68')

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
#Start listening for clients to connect, the number specifies the number of clients
#allowed before it refuses more connections. 
s.listen(5)
print('Checking for clients')

Accepting_Clients = True
Client_List = []

while (Accepting_Clients):
    #This s.accept is blocking meaning it waits until another connection is made
    conn, addr = s.accept()
    print('A new Connection was made!!!!!')
    print('Connection address:', addr)
    print('Connection name:' , conn)
    print('......')
    Client_List.append(conn)
    if(len(Client_List) == 3):
       Accepting_Clients = 0
print('All of the clients have been accepted, here is the list')
print('.......................................................')
print(Client_List)

#try to send the first client to connect a message
Client_List[0].send(data_to_send)
Client_List[1].send(data_to_send)
Client_List[2].send(data_to_send)
print('-----------------------------------------------------')
print('Sent data to each client in the list without error')
#close out the complete socket
s.close()

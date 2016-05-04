#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   cdos
#   E-mail  :   tommyhey@163.com
#   Date    :   16/04/25 14:21:15
#   Desc    :   
#

import socket
import os
PORT = 10000
BUFSIZE = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', PORT))
s.listen(1);
while True:
    conn, addr = s.accept()
    data = conn.recv(PORT)
    conn.send('Connected to server[%s] from client[%s]\n' %(os.getpid(), addr))
    conn.close()
s.close()


#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   cdos
#   E-mail  :   tommyhey@163.com
#   Date    :   16/04/26 18:21:47
#   Desc    :   
#

import socket

s = socket.socket()
host = socket.gethostname()
port = 1234

s.bind((host, port))
s.listen(5)

while True:
    c, addr = s.accept()
    print 'Got connection from', addr
    c.send('Thank you for connectiong ...')
    c.close()

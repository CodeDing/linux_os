#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   cdos
#   E-mail  :   tommyhey@163.com
#   Date    :   16/04/26 18:23:56
#   Desc    :   
#

import socket

s = socket.socket()
host = socket.gethostname()
port = 1234

s.connect((host, port))
print s.recv(1024)

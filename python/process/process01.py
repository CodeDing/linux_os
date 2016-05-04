#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   cdos
#   E-mail  :   tommyhey@163.com
#   Date    :   16/04/26 15:38:57
#   Desc    :   
#
import os

print 'Process (%s) start ...' % os.getpid()
pid = os.fork()

if pid == 0:
    print "I am child process (%s) and my parent is %s." % (os.getpid(), os.getppid())
else:
    print "I (%s) just created a child process (%s)." % (os.getpid(), pid)


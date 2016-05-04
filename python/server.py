#!/usr/bin/env python
# -*- coding:utf-8 -*-
#
#   Author  :   cdos
#   E-mail  :   tommyhey@163.com
#   Date    :   16/05/03 14:49:03
#   Desc    :   
#

from bottle import get, run
 
@get('/')
def homepage():
    return '<p style="color:red">Hello World!</p>'

run(host='', port=25252)


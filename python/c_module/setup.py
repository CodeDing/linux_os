from distutils.core import setup, Extension
module1 = Extension('ext',
                    sources = ['ext.c'])
setup(name = 'ext',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])

from distutils.core import setup, Extension
from smtpd import usage

setup(name='mymodule01', 
      version='1.01',
      description='time string module for testing',
      license='MIT',
      author='a0z9',
      author_email='a0z9@rambler.ru',
      keywords=['test module', 'extra module for time strings', 'file from seminar'],
      url='https://github.com/a0z9/cpp_python_seminar/lib04/src',
      long_description = 'simple usage!',
      platforms = 'x64',  
      ext_modules=[Extension('mymodule01', ['mymodule01.c'])])


# run from shell:
# python setup.py install
#

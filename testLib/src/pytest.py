import ctypes
import os



class Book(ctypes.Structure):
    _fields_ = [('author',ctypes.c_char_p),
                ('title',ctypes.c_char_p),
                ('year', ctypes.c_int)]
    
    def __repr__(self):
        return'[{0}, {1}, {2}]'.format(self.author.decode(), self.title.decode(), self.year)

# not required in linux to add gcc path, but always need to add extra user libs
# if they are in different path than below lib (lib_for_python.dll)
os.add_dll_directory(r'C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin')

#your path to library
clib = ctypes.CDLL(r'C:\Users\And\eclipse-workspace-2021-luxoft\lib03\Debug\lib_for_python.dll')

print(clib)

print('-'*60)
print(clib.swap)
a = ctypes.c_int64(100)
b = ctypes.c_int64(2)

print("a=%6s, b=%6s" % (a.value, b.value))
clib.swap(ctypes.byref(a), ctypes.byref(b))
print("a=%6s, b=%6s" % (a.value, b.value))
print('-'*60)

# start Test Book structure  ---------------------------------------------------

print(clib.gen_book)

clib.gen_book.argtypes = [ctypes.c_char_p,ctypes.c_char_p,ctypes.c_int]
clib.gen_book.restype = ctypes.POINTER(Book)

buf1 = ctypes.create_string_buffer(56)
buf1.value = b'Jack London'
buf2 = ctypes.create_string_buffer(50)
buf2.value = '"Белое безмолвие"'.encode('utf8')

book1 = clib.gen_book(buf1,buf2,1976)
print(book1)
print(book1.contents)

# free memory occupied by book
clib.free_book(book1)
print('-'*60)
# end of Test Book structure
# get time string from c --------------------------------------------------------

from enum import IntEnum
     
class menum(IntEnum):
    sec=0
    millis=1
    micro=2
    nano=3

clib.time_str.argtypes = [ctypes.c_size_t]
clib.time_str.restype = ctypes.POINTER(ctypes.c_char)

# create and return string from external lib
print(clib.time_str)
pstr = clib.time_str(menum.micro)
   
print(pstr)    
print("time_str:", ctypes.cast(pstr, ctypes.c_char_p).value.decode())

# free memory occupied by string
clib.rm_time_str(pstr)
print('-'*60)
# start array test --------------------------------------------------------------------

print(clib.sum)
darr = (1.0,2.0,3,4.0,5,6,7,8,9,10)
Nd = len(darr)

cdarr =(ctypes.c_double*Nd)()
cdarr[:] = darr
clib.sum.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.c_int]
clib.sum.restype = ctypes.c_double

print("sum of 10 = ",clib.sum(cdarr,Nd))
print('-'*60)
## --------------------------------------------------------------------------------------



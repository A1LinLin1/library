from Crypto.Util.number import *


    
a=bytes_to_long(b'hello')
print(a)
print(long_to_bytes(a))
print(long_to_bytes(a).decode('utf-8'))
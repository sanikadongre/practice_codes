def swap_bits(num):

even = num & 0xAAAAAAAA
odd = num & 0x55555555
even >>=1
odd <<= 1
out = even|odd
return out

num = 56
output = swap_bits(num)
print(output)

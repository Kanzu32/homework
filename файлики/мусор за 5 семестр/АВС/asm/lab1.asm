; (3x^2-x+8)/(3(x-1)) 4 <= x <= 11
rd 0x0
cmp #3
jnc error
cmp #11
jc error

sub #1
mul #3
wr r1

rd 0x0
wr r0
mul r0
mul #3
sub r0
add #8

div r1
wr 0x1
rd r7
cmp #0
jnz overflow

rd #0x0
wr 0x2
ret

overflow:
rd #0x0F
wr 0x2
ret

error:
rd #0xFF
wr 0x2
ret
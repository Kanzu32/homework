rd #0
wr 0x0
wr 0x1
wr 0x2
wr 0x3
wr 0x4
wr 0x5

rd #0b111
out 0x42

rd #1
out 0x14
out 0x24
rd #0b00101101
out 0x16
rd #0b00111101
out 0x26
rd #0b01000
out 0x17
out 0x27

ei

loop:
nop
jmp loop


incr_1:
rd 0x0
add #1
cmp #10
wr 0x0
jnz skip1
rd #0
wr 0x0

rd 0x1
add #1
cmp #10
wr 0x1
jnz skip1
rd #0
wr 0x1

rd 0x2
add #1
cmp #6
wr 0x2
jnz skip1
rd #0
wr 0x2

rd 0x3
add #1
cmp #10
wr 0x3
jnz skip1
rd #0
wr 0x3

rd 0x4
add #1
cmp #6
wr 0x4
jnz skip1
rd #0
wr 0x4
skip1:
rd r7
cmp #0
jnz rt1
call display_write
rt1:
iret

cmd:
in 0x41
cmp #1
jnz next
rd #0
wr r7
jmp brk

next:
cmp #2
jnz next2
rd #1
wr r7
jmp brk

next2:
cmp #3
jnz next3
rd r7
cmp #0
jnz scnd
rd #0b00101101
out 0x16
rd #0b01000
out 0x17
jmp brk
scnd:
rd #0b00111101
out 0x26
rd #0b01000
out 0x27
jmp brk

next3:
cmp #4
jnz next4
rd r7
cmp #0
jnz scnd2
rd #0b00100001
out 0x16
rd #0b00000
out 0x17
call fill0
call display_write
jmp brk
scnd2:
rd #0b00110001
out 0x26
rd #0b01000
out 0x27
call fill0
call display_write
jmp brk

next4:
cmp #5
jnz next5
call fill0
jmp brk

next5:
cmp #6
jnz brk
rd r7
cmp #0
jnz scnd3
rd #0b00100001
out 0x16
rd #0b00000
out 0x17
jmp brk
scnd3:
rd #0b00110001
out 0x26
rd #0b00000
out 0x27
brk:
iret

incr_2:
rd 0x10
add #1
cmp #10
wr 0x10
jnz skip2
rd #0
wr 0x10

rd 0x11
add #1
cmp #10
wr 0x11
jnz skip2
rd #0
wr 0x11

rd 0x12
add #1
cmp #6
wr 0x12
jnz skip2
rd #0
wr 0x12

rd 0x13
add #1
cmp #10
wr 0x13
jnz skip2
rd #0
wr 0x13

rd 0x14
add #1
cmp #6
wr 0x14
jnz skip2
rd #0
wr 0x14
skip2:
rd r7
cmp #1
jnz rt2
call display_write
rt2:
iret

fill0:
rd #5
wr r6
rd r7
cmp #0
jz frst
rd r6
rd #0x15
wr r6
frst:
rd #0
wr -@r6
rd r6
cmp #0
jnz frst
ret

display_write:
rd #4
wr r6
rd #0
out 0x44 ; 0
rd r7
cmp #0
jz first
rd #0x14
wr r6
rd 0x42
out 0x44 ; 2
jmp print
first:
rd 0x41
out 0x44 ; 1
print:
rd #0
out 0x44

rd @r6-
add #0x40
wr r0
rd @r0
out 0x44

rd @r6-
add #0x40
wr r0
rd @r0
add #1 ; .
out 0x44

rd @r6-
add #0x40
wr r0
rd @r0
out 0x44

rd @r6-
add #0x40
wr r0
rd @r0
add #1
out 0x44

rd @r6-
add #0x40
wr r0
rd @r0
out 0x44

ret



.org 4
.dw incr_2

.org 2
.dw incr_1

.org 8
.dw cmd

.c 2
.org 0x40
.db  0b01111110, 0b00001100, 0b10110110, 0b10011110, 0b11001100, 0b11011010, 0b11111010, 0b00001110, 0b11111110, 0b11011110

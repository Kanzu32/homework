stack1 segment stack "stack"
    db 20 dup(?)
stack1 ends

data1 segment
    A db 111b
data1 ends

data2 segment
    pr dd t1
data2 ends
    
data3 segment
    B db 101b
data3 ends

code1 segment
t1: mov ax, data1
    mov ds, ax
    assume ds:data1

    mov bl, A
    rcr bl, 3 ;CF = 1

    jmp far ptr t2

code1 ends

code2 segment
t2: mov ax, data3
    mov ds, ax
    assume ds:data3

    mov bh, B
    rcr bh, 5 ;CF = 0

    jmp far ptr exit
    
code2 ends

code3 segment
begin:
    assume ss:stack1, ds:data1,  cs:code3
    mov ax, data1
    mov ds, ax

    shl A, 1 ;0000 1110

    mov ax, data3
    mov ds, ax
    assume ds:data3

    shr B, 2 ;0000 0001

    mov ax, data2
    mov ds, ax
    assume ds:data2

    jmp ds:pr

exit: mov ah, 4ch
    int 21h
   
code3 ends

end begin
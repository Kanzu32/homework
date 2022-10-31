d_s segment 
    arr DW 18 dup(?)
    i DW ?
    j DW ?
    min DW 0
    max DW 0
d_s ends

c_s segment
    assume ss:s_s, ds_d:ds_d, cs:c_s 
begin:

    mov ax, d_s
    mov ds, ax
    xor ax, ax 

    mov si, 2
    mov ax, si
    mov cx, 16 

    mov arr, 0
    mov arr + 2, 1 
FIB:
    mov si, ax
    shl si, 1; * 2
    sub si, 4 
    mov bx, arr-si
    add si, 2
    add bx, arr-si
    add si, 2
    mov arr+si, bx
    inc ax
    mov min, bx
    loop FIB


    
    mov cx, 6
    mov i, 1 
    mov j, cx
    mov ax, 1500
WH1:
    mov si, cx
    dec si 
    shl si, 1; *2
    mov bx, arr + 12 + si
    mov dx, bx
    shr dx, 1
    jc IF1 
    loop WH1 
    jmp endWH1

IF1:
    cmp bx, ax
    jl A1 
    loop WH1
    jmp endWH1 
    
A1:
    mov ax, bx
    loop WH1

endWH1:

    mov min, ax 
    xor bx, bx
    xor dx,dx
    ; arr + stroka * razmer * i + j * razmer 
    ; arr + 6 * 2 * i + 8  <=> 12 * si + 8  
     
   
     
    mov cx, 3
    mov j, 1
    mov i, cx
    mov dx, 0
WH2:
    mov si, cx
    dec si 
    
    mov max, dx
    mov ax, si                                                            
    mov bx, 12
    imul bx
    mov dx, max
    
    mov si, ax
    
    mov bx, arr + 6 + si
    mov ax, bx
    shr ax, 1
    jnc IF2 
    loop WH2 
    jmp endWH2
    
IF2:
    cmp bx, dx
    jg A2 
    loop WH2
    jmp endWH2
     
    
A2:
    mov dx, bx
    loop WH2

endWH2: 
    
    mov max, dx


    mov ah, 4ch
    int 21h

c_s ends
end begin



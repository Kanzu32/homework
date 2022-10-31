d_s segment
    a db 9h
    b db 9h
    nod db 1h
    kol db 0
    
d_s ends
begin:
c_s segment  
    assume ss:s_s, ds_d:ds_d, cs:c_s 
       
       

    mov ax, d_s
    mov ds, ax
    
    mov ah, a
    mov al, b
    
    
    cmp ah, al
    je endd
while:    
    cmp ah, 0
    jng end1; ah <= 0 
    mov nod, ah
    cmp ah, al
    jg u1; ah > al
    jmp else; ah <= al
    jmp while
    
u1: 
    sub ah, al
    jmp while
     
else:
    xchg ah, al
    jmp u1
     
end1:
    mov ah, nod 
    
endd:
    mov nod, ah
    
while2:
     cmp ah, 0
     je end2; ah = 0 
     shr ah, 1
     jc u2
     jmp while2 
     
u2:
    add kol, 1;
    jmp while2    
     
end2:
    mov dl, kol
    
      
    mov ah, 4ch
    int 21h
     
c_s ends
end begin



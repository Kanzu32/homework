s_s segment stack "stack"
    db 20 dup(?)
s_s ends

d_s1 segment
    chis db 101b
d_s1 ends

d_s2 segment
    pr dd 0h
d_s2 ends
    
d_s3 segment
    chis1 db 100b
d_s3 ends

c_s1 segment
assume ss:s_s, ds:d_s2, cs:c_s3      

mov chis, 10b

m1:
 
mov ax, d_s1
mov ds,ax

mov bl, chis

rcr bl, 3

mov ax, d_s2
mov ds, ax

mov pr+2, c_s2
mov pr, 0h

jmp dword ptr pr

                  
c_s1 ends
         
         

c_s2 segment
  
 
mov ax, d_s3
mov ds,ax

mov bh, chis1

rcr bh, 5

mov ax, d_s2
mov ds,ax  

mov pr+2, c_s3
mov pr, m2

jmp dword ptr pr
   
    
c_s2 ends



c_s3 segment
begin:
assume ss:s_s, ds:d_s1,  cs:c_s3


shl chis, 1

mov ax, d_s3
mov ds, ax

shr chis1, 2

mov ax, d_s2
mov ds, ax


mov pr+2, c_s1
mov pr, m1 

jmp dword ptr pr

m2: 
mov ah, 4ch
int 21h
   
c_s3 ends

end begin







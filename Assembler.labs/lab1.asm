d_s segment                     

data1 db 10, 27         
data2 db 0101B
el db 3                                 

sum db 0
raz db 0
pr dw 1  


mod1 db 0
divv db 0

d_s ends
c_s segment
assume ds:d_s,cs:c_s 

begin:  

 mov ax,d_s       
 
 
 mov ds,ax               
 
 
 mov dl,data1     ;10+27          
 
 add dl,data1+1           
 
 mov sum,dl
 

 mov al, data1; 10 - 27 signed
 
 sub al, data1+1


 mov raz, al

 
 neg data1+1; 10 - (-27)
 
 mov al, data1
 
 sub al, data1+1
 
 mov raz, al
 
 
 mov al, data1 ; 10 * (-27)
 
 imul data1+1
 
 mov pr, ax
 
 
 neg data1+1 ; 10/27
 
 mov al, data1  
 mov ah, 0h
 
 div data1+1
 
 mov mod1, ah
 mov divv, al
 
 
 mov el, 3
 or al, el
 not al
 mov el, 7
 not el
 and al, el
 
 mov dl, al
 xor dl, al
 
 
 
 mov ah,4ch             
 
 int 21h                    
c_s ends                   
end begin                


        
        




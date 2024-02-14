; Сложение упакованных десятичных чисел с клавиатуры в память
rd #0b111
out 0x01 ; вкл приёма в буфер и формирований запросов на прерывания в строчном режиме

rd #0x20 ; адрес записи
wr r1
wr r0

ei

loop:
nop
jmp loop

correct: ; r0 начало r1 конец+1 r3 перебор
wr @r1+
rd r1
sub #1
wr r3
lp:
rd -@r3 ; перенос из i-1 в i
and #0x0F
mul #16
add +@r3
wr @r3-

rd @r3 ; изменение i-1
and #0xF0
div #16
wr @r3

rd r3
cmp r0
jnz lp

jmp input_end

sum: ; обработчик прерываний клавиатуры
in 0x00
cmp #0x2F
jnc end
cmp #0x39 ; проверка на числа
jc end
sub #0x30
wr r2
sbis 0x02, 1 ; если последний символ в разряде единиц
jmp correct ; откорректировать
mul #16 ; преобр в упакованный формат
wr r2
sbic 0x02, 1
in 0x00
cmp #0x2F
jnc end
cmp #0x39
jc end
sub #0x30
add r2
wr @r1+
input_end:
sbic 0x02, 1
jmp sum
call reverse
end:
iret

reverse: ; r0 начало, r2 кол-во/2, r3 индекс, r4 tmp, r5 левый индекс, r6 правый индекс
rd r1
sub r0
div #2
wr r2
rd #0
wr r3
swp:
rd r0
add r3
wr r5
rd @r5
wr r4
rd r1
sub r3
sub #1
wr r6
rd @r6
wr @r5
rd r4
wr @r6

inc r3
rd r3
cmp r2
jnz swp
rd r1
cmp #0x2F
jnn endr
call calc
jmp exit
endr:
rd #0x30
wr r1
wr r0
ret

calc: ; r0 счётчик r1 ссылка 1 r2 рез
rd #0
wr r0
wr r2
next:
rd #0x20
add r0
wr r1
rd @r1
wr r2
rd #0x30
add r0
wr r1
rd @r1
sbs 0x10, 0 ; если нет переноса
jmp m1 ; пропустить
add #1
cb 0x10, 0 ; сбросить перенос

m1:
add r2 
daa
jnc m2 ; если нет нового переноса не устанавливаем бит
sb 0x10, 0
m2:
wr r2
rd #0x40
add r0
wr r1
rd r2
wr @r1
inc r0
rd r0
cmp #0x0F
jnn next
ret

exit:
hlt

.org 2
.dw sum
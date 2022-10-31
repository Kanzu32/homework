_TEXT SEGMENT
ASSUME CS:_TEXT
start:
    mov ax, _DATA
    mov ds, ax

    lea dx, [txt1]
    mov ah, 09h
    int 21h

    mov ax, _DAT2
    mov ds, ax

    lea dx, [txt2]
    mov ah, 09h
    int 21h

    jmp far ptr far_away

_TEXT ENDS

_TEXT2 SEGMENT
ASSUME CS:_TEXT2
far_away:
    mov ax, _DAT3
    mov ds, ax

ASSUME DS:_DAT3
    mov dx, example
    mov ah, 02h
    int 21h
    xchg dh, dl
    int 21h
    mov dl, 13
    int 21h
    mov dl, 10
    int 21h

    lea dx, [txt3]
    mov ah, 09h
    int 21h

    mov ax, 4C00h
    int 21h
_TEXT2 ENDS

_DATA SEGMENT
ORG 0FF00h
    txt1 DB "TXT_1", 13, 10, '$'
_DATA ENDS

_DAT2 SEGMENT
ORG 0FF00h
    txt2 DB "TXT_2", 13, 10, '$'
_DAT2 ENDS

_DAT3 SEGMENT
ORG 0FF00h
    example DW 'ab'
    txt3 DB "TXT_3", 13, 10, '$'
_DAT3 ENDS

_STACK SEGMENT STACK 'STACK'
      DW  1000h dup(?)
_STACK ENDS

END start
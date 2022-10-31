format PE64 GUI
; format PE GUI 4.0
; include 'win32a.inc'
entry @start

@start:
        int3
        mov eax, 3
        ret
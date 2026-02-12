; main.asm
bits 16
org 0x7C00          ; BIOS loads boot sector here

; --- Compute 5 + 10 ---
mov ax, 5
mov bx, 10
add ax, bx          ; AX = 15

; --- Convert AX to two digits ---
mov bx, 10
xor dx, dx          ; clear DX for division
div bx              ; AX ÷ 10 → quotient in AX, remainder in DX
                    ; AX = tens digit, DX = ones digit

; --- Print tens digit ---
add al, '0'         ; convert to ASCII
mov ah, 0x0E
int 0x10

; --- Print ones digit ---
mov al, dl          ; move remainder to AL
add al, '0'         ; convert to ASCII
mov ah, 0x0E
int 0x10

jmp $               ; infinite loop

; --- Boot sector padding ---
times 510-($-$$) db 0
dw 0xAA55           ; boot signature



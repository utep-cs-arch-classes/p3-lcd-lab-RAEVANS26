    .arch msp430g2553
    .p2align 1,0
    .text
    
    .extern drawDiamond
    .extern color

jmp_table:
    .word case0 ;red diamond
    .word case1 ;green diamond
    .word case2 ;gold diamond
    .word case3 ;lime green diamond
    
    .global color_diamond
color_diamond:
    mov.b &color, r12
    add.b r12, r12
    mov jmp_table(r12), r0
    
case0:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0x001f, r14 ;red
    call #draw_diamond
    add.b #1, &color
    jmp end

case1:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0x0320, r14 ;dark green
    call #draw_diamond
    add.b #1, &color
    jmp end
    
case2:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0x06bf, r14 ;gold
    call #draw_diamond
    add.b #1, &color
    jmp end
    
case3:
    mov.b #60, r12
    mov.b #60, r13
    mov.b #0x3666, r14 ;lime green
    call #draw_diamond
    mov.b #0, &color
    jmp end

end: 
    pop r0
    
    

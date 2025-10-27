.data
    arr_A: .word 0, 1, 2, 7,-8, 4, 5, 12, 11,-2
    arr_B: .word 0, 0, 0, 0, 0, 0, 0, 0,   0, 0

    
.text
.globl main
main:
    la a0, arr_A
    la a1, arr_B
    la a3, arr_B
    li a2, 0 # index for iterate in 'arr_A'
    # li a3, 0 # index for iterate in 'arr_B'
    li t0, 10
loop:
    lw t1, 0(a0)
    sw t1, 0(a1)
    addi a0, a0, 4
    addi a1, a1, 4
    addi a2, a2, 1
    blt a2, t0, loop
    
    li t1, 0 # index for iterate in 'arr_B' in printing

loop2:
    lw a4, 0(a3)
    addi a3, a3, 4
    addi t1, t1, 1
    blt t1, t0, loop2
    
    ret

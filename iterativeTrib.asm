.data
prompt0: .asciiz "Enter tribonacci(0): "
prompt1: .asciiz "Enter tribonacci(1): "
prompt2: .asciiz "Enter tribonacci(2): "
promptN: .asciiz "Enter n: "
equals:  .asciiz " = "


.text
main:
    # tribonacci(0)
    la $a0, prompt0
    li $v0, 4
    syscall
get_trib0:
    li $v0, 5
    syscall
    bltz $v0, get_trib0
    move $t0, $v0  # trib0 = $t0

    # tribonacci(1)
    la $a0, prompt1
    li $v0, 4
    syscall
get_trib1:
    li $v0, 5
    syscall
    bltz $v0, get_trib1
    move $t1, $v0  # trib1 = $t1

    # tribonacci(2)
    la $a0, prompt2
    li $v0, 4
    syscall
get_trib2:
    li $v0, 5
    syscall
    bltz $v0, get_trib2
    move $t2, $v0  # trib2 = $t2

    # n
    la $a0, promptN
    li $v0, 4
    syscall
get_n:
    li $v0, 5
    syscall
    bltz $v0, get_n
    move $t3, $v0  # n = $t3

    # Base cases
    li $t4, 0       
    beq $t3, 0, print_result 
    move $t4, $t0
    beq $t3, 1, print_result   
    move $t4, $t1
    beq $t3, 2, print_result 
    move $t4, $t2

    
    li $t5, 3       
loop:
    add $t6, $t0, $t1      # $t6 = n_minus_3 + n_minus_2
    add $t4, $t6, $t2      # $t4 = $t6 + n_minus_1
    move $t0, $t1          # trib_n_minus_3 = n_minus_2
    move $t1, $t2          # trib_n_minus_2 = n_minus_1
    move $t2, $t4          # trib_n_minus_1 = result
    addi $t5, $t5, 1       # i++
    bne $t5, $t3, loop     # continue if i != n 

print_result:

    # Print n
    move $a0, $t3
    li $v0, 1
    syscall

    # Print " = "
    la $a0, equals
    li $v0, 4
    syscall

    # Print result
    move $a0, $t4
    li $v0, 1
    syscall


    # Exit
    li $v0, 10
    syscall

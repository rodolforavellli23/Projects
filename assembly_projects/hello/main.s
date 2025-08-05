.section .data
hello:
    .ascii "\n\tHello World!\n"
hello_len = . - hello       # Calculate string length

.section .text
.global _start

_start:
    # Write system call
    mov $1, %rax            # Syscall number for write (1)
    mov $1, %rdi            # File descriptor 1 (stdout)
    mov $hello, %rsi        # Address of string
    mov $hello_len, %rdx    # Length of string
    syscall                 # Invoke system call

    # Exit system call
    mov $60, %rax           # Syscall number for exit (60)
    xor %rdi, %rdi          # Exit status code 0
    syscall                 # Invoke system call

####################################################
#  李晓峰，2020.8.5
#
#  此程序利用指令 gcc -S -m32 hello.c
#  把helloworld的C语言程序，生成helloworld的汇编程序
#  然后对生成的汇编程序进行了修改而成。
#  程序来源于：https://en.wikibooks.org/wiki/X86_Assembly/GAS_Syntax
#
####################################################

        .text
  
LC0:
         .ascii "Hello, world!\12\0"
 .globl _main
 _main:
        pushl   %ebp
        movl    %esp, %ebp
        subl    $8, %esp
        andl    $-16, %esp
        movl    $0, %eax
        movl    %eax, -4(%ebp)
        movl    -4(%ebp), %eax
        call    __alloca
        call    ___main
        movl    $LC0, (%esp)
        call    _printf
        movl    $0, %eax
        leave
        ret
		
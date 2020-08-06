# ----------------------------------------------------------------------------------------
# Writes "Hello,world." to the console using a C library. Runs on Linux or any other system
# that does not use underscores for symbols in its C library. To assemble and run:
#
#     gcc hola.s && ./a.out
# ----------------------------------------------------------------------------------------
# ####################################################
#  李晓峰，2020.8.5
#
#  进行修改，并添加注释。
#
####################################################
        .global main
		
        .text
main:                                  # This is called by C library's startup code
		#去掉下面这句话，因为我们用的32位编译，rdi寄存器是64位寄存器
        #mov    $message,%rdi          # First integer (or pointer) parameter in %rdi
		movl    $message, (%esp)  #将要打印的字符装入esp
        call    _printf                 # 调用printf函数
        ret                             # Return to C library code
message:
        .asciz "Hello,world.\n"            # asciz puts a 0 byte at the end
		
		
# C_samplecode

## 介绍
根据在给不同年级授课时的情况，整理一些C语言的示例代码，供大家参考，内容会不断更新。
大多数时候，初学者学完C语言后会有一种感觉，那就是是好像都看懂了，练习也做了，但是还是不能去完成一个任务，或者说实际去做些项目。
这里，需要大家理解，C语言是一门语言，是一门与计算机交互的语言，所以你想要去操作计算机（也就是我们说的做些项目），除了了解C语言本身，你也必需了解你所要操作的计算机给你提供了什么样的操作接口也是非常重要的（这部分以API或者库的形式体现，比如windows API，GNU lib），而大家感觉做不出什么东西，就是因为缺少第二类知识，这部分知识，你最直接的方式是去看相关的官网文档。
## Xiaofeng's web
http://buuer_xxtxiaofeng.gitee.io/lxf/

## 编译环境
C语言最终是要编译为机器码来执行的。
C语言首先要明确你的编译器，然后选择一个你喜欢的编辑器，或者IDE(把编译器和编辑器集成了)。
当然还有一些重要的工具，比如调试工具等等。
本仓库的示例代码均在Windows 10操作系统中，使用gcc测试通过。
## 声明
有些示例中把在本机上编译后的exe文件也上传了，但是好像有些杀毒软件说有木马。
初步判断是预报，理由：
1、我没有去下马。
2、源程序没有调别的第三方库。
3、gcc是从官网上下的。

## 示例代码说明

每一个目录里面都是一个独立的示例代码，下面对仓库中的示例代码进行简单说明。
### Helloworld
最简单的示例，输出“Hello C World”，看看基本编译环境是否ok。
### runwithpar
示例如何编写带参数运行的程序，也就是如何在程序中获取这些参数。
### multc
示例如何在源程序级别分模块，就是分为多个.c进行程序设计。
### runcmd
示例如何在程序中运行一个命令。
### colortext
示例如何在windows的终端（console）尽心输出文本的颜色控制。此示例使用的windows API。
### FunPointer
示例函数指针的基本定义和使用。
### dynloadlib
示例如何动态加载一个动态库，并调用动态库中的某个函数，这是设计一些具有动态加载模块系统的重要技术手段。
### LFSR
示例如何实现一个最简单的循环移位寄存器，这是流密码实现的关键。
### usegmp
示例如何使用大数库，并且示例计算 $2^{100}$ 。
### gmpwritefile
示例如何进行将大数库计算所得结果写入文件并读出。
### DUstruct
定义和使用结构体，此示例初始目的是为准备定义协议结构体数据的同学做参考。
### TCPSenRev
这是拷贝自微软网站上的示例代码，一个简单的TCP消息传输。
### firstGDI
示例如何使用windows的GDI库，进行绘图，GDI函数可以参考微软网站，给出一个参考链接https://docs.microsoft.com/zh-cn/windows/win32/gdi/windows-gdi

### FirstGTK
示例如何创建一个GKT-3.0的窗口程序Hello world！这是个GTK官网的示例程序，这个例子的重点是进行GTK开发环境的配置。
### FirstWindow
示例如何使用C语言创建一个窗体。
### FirstWinTextHello
示例如何在创建的窗体中输出红色文本。
### FirstWinDrawShape
示例如何在窗体中画一个椭圆。
### FirstWinMenu
示例如何创建一个有菜单的窗体。
### FirstWinMenuAct
示例如何创建一个带菜单的窗体，并且对菜单事件进行响应。

### FirstWinInteractive
示例如何使用菜单控制，来用鼠标在窗体中画出不同的填充图。

### getconsoleevent
示例如何获取windows终端中的键盘事件。
### showchineseselffont
示例点阵字库的原理，HZLIB.bin是一个点阵字库（但是不是windows中使用的标准字库，可以用到嵌入式系统，自己编写显示驱动），程序读取字库，用* 打出汉字。

### WinShowBMP
示例如何在窗体中显示一个bitmap文件，也就是如何将BMP文件加载到内存中，然后在窗体中绘制出来。
这是各种图片显示的基础。

### ShowBitmap
示例如何在终端中显示图片。在windows的自带的cmd中可以正常显示，也许在第三方的终端中无法显示。

### EnumFont
这是使用windows API EnumFontFamilies来枚举操作系统内安装的所有字体，
这里有一个回调函数EnumFamCallBack，当系统每次找到一个字体时，回调
此函数，此回调函数将字体名在终端打印出来。

### ShowFont
示例在窗体选择一个字体，显示文字。

### HookMessageBox
示例修改内存代码的方式，进行函数注入，实现MessageBoxA的钩子函数。

### HookCalc
示例如何利用Windows操作提供的机制，将一个动态连接库的函数，做为钩子函数挂在程序calc.exe的键盘消息处理的钩子上。这个钩子是操作系统为大家准备好的，便于系统扩展，与修改内存代码，进行函数注入的挂钩原理不同。

### compile64app
示例对一个简单的程序如何利用gcc编译位32位和64位的，同时此示例程序更加简单类型所占空间，可以看出是32位程序，还是64位程序。

### keyboardHook
示例如何利用windows 操作系统提供的机制，挂一个全局键盘钩子函数，示例中的钩子函数在一个dll中。

### changeentry
示例如何修改缺省的入口函数。

### asm-uselib
这是一个利用GNU gcc的assembler as 和linker ld做为工具，编写的汇编程序，gas（GNU as）汇编语言为AT&T，所以此程序也是使用这个语法，这个程序调用C库的printf，实现输出Hello world.

### catcherr-jmp
示例采用jmp的方法，通过宏定义，模拟C++等语言常用的try/catch错误捕获的方法。

### catcherr-assert
利用C语言的assert宏，抛出错误进行处理的示例。



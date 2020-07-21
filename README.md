# C_samplecode

#### 介绍
根据在给不同年级授课时的情况，整理一些C语言的示例代码，供大家参考，内容会不断更新。
#### Xiaofeng's web
http://buuer_xxtxiaofeng.gitee.io/lxf/
#### 编译环境
C语言最终是要编译为机器码来执行的。
C语言首先要明确你的编译器，然后选择一个你喜欢的编辑器，或者IDE(把编译器和编辑器集成了)。
当然还有一些重要的工具，比如调试工具等等。
本仓库的示例代码均在Windows 10操作系统中，使用gcc测试通过。
#### 声明
有些示例中把在本机上编译后的exe文件也上传了，但是好像有些杀毒软件说有木马。
初步判断是预报，理由：
1、我没有去下马。
2、源程序没有调别的第三方库。
3、gcc是从官网上下的。

#### 示例代码说明

每一个目录里面都是一个独立的示例代码，下面对仓库中的示例代码进行简单说明。
##### Helloworld
最简单的示例，输出“Hello C World”，看看基本编译环境是否ok。
##### runwithpar
示例如何编写带参数运行的程序，也就是如何在程序中获取这些参数。
##### multc
示例如何在源程序级别分模块，就是分为多个.c进行程序设计。
##### colortext
示例如何在windows的终端（console）尽心输出文本的颜色控制。此示例使用的windows API。
##### FunPointer
示例函数指针的基本定义和使用。
##### dynloadlib
示例如何动态加载一个动态库，并调用动态库中的某个函数，这是设计一些具有动态加载模块系统的重要技术手段。
##### LFSR
示例如何实现一个最简单的循环移位寄存器，这是流密码实现的关键。
##### usegmp
示例如何使用大数库，并且示例计算 $2^{100}$ 。
##### gmpwritefile
示例如何进行将大数库计算所得结果写入文件并读出。
##### DUstruct
定义和使用结构体，此示例初始目的是为准备定义协议结构体数据的同学做参考。
##### TCPSenRev
这是拷贝自微软网站上的示例代码，一个简单的TCP消息传输。
##### firstGDI
示例如何使用windows的GDI库，进行绘图，GDI函数可以参考微软网站，给出一个参考链接https://docs.microsoft.com/zh-cn/windows/win32/gdi/windows-gdi
##### FirstWindow
示例如何使用C语言创建一个窗体。
##### FirstWinTextHello
示例如何在创建的窗体中输出红色文本。
##### FirstWinDrawShape
示例如何在窗体中画一个椭圆。
##### FirstWinMenu
示例如何创建一个有菜单的窗体。
##### FirstWinMenuAct
示例如何创建一个带菜单的窗体，并且对菜单事件进行响应。

##### FirstWinInteractive
示例如何使用菜单控制，来用鼠标在窗体中画出不同的填充图。

##### getconsoleevent
示例如何获取windows终端中的键盘事件。
##### showchineseselffont
示例点阵字库的原理，HZLIB.bin是一个点阵字库（但是不是windows中使用的标准字库，可以用到嵌入式系统，自己编写显示驱动），程序读取字库，用* 打出汉字。



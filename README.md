# CPP-Training

## Route Planning Project
A route planner that plots path between two points on a map using real map data from the **[OpenStreetMap](https://www.openstreetmap.org/)** project.  
*The OpenStreetMap project is an open source, collaborative endeavor to create free, user-generated maps of every part of the world.*

## Debug
### 编译 Debug 模式
```gcc [other flags] -g <source files> -o <output file>```

-Wall 打印所有警告  
-Werror 将所有敬告视为错误  
-ansi 只支持ANSI标准的C语法  
-pedantic-errors 将所有不符合ISO标准的警告视为错误  

### gdb commands
`run`  
`backtrace`: produces a stack trace of the function calls that lead to a seg fault

`x <address>`: examine, get the value of an address

`break <func or file.xx:line>`: set break point

`condition 1 <condition>`: 设置第一个断点触发的条件

`step`：单步调试

`next`: 单行调试，不会跳到function 里面去

`print`

`watch my_var`: whenever my_var's value is modified，interrupt and print old&new value

`finitsh`: runs until the current function is finished

`info b`: display breakpoints

`delete`: deletes a specified breakpoint

`quit`
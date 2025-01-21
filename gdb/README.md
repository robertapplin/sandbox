# GNU Debugger (GDB)

Debugging using GDB from the command line:

```sh
gdb --args python test_script.py
break FrameworkManager.cpp:64
r          - means run
c          - continue to the next breakpoint
n          - move to next line
s          - step into 
fin        - return from the current function
list       - display the next couple of lines
exit       - exit the debugging session
```

Display the value of variables using GDB:

```sh
p <var_name>     - print the contents of the particular variable
p (*<var_name>._M_impl._M_start)@N      - print the next N elements in a vector. The _M_impl and _M_start attributes are in a different colour in the cmd line
p (*<var_name>._M_dataplus._M_p)@1      - print a string in the variable
p $2                                    - print the variable previously output in variable $2
```

``0x0`` tends to be a default memory location value meaning the vector or variable is empty. ``cannot access memory at address`` means the same

To change to a different thread and show the backtrace:

```sh
info threads
thread <id>
bt
```

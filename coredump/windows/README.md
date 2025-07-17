Build
#####

1. Configure and generate the project with:

```sh
cmake . -B build --preset win-vs
```

2. Build the project with:

```sh
cd build && cmake --build .
```

Windows Setup
#############

The key to this is to ensure when you build the executable, there are `.pdb` files which are generated alongside it.

1. Create a `.reg` file with the following contents:

```
Windows Registry Editor Version 5.00

[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\Windows Error Reporting\LocalDumps]
"DumpFolder"="C:\\CrashDumps"
"DumpCount"=dword:00000010
"DumpType"=dword:00000002   ; 2 = full dump, 1 = mini
```

2. Double click this file in the File Explorer to apply it

3. Run the project with:

```sh
cd build && ./CoredumpMain
```

4. Check for a `CoredumpMain.exe.<pid>.dmp` file in the current working directory, or `C:\CrashDumps`

5. Copy this `.dmp` file to the same directory as the `.pdb` files

6. From Visual Studio, open the `.dmp` file. Then select `Debug with Native Only` to see the call stack

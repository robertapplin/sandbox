Build
#####

1. Configure and generate the project with:

```sh
cmake . -B build --preset ninja
```

2. Build the project with:

```sh
cd build && cmake --build .
```

Linux Setup
###########

1. Check and then set the core dump size:

```sh
ulimit -c
ulimit -c unlimited
```

2. Customize where and how core dumps are saved:

```sh
sudo sysctl -w kernel.core_pattern=core.%e.%p
```

3. Run the project with:

```sh
cd build && ./CoredumpMain
```

4. Check for a `core.CoredumpMain.<pid>` file in the current working directory

5. Use `gdb` to inspect the crash:

```sh
gdb ./CoredumpMain core.CoredumpMain.<pid>
bt  # backtrace
info locals  # Show local variables
```


Description
###########

This directory provides several options for ensuring Qt code is executed on the GUI thread in the context of a threaded application.
Interacting with Qt widgets from outside the main thread can cause a crash. The base pattern used for the code is MVP.

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

3. Run the project with:

```sh
cd build
./option1/launch1
./option2/launch2
```


Conan - how it works
####################

1. Declare C++ libraries in `conanfile.py`; `conan install` fetches them.
2. Packages live in a global cache at `~/.conan2/p/`, shared across projects.
3. Each cache entry is keyed by a hash of version + compiler + build type + options.
4. Prebuilt binaries are downloaded if available; otherwise built from source (if `--build=missing` is provided).
5. `conan install` just generates CMake config files in `build/` pointing at the cache.
6. Build dependencies need installing separately. Using a virtual environment to install Conan is a good idea.

Getting Started
###############

Install Prerequisities

```sh
sudo apt update
sudo apt install build-essential cmake
```

Create a default Conan profile

```sh
conan profile detect --force
```

Open `~/.conan2/profiles/default` and ensure `compile.cppstd=20`

Build
#####

Install dependencies and generate build folder

```sh
conan install . --output-folder=_build --build=missing -s build_type=Release
```

Configure using the Conan-generated toolchain

```sh
cmake -S . -B _build -DCMAKE_TOOLCHAIN_FILE=_build/build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
```

Build the project

```sh
cmake --build _build -j
```

Run
###

Run the app

```sh
./_build/my_app
```

Run the tests

```sh
ctest --test-dir _build --output-on-failure
```

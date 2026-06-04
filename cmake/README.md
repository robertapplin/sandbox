# Visual Studio Native Support

The `CMakeLists.txt` are loaded directly. This means when a `CMakeLists.txt` is changed, Visual Studio will automatically reconfigure and generate.

1. Open Visual Studio
2. Select the directory containing the top-level `CMakeLists.txt` file
3. The first time you open, it will configure and generate the project
4. It will open in "Folder View". To build everything, select `Build`->`Build All`
5. When finished, you can "Select Startup Item" next to the green play button.

Note that `CMakePresets.json` is the modern way to configure your build.

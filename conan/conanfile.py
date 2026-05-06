from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMakeDeps, CMake, cmake_layout


class MyAppRecipe(ConanFile):
    name = "myapp"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"

    requires = ()

    test_requires = (
        "catch2/3.14.0"
    )

    def layout(self):
        return cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.variables["CMAKE_CXX_STANDARD"] = "20"
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

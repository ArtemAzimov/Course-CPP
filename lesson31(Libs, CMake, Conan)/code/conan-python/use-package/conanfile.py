from conans import ConanFile, CMake

class MyAppConan(ConanFile):
    requires = "package-lib/1.0@marat/jfrog"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake", "cmake_paths", "cmake_find_package"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def configure(self):
        self.options['package-lib'].shared = True 

    def imports(self):
        self.copy("*.dll", "", "bin")
        self.copy("*.dylib", "bin", "lib")
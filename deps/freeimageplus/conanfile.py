from conans import ConanFile, AutoToolsBuildEnvironment, tools

class FreeImagePlusConan(ConanFile):
    name = "freeimageplus"
    version = "3.18.0"
    license = "http://freeimage.sourceforge.net/freeimage-license.txt"
    description = "freeimageplus"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = "shared=False", "fPIC=True"
    generators = "cmake"

    def configure(self):
        if self.settings.os == "Windows":
            self.options.remove("fPIC")

    def source(self):
        zip_name = "FreeImage3180.zip"
        tools.download("https://downloads.sourceforge.net/project/freeimage/Source%20Distribution/3.18.0/FreeImage3180.zip", zip_name)
        tools.unzip(zip_name, destination=".")

    def build(self):
        autotools = AutoToolsBuildEnvironment(self)
        env_build_vars = autotools.vars
        env_build_vars['DESTDIR'] = self.package_folder
        with tools.environment_append(env_build_vars):
            if tools.detected_os() == "Macos":
                self.run("cd FreeImage && make -f Makefile.gnu -j {}".format(tools.cpu_count()))
            else:
                self.run("cd FreeImage && make -f Makefile.osx -j {}".format(tools.cpu_count()))
            self.run("cd FreeImage && make -f Makefile.fip -j {}".format(tools.cpu_count()))

    def package(self):
        self.copy("*.h", dst="include", src="FreeImage/Source")
        self.copy("*.h", dst="include", src="FreeImage/Wrapper/FreeImagePlus")
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.includedirs = ["include"]
        self.cpp_info.libdirs = ["lib"]
        self.cpp_info.libs = ["freeimage", "freeimageplus"]

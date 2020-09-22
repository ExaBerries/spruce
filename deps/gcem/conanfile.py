from conans import ConanFile, CMake, tools

class GCEMConan(ConanFile):
    name = "gcem"
    description = "gcem"
    url = "https://github.com/kthohr/gcem.git"
    homepage = url
    license = "Apache-2.0"
    exports = "LICENSE"
    version = "1.12.0"

    def source(self):
        git = tools.Git()
        git.clone(self.url)
        git.checkout("tags/v{}".format(self.version))

    def package(self):
        cmake = CMake(self)
        cmake.configure(build_dir="build")
        cmake.install()

        self.copy(pattern="LICENSE.txt", dst="licenses")

    def package_id(self):
        self.info.header_only()

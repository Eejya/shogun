import os
import subprocess
import sys
from setuptools import setup,find_packages
from distutils.command.build import build as _build
from distutils.command.install import install as _install

def read(fname):
    return open(os.path.join(os.path.dirname(__file__), fname)).read()

class ConfigureAndInstallShogun(_install):
    def build_directory(self):
        if not os.path.exists("./build_test"):
            print("Created directory")
            os.makedirs("./build_test")
        os.chdir("./build_test")   
    def cmake_build(self):
        if subprocess.call(["cmake", "..", "-DPythonModular=ON"]) != 0:
            raise EnvironmentError("error calling cmake")
    def make(self):
        if subprocess.call(["make"]) != 0:
            raise EnvironmentError("error calling make")
    def make_install(self):
        if subprocess.call(["make install"]) != 0:
            raise EnvironmentError("error calling make")    
    def run(self):
        self.build_directory()
        #self.cmake_build()
        #self.make()
        _install.run(self)
       
setup(
    name = "Shogun machine learning toolbox",
    version = "4.1.0",
    author = "Shogun team",
    author_email = "shogun-list@shogun-toolbox.org",
    description = ("Shogun is a free, open source toolbox written in C++, offering numerous algorithms and data structures for machine learning problems."),
    license = "GPL",
    keywords = "Trial pypi shogun package",
    url = "http://www.shogun-toolbox.org/page/home/",
    packages=find_packages(),
    long_description=read('README.md'),
    cmdclass={
          'install' : ConfigureAndInstallShogun,
          }
)
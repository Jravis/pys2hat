from distutils.core import setup, Extension
import numpy as np

module1 = Extension('pures2hat',
                    sources = ['pys2hat/pyc_pures2hat.c'],
                    include_dirs = ['s2hat','pure_s2hat'],
                    library_dirs = ['s2hat','pure_s2hat'],
                    libraries = ['s2hat','s2hat_pure'])

setup (name = 'pys2hat',
       version = '0.1',
       description = 's2hat with ure-s2hat E/B separation for CMB polarization maps',
       include_dirs = [np.get_include()],
       ext_modules = [module1])

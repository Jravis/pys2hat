AC_INIT([PyXPure], 0.1, [rwogburn@gmail.com])
AM_INIT_AUTOMAKE

# Checks for programs. These may set default variables, such as CFLAGS
# AC_PROG_CC
# AC_PROG_FC
AC_PROG_RANLIB

# Use the C language and compiler for the following checks
AC_LANG([C],[F90])

# Checks for libraries.
AX_PROG_FC_MPI
AX_PROG_CC_MPI

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])

# Check for Python compiler.
AC_PATH_PROG(PYTHON, python)

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

AC_CONFIG_FILES([Makefile
                 s2hat/Makefile
                 pure_s2hat/Makefile])

AC_OUTPUT

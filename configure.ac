AC_INIT([PyS2Hat], 0.1, [rwogburn@gmail.com])
AM_INIT_AUTOMAKE

# Use the C and Fortran language and compiler for the following checks
AC_LANG(C)

# --------------------------------------------
# Check whether we are to use real MPI installation or MPI stubs
# --------------------------------------------
AC_ARG_ENABLE(
[mpi],
[  --enable-mpi           Enable use of MPI (default: disabled)],
[case "${enableval}" in
  yes) use_mpi=yes ;;
   no) use_mpi=no ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-mpi option]) ;;
esac],
use_mpi=no)

AM_CONDITIONAL(BUILD_MPI_STUBS, test x"$use_mpi" = xno)
AM_CONDITIONAL(USE_MPI, test x"$use_mpi" = xyes)

# Checks for programs. These may set default variables, such as CFLAGS
AC_PROG_CPP
if test x"$use_mpi" == xyes; then
        # Use MPI compilers
        AX_PROG_FC_MPI
        AX_PROG_CC_MPI
else
        AC_PROG_CC
        AC_PROG_FC
fi
AC_PROG_RANLIB

# Checks for ehader files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdio.h])

# --------------------------------------------
# Check for Python compiler / if we should build python extension
# --------------------------------------------
AC_PATH_PROG(PYTHON, python)
AM_CONDITIONAL(HAVE_PYTHON, test x"$PYTHON" != x)
AC_ARG_ENABLE(
[python],
[  --enable-python         Enable build of python extension (default: enabled)],
[case "${enableval}" in
  yes) python_ext=yes ;;
   no) python_ext=no ;;
    *) AC_MSG_ERROR([bad value ${enableval} for --enable-python option]) ;;
esac],
python_ext=no)

if test x"$python_ext" = xyes; then
        if test x"$PYTHON" = x; then
                AC_MSG_ERROR([Can't build python extension, as python executable could not be found])
        fi
        # CFLAGS="$CFLAGS -fPIC"
        # AC_PYTHON_DEVEL
fi

AM_CONDITIONAL(BUILD_PYTHON_EXTENSION, test x"$python_ext" = xyes)

# --------------------------------------------
# Check for various possible FFT libraries
# What about other option ACML?
# --------------------------------------------
have_healpix=no
AC_CHECK_LIB([healpix],[healpix_fft],have_healpix=yes)
have_fftw3_c2r=no
AC_CHECK_LIB([fftw3],[fftw_plan_dft_c2r],have_fftw3_c2r=yes)
have_fftw3_hc2r=no
AC_CHECK_LIB([fftw3],[fftw_plan_dft],have_fftw3_hc2r=yes)
AM_CONDITIONAL(S2HAT_FFT_HEALPIX, test x"$have_healpix" = xyes)
AM_CONDITIONAL(S2HAT_FFT_FFTW3_C2R, test x"$have_fftw3_c2r" = xyes)
AM_CONDITIONAL(S2HAT_FFT_FFTW3_HC2R, test x"$have_fftw3_hc2r" = xyes)

# --------------------------------------------
# Checks for typedefs, structures, and compiler characteristics.
# --------------------------------------------

AC_TYPE_SIZE_T

AC_CONFIG_FILES([Makefile
                 mpi_stubs/Makefile
                 s2hat/Makefile
                 pure_s2hat/Makefile])

AC_OUTPUT

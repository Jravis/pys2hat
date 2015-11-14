# The libraries to build
noinst_LIBRARIES = libs2hat.a
noinst_HEADERS = \
        s2hat.h \
        s2hat_defs.h \
        s2hat_f2c.h \
        s2hat_types.h

# Fortran flags
AM_FCFLAGS=-O3 -std=gnu -fno-second-underscore -ffixed-line-length-none -ffree-line-length-none
# AM_FCFLAGS=-O3 -std=gnu -fno-underscoring -ffixed-line-length-none -ffree-line-length-none
# AM_FCFLAGS=-O3 -std=gnu -ffixed-line-length-none -ffree-line-length-none
# AM_CPPFLAGS=-Df2cFortran

# C build:
# .c:
#	$(MPICC) $(AM_CFLAGS) $(CFLAGS) $(MPILIBS) -Lfoobar -c $<

# The files to add to the library and to the source distribution
libs2hat_a_SOURCES = \
        $(libs2hat_a_HEADERS) \
        s2hat_defs.f90 \
        s2hat_types_internal.F90 \
        s2hat_pixelization.f90 \
        s2hat_toolbox.F90 \
        s2hat_alm2map.f90 \
        s2hat_map2alm.F90 \
        s2hat_c_interface.f90 \
        s2hat_c_wrappers.c

bin_PROGRAMS = \
        s2hat_f90_example \
        s2hat_c_example

s2hat_c_example_LDADD=./libs2hat.a -lmpifort
s2hat_c_example_SOURCES = \
        s2hat_example.c

s2hat_f90_example_LDADD=./libs2hat.a
s2hat_f90_example_SOURCES = \
        s2hat_f90_example.f90

clean:
	rm -f *.o *.mod *.a

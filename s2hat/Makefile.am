# The libraries to build
noinst_LIBRARIES = libs2hat.a
noinst_HEADERS = \
        s2hat.h \
        s2hat_defs.h \
        s2hat_f2c.h \
        s2hat_types.h

# Fortran flags
AM_FCFLAGS=-O3 -std=gnu -fno-second-underscore -ffixed-line-length-none -ffree-line-length-none

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

clean:
	rm -f *.o *.mod *.a

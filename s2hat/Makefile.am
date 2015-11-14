# Decide what FFT library to use
DFLAGS = 
LDADD =
if S2HAT_FFT_HEALPIX
LDADD+=-lhealpix
DFLAGS += -DHEALPIX_fft
else
if S2HAT_FFT_FFTW3_C2R
LDADD+=-lfftw3
DFLAGS += -DFFTW3_C2R
else
if S2HAT_FFT_FFTW3_HC2R
LDADD+=-lfftw3
DFLAGS += DFFTW3_HC2R
endif
endif
endif

# The libraries to build
noinst_LIBRARIES = libs2hat.a
noinst_HEADERS = \
        s2hat.h \
        s2hat_defs.h \
        s2hat_f2c.h \
        s2hat_types.h

# Fortran flags
AM_FCFLAGS=-O3 -std=gnu -fno-second-underscore -ffixed-line-length-none -ffree-line-length-none -I/opt/local/include
# AM_FCFLAGS=-O3 -std=gnu -fno-underscoring -ffixed-line-length-none -ffree-line-length-none
# AM_FCFLAGS=-O3 -std=gnu -ffixed-line-length-none -ffree-line-length-none
# AM_CPPFLAGS=-Df2cFortran

AM_FCFLAGS += $(DFLAGS)

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

s2hat_c_example_LDFLAGS=-L.
s2hat_c_example_LDADD=-ls2hat -lmpifort $(LDADD)
s2hat_c_example_SOURCES = \
        s2hat_example.c

s2hat_f90_example_LDFLAGS=-L.
s2hat_f90_example_LDADD=-ls2hat $(LDADD)
s2hat_f90_example_SOURCES = \
        s2hat_f90_example.f90

clean:
	rm -f *.o *.mod *.a

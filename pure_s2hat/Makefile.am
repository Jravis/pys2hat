if USE_MPI
FORTLIB=-lmpifort
else
MPIINC=-I../mpi_stubs
MPILIBFLAGS=-L../mpi_stubs
MPILIB=-lmpi_stubs
FORTLIB=-lgfortran
endif

# The libraries to build
noinst_LIBRARIES = libs2hat_pure.a
noinst_HEADERS = \
        s2hat_pure.h

AM_CFLAGS=-I../s2hat -L../s2hat $(MPIINC)

# The files to add to the library and to the source distribution
libs2hat_pure_a_SOURCES = \
        $(libs2hat_pure_a_HEADERS) \
        s2hat_map2purealm.c

clean:
	rm -f *.o *.mod *.a

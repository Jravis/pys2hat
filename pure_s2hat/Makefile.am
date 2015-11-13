# The libraries to build
noinst_LIBRARIES = libs2hat_pure.a
noinst_HEADERS = \
        s2hat_pure.h

AM_CFLAGS=-I../s2hat -L../s2hat

# The files to add to the library and to the source distribution
libs2hat_pure_a_SOURCES = \
        $(libs2hat_pure_a_HEADERS) \
        s2hat_map2purealm.c

clean:
	rm -f *.o *.mod *.a

additional_dist_subdirs =

if BUILD_PYTHON_EXTENSION
all-local:
	CC="$(CC)" CFLAGS="$(CFLAGS) -fno-strict-aliasing" $(PYTHON) setup.py build
install:
	$(PYTHON) setup.py install
clean-local:
	$(PYTHON) setup.py clean --all
else
additional_dist_subdirs += pys2hat
endif

if BUILD_MPI_STUBS
MPI_STUBS_SUBDIR = mpi_stubs
else
additional_dist_subdirs += mpi_stubs
endif

SUBDIRS = \
        $(MPI_STUBS_SUBDIR) \
        s2hat \
        pure_s2hat

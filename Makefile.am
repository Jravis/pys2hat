additional_dist_subdirs =

if BUILD_PYTHON_EXTENSION
all-local:
	CC="$(CC)" CFLAGS="$(CFLAGS) -fno-strict-aliasing" $(PYTHON) setup.py build
install:
	$(PYTHON) setup.py install
clean-local:
	$(PYTHON) setup.py clean --all
else
additional_dist_subdirs += py_ext
endif

SUBDIRS = \
        s2hat \
        pure_s2hat

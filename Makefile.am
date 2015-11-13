SUBDIRS = \
        s2hat \
        pure_s2hat

all-local:
	CC="$(CC)" CFLAGS="$(CFLAGS) -fno-strict-aliasing" $(PYTHON) setup.py build

install:
	$(PYTHON) setup.py install

clean-local:
	$(PYTHON) setup.py clean --all

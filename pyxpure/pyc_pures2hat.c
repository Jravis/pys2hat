/*
 * RWO 151113 - wrap pure-s2hat library for use in python
 */

#include <Python.h>  /* Greedy -- must go first */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numpy/arrayobject.h"
#include <mpi.h>
#include "s2hat.h"
#include "s2hat_pure.h"

/* #define PR(args...) mexPrintf(args); mexEvalString("0;")
 */
#define PR(args...) printf(args); printf("\n");

#define DEBUG_PURE_S2HAT 0
#if DEBUG_PURE_S2HAT
#  define DEBUG(args...) PR(args)
#else
#  define DEBUG(args...)
#endif

static PyObject * pyc_test (PyObject * self, PyObject * args)
{
    PyObject * D;

    return D;
}

static PyMethodDef pures2hatMethods[] = {
    {"test", pyc_test, METH_VARARGS,
     "Pure-s2hat E/B separation from a masked map."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC initpures2hat(void)
{
    (void) Py_InitModule("pures2hat", pures2hatMethods);
    import_array();
}




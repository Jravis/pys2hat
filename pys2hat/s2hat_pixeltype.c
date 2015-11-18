#include <Python.h>
#include <structmember.h>
/* #include <s2hat_defs.h> */
#include <strings.h>
#include <mpi.h>
#include <s2hat.h>

typedef struct {
    PyObject_HEAD
    s2hat_pixeltype * pixeltype;
} PixelType;

static PyMemberDef PixelType_members[] = {
    {"pixeltype", T_OBJECT_EX, offsetof(PixelType, pixeltype), 0,
     "internal pixeltype structure"},
    {NULL}  /* Sentinel */
};

static PyMethodDef PixelType_methods[] = {
    {NULL}  /* Sentinel */
};

static void PixelType_dealloc(PixelType* self)
{
    if (NULL != self->pixeltype)
      destroy_pixelization(*(self->pixeltype));
    Py_XDECREF(self->pixeltype);
    self->ob_type->tp_free((PyObject*)self);
}

static PyObject * PixelType_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PixelType *self;

    self = (PixelType *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->pixeltype = NULL;
        self->pixeltype = (s2hat_pixeltype *)malloc(sizeof(s2hat_pixeltype));
        if (self->pixeltype == NULL)
          {
            Py_DECREF(self);
            return NULL;
          }
    }

    return (PyObject *)self;
}

static int PixelType_init(PixelType *self, PyObject *args, PyObject *kwds)
{
    s2hat_pixparameters pixpars;
    PyObject *pixchoice = NULL;
    int pcnum = -1;

    static char *kwlist[] = {"pixchoice","par1","par2", NULL};

    if (! PyArg_ParseTupleAndKeywords(args, kwds, "S|ii", kwlist, 
                                      &pixchoice, &(pixpars.par1), &(pixpars.par2)))
        return -1;

    if (pixchoice) {
        if (!strncasecmp(PyString_AsString(pixchoice),"healpix",10))
            pcnum = PIXCHOICE_HEALPIX;
        else if (!strncasecmp(PyString_AsString(pixchoice),"glesp",10))
            pcnum = PIXCHOICE_GLESP;
        else if (!strncasecmp(PyString_AsString(pixchoice),"ecp",10))
            pcnum = PIXCHOICE_ECP;
        else if (!strncasecmp(PyString_AsString(pixchoice),"glcp",10))
            pcnum = PIXCHOICE_GLCP;
        else {
            PyErr_SetString(PyExc_ValueError, "Undefined pixelization choice string.");
            return -1;
        }
        /* Don't need to free pixchoice, it will be garbage collected */
    }
    else {
        PyErr_SetString(PyExc_ValueError, "No pixelization choice string specified.");
        return -1;
    }

    if (NULL == self->pixeltype) {
        self->pixeltype = NULL;
        self->pixeltype = (s2hat_pixeltype *)malloc(sizeof(s2hat_pixeltype));
        if (self->pixeltype == NULL)
        {
            PyErr_SetString(PyExc_TypeError, "Failed to allocate memory for pixeltype struct.");
            return -1;
        }
    }
    printf("Calling set_pixelization.\n");
    printf("  pc=%d, par1=%d, par2=%d.\n", pcnum, pixpars.par1, pixpars.par2);
    set_pixelization(pcnum, pixpars, self->pixeltype);
    printf("Returned.\n");

    return 0;
}

static PyTypeObject pys2hat_PixelTypeType = {
    PyObject_HEAD_INIT(NULL)
    0,                                  /*ob_size*/
    "pys2hat.PixelType",                /*tp_name*/
    sizeof(PixelType),                  /*tp_basicsize*/
    0,                                  /*tp_itemsize*/
    (destructor)PixelType_dealloc,      /*tp_dealloc*/
    0,                                  /*tp_print*/
    0,                                  /*tp_getattr*/
    0,                                  /*tp_setattr*/
    0,                                  /*tp_compare*/
    0,                                  /*tp_repr*/
    0,                                  /*tp_as_number*/
    0,                                  /*tp_as_sequence*/
    0,                                  /*tp_as_mapping*/
    0,                                  /*tp_hash */
    0,                                  /*tp_call*/
    0,                                  /*tp_str*/
    0,                                  /*tp_getattro*/
    0,                                  /*tp_setattro*/
    0,                                  /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,                 /*tp_flags*/
    "PyS2Hat PixelType object",         /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		               /* tp_iter */
    0,		               /* tp_iternext */
    PixelType_methods,         /* tp_methods */
    PixelType_members,         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PixelType_init,  /* tp_init */
    0,                         /* tp_alloc */
    PixelType_new,             /* tp_new */
};

static PyMethodDef pys2hat_methods[] = {
    {NULL}  /* Sentinel */
};

#ifndef PyMODINIT_FUNC	/* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
initpys2hat(void) 
{
    PyObject* m;

    pys2hat_PixelTypeType.tp_new = PyType_GenericNew;
    if (PyType_Ready(&pys2hat_PixelTypeType) < 0)
        return;

    m = Py_InitModule3("pys2hat", pys2hat_methods,
                       "Example module that creates an extension type.");

    Py_INCREF(&pys2hat_PixelTypeType);
    PyModule_AddObject(m, "PixelType", (PyObject *)&pys2hat_PixelTypeType);
}

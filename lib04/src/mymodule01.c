#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <time.h>
#include <stdio.h>


static PyObject *
time_string( PyObject *self)
{

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char buffer[21];
    sprintf(buffer,"%04d-%02d-%02d_%02d:%02d:%02d",
    		tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
			tm.tm_hour, tm.tm_min, tm.tm_sec);
    return Py_BuildValue("s", buffer);
}


static char mymodule01_docs[] =
   "time_string( ): get time string from c!!\n";


static PyMethodDef mymodule01_funcs[] = {
   {"time", (PyCFunction)time_string, METH_NOARGS, mymodule01_docs},
   {NULL,NULL,0,NULL}
};


static struct PyModuleDef mymodule01 =
{
    PyModuleDef_HEAD_INIT,
    "mymodule01",     /* name of module */
	mymodule01_docs,  /* module documentation */
    -1,
	mymodule01_funcs
};

PyMODINIT_FUNC PyInit_mymodule01(void)
{
    return PyModule_Create(&mymodule01);
}


/*
 * =====================================================================================
 *
 *       Filename:  ext.c
 *
 *    Description:  
 *
 *        Version:  0.1.0
 *        Created:  09/16/2011 05:44:40 PM
 *       Revision:  r1
 *       Compiler:  gcc
 *
 *         Author:  Fu Haiping <haipingf@gmail.com>
 *        Company:  ICT
 *
 * =====================================================================================
 */
 
#include <Python.h>
 
static PyObject *my_callback = NULL;
 
static PyObject *
_set_callback(PyObject *self, PyObject *args)
{
    PyObject *result = NULL;
    PyObject *temp;
    if (PyArg_ParseTuple(args, "O", &temp)) {
        if (!PyCallable_Check(temp)) {
            PyErr_SetString(PyExc_TypeError, "parameter must be callable");
            return NULL;
        }
        Py_XINCREF(temp);         /* Add a reference to new callback */
        Py_XDECREF(my_callback);  /* Dispose of previous callback */
        my_callback = temp;       /* Remember new callback */
        /* Boilerplate to return "None" */
        Py_INCREF(Py_None);
        result = Py_None;
    }
    return result;
}
 
static int _compare(const char *a, const char *b)
{
    long ret;
    PyObject *arglist;
    PyObject * result = NULL; 
    arglist = Py_BuildValue("(ss)", a, b);
    result = PyEval_CallObject(my_callback, arglist); 
    ret = PyInt_AsLong(result);
    if (result == NULL) 
        return -1; 
    Py_DECREF(result); 
    return ret;
}
 
void compare(const char *a, const char *b)
{
    if (_compare(a, b) > 0) {
        printf("arg1 is greater than arg2\n");
    } else if (_compare(a, b) < 0) {
        printf("arg1 is NOT greater than arg2\n");
    } else {
        printf("arg1 is equal to arg2\n");
    }
}
 
static PyObject* _compare_callback(PyObject *self, PyObject *args) 
{ 
 
    const char *a = NULL, *b = NULL;
    if (!PyArg_ParseTuple(args, "ss", &a, &b)) {
        return NULL;
    }
    compare(a, b);
    Py_INCREF(Py_None);
    return Py_None;
} 
 
static PyMethodDef
extMethods[] = {
    {"setcmp", _set_callback, METH_VARARGS},
    {"compare", _compare_callback, METH_VARARGS},
    {NULL, NULL}
};
 
void initext()
{
    Py_InitModule("ext", extMethods);
}

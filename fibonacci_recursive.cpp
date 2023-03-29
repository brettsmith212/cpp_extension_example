#include <Python.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

static PyObject* fib_wrapper(PyObject* self, PyObject* args) {
    int n;

    if (!PyArg_ParseTuple(args, "i", &n)) {
        return NULL;
    }

    int result = fib(n);

    return Py_BuildValue("i", result);
}

static PyMethodDef module_methods[] = {
    {"fib", fib_wrapper, METH_VARARGS, "Calculate the n-th Fibonacci number."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module_definition = {
    PyModuleDef_HEAD_INIT,
    "fibonacci_recursive",
    "A C++ extension module that calculates Fibonacci numbers using recursion.",
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_fibonacci_recursive(void) {
    Py_Initialize();
    return PyModule_Create(&module_definition);
}


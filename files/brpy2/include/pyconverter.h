# ifndef __PYCONVERTER_H__
# define __PYCONVERTER_H__

#include <Python.h>

#include <opencv2/core/core.hpp>
#include <numpy/ndarrayobject.h>

int failmsg(const char *fmt, ...);

class NDArrayConverter
{
private:
    void init();

public:
    NDArrayConverter();
    cv::Mat toMat(const PyObject* o);
    PyObject* toNDArray(const cv::Mat& mat);
};

# endif // PYCONVERTER

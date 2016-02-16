#ifndef PYEXCEPTIONS_H
#define PYEXCEPTIONS_H

#include <string>
#include "Python.h"

// Base Exception
struct BaseException
{
    BaseException(const std::string &function) : function(function) {}
    std::string function;
};

// Missing Key Exception
struct MissingKeyException : BaseException
{
    MissingKeyException(const std::string &function, const std::string &key) : BaseException(function), key(key) {}
    std::string key;
};
void missingKeyExceptionToString(const MissingKeyException &ex);

// Empty Template Exception
struct EmptyTemplateException : BaseException
{
    EmptyTemplateException(const std::string &function) : BaseException(function) {}
};
void emptyTemplateExceptionToString(const EmptyTemplateException &ex);

// Out of bounds index Exception
struct OutOfBoundsException : BaseException
{
    OutOfBoundsException(const std::string &function, int size, int index) : BaseException(function), size(size), index(index) {}
    int size, index;
};
void outOfBoundsExceptionToString(const OutOfBoundsException &ex);

// Comparison Exceptions
struct NoDistanceException : BaseException
{
    NoDistanceException(const std::string &function) : BaseException(function) {}
};
void noDistanceExceptionToString(const NoDistanceException &ex);

struct PairwiseListsDontMatchException : BaseException
{
    PairwiseListsDontMatchException(const std::string &function) : BaseException(function) {}
};
void pairwiseListsDontMatchToString(const PairwiseListsDontMatchException &ex);

// Misc Exception
struct BadFileTypeException : BaseException
{
    BadFileTypeException(const std::string &function, const std::string &fileType) : BaseException(function), fileType(fileType) {}
    std::string fileType;
};
void badFileTypeToString(const BadFileTypeException &ex);

struct OutputInInputsException : BaseException
{
    OutputInInputsException(const std::string &function) : BaseException(function) {}
};
void outputInInputsToString(const OutputInInputsException &ex);

#endif // PYEXCEPTIONS_H


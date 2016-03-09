#ifndef PYTEMPLATE_H
#define PYTEMPLATE_H

#include "pyconverter.h"
#include "pyfile.h"

class PyTemplate
{
public:
    PyTemplate() {}
    PyTemplate(const std::string &name) { file = PyFile(name); }
    PyTemplate(const PyFile &f) { file = f; }
    PyTemplate(PyObject *o) { append(o); file = PyFile(); }
    PyTemplate(const std::string &name, PyObject *o) { append(o); file = PyFile(name); }

    // Conversion operations
    br::Template toTemplate() const;
    void fromTemplate(const br::Template &t);

    // Template operations
    PyObject *first() const;
    PyObject *m() const { return first(); }
    PyObject *last() const;
    PyObject *get(int idx) const;
    void append(const PyObject *o);
    void insert(const PyObject *o, int idx);
    void replace(const PyObject *o, int idx);
    void clear() { t.clear(); }

    int size() const { return t.size(); }
    int bytes() const { return (int)t.bytes(); }
    bool null() const { return t.isNull(); }
    bool empty() const { return t.empty(); }

    PyFile file;

private:
    br::Template t;
};

#endif // PYTEMPLATE_H

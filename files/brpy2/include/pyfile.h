#ifndef PYFILE_H
#define PYFILE_H

#include <openbr/openbr_plugin.h>
#include "pyexceptions.h"

struct PyFile
{
    PyFile() {}
    PyFile(const std::string &path) { file = br::File(path.c_str()); }

    std::string name() const { return file.name.toStdString(); }
    std::string flat() const { return file.flat().toStdString(); }
    std::string hash() const { return file.hash().toStdString(); }

    std::string get(const std::string &key);
    void set(const std::string &key, const std::string &value) { file.set(key.c_str(), QString(value.c_str())); }

    bool fte() const { return file.fte; }
    bool isNull() const { return file.isNull(); }
    bool exists() const { return file.exists(); }

    std::string fileName() const { return file.fileName().toStdString(); }
    std::string baseName() const { return file.baseName().toStdString(); }

    std::string suffix() const { return file.suffix().toStdString(); }
    std::string path() const { return file.path().toStdString(); }

    bool contains(const std::string &key) const { return file.contains(key.c_str()); }
    void remove(const std::string &key);

    PyObject *points();
    void appendPoint(PyObject *point);
    void clearPoints() { file.clearPoints(); }

    PyObject *rects();
    void appendRect(PyObject *rect);
    void clearRects() { file.clearRects(); }

    br::File file;
};

#endif // PYFILE_H

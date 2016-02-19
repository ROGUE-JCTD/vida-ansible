#ifndef PYFUNCTIONS_H
#define PYFUNCTIONS_H

#include <boost/python.hpp>
#include "pytemplate.h"

// Setup
void initialize();
void initialize(int &argc, char *argv[], const char *sdk_path, bool use_gui);
void finalize();

// Set
void setAlgorithm(const std::string &algorithm);
std::string getGlobal(const std::string &key);
void setGlobal(const std::string &key, const std::string &value);

// Train
void train(const std::string &file, const std::string &model);

// Enroll
PyTemplate enroll(const PyTemplate &t);
boost::python::list enroll(const boost::python::list &templates);
void enroll(const std::string &input, const std::string &output);

// Comparison
float compare(const PyTemplate &t1, const PyTemplate &t2);
boost::python::list compare(const PyTemplate &probe, const boost::python::list &gallery);
void compare(const std::string &gallery, const std::string &probe, const std::string &output);

boost::python::list pairwiseCompare(const boost::python::list &tl1, const boost::python::list &tl2);
void pairwiseCompare(const std::string &tl1, const std::string &tl2, const std::string &output);

// IO
PyTemplate readFormat(const std::string &file);
void writeFormat(const std::string &file, const PyTemplate &tmpl);

boost::python::list readGallery(const std::string &file);
void writeGallery(const std::string &file, const boost::python::list &templates);

#endif // PYFUNCTIONS_H


#pragma once

#include <boost/interprocess/sync/scoped_lock.hpp>
#include <iostream>
#include <sstream>
#include <cstdlib> //std::system
#include <thread>
#include <opencv2\opencv.hpp>

#include "SharedImageBuffer.h"

using std::string;

using namespace cv;
using namespace boost::interprocess;
using namespace boost::detail;

void program_thread(std::stringstream & cmd);

void _camera(ti &o);

void _run(ti &t);
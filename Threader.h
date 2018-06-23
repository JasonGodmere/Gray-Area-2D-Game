#pragma once

#include "Define.h"

unsigned concurentThreadsSupported = std::thread::hardware_concurrency();

//gets the number of processing threads of machine for multithread
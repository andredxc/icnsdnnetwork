//  (C) Copyright John Maddock 2001 - 2003. 
//  (C) Copyright Jens Maurer 2003. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


//  See http://www.boost.org for most recent version.

//  SGI Irix specific config options:

#define NDNBOOST_PLATFORM "SGI Irix"

#define NDNBOOST_NO_SWPRINTF 
//
// these are not auto detected by POSIX feature tests:
//
#define NDNBOOST_HAS_GETTIMEOFDAY
#define NDNBOOST_HAS_PTHREAD_MUTEXATTR_SETTYPE

#ifdef __GNUC__
   // GNU C on IRIX does not support threads (checked up to gcc 3.3)
#  define NDNBOOST_DISABLE_THREADS
#endif

// boilerplate code:
#define NDNBOOST_HAS_UNISTD_H
#include <ndnboost/config/posix_features.hpp>




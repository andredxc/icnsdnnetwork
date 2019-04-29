//  (C) Copyright John Maddock 2001. 
//  Use, modification and distribution are subject to the 
//  Boost Software License, Version 1.0. (See accompanying file 
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

//  BeOS specific config options:

#define NDNBOOST_PLATFORM "BeOS"

#define NDNBOOST_NO_CWCHAR
#define NDNBOOST_NO_CWCTYPE
#define NDNBOOST_HAS_UNISTD_H

#define NDNBOOST_HAS_BETHREADS

#ifndef NDNBOOST_DISABLE_THREADS
#  define NDNBOOST_HAS_THREADS
#endif

// boilerplate code:
#include <ndnboost/config/posix_features.hpp>
 



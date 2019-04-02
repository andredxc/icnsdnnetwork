/*
 * tno-ext.h
 *
 *  Created on: Feb 21, 2016
 *      Author: borgert
 */

#ifndef TNO_EXT_H_
#define TNO_EXT_H_

#include "openflow/openflow.h"

#define TNO_VENDOR_ID 0x66666666

enum tno_type {

    TNO_PUT_BPF,
    TNO_DEL_BPF,
    TNO_GET_BPF

};




#endif /* TNO_EXT_H_ */

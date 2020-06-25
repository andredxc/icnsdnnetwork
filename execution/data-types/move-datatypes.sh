#!/bin/bash

MININDN_DIR="/home/osboxes/mini-ndn"
PARENT_PATH=$(dirname "${BASH_SOURCE[0]}")

# C2DataTypes
cp $PARENT_PATH/C2DataTypes.cpp $MININDN_DIR/ndn-cxx/examples/
cp $PARENT_PATH/C2DataTypes.hpp $MININDN_DIR/ndn-cxx/examples/

#!/bin/bash

MININDN_DIR="/home/osboxes/mini-ndn"

# Consumer and producer
cp agents-minindn/producer.cpp $MININDN_DIR/ndn-cxx/examples/
cp agents-minindn/consumer.cpp $MININDN_DIR/ndn-cxx/examples/

# C2DataTypes
cp agents-minindn/C2DataTypes.cpp $MININDN_DIR/ndn-cxx/examples/
cp agents-minindn/C2DataTypes.hpp $MININDN_DIR/ndn-cxx/examples/

# Experiment
cp experiments/random_talks.py $MININDN_DIR/ndn/experiments/ss

cd $MININDN_DIR/ndn-cxx/; sudo ./waf

#!/bin/bash

MININDN_DIR="/home/osboxes/mini-ndn"
PARENT_PATH=$(dirname "${BASH_SOURCE[0]}")

# Consumer and producer
cp $PARENT_PATH/producer.cpp $MININDN_DIR/ndn-cxx/examples/
cp $PARENT_PATH/consumer.cpp $MININDN_DIR/ndn-cxx/examples/



# cd "$parent_path"
# cat ../some.text
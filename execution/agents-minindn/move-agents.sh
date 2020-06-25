#!/bin/bash

MININDN_DIR="/home/osboxes/mini-ndn"

# Consumer and producer
cp ./producer.cpp $MININDN_DIR/ndn-cxx/examples/
cp ./consumer.cpp $MININDN_DIR/ndn-cxx/examples/

##!/bin/bash
# parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )

# cd "$parent_path"
# cat ../some.text
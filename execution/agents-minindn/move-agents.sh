#!/bin/bash

MININDN_DIR="/home/osboxes/mini-ndn"
PARENT_PATH=$(dirname "${BASH_SOURCE[0]}")

# Consumer and producer
cp $PARENT_PATH/producer.cpp $MININDN_DIR/ndn-cxx/examples/
cp $PARENT_PATH/consumer.cpp $MININDN_DIR/ndn-cxx/examples/

# Gambi
cd $PARENT_PATH; cd ..; ./build.sh


echo "Done"


# #Filename: success_test.sh 
# # Evaluate the arguments on the command line - ie success_test.sh 'ls | grep txt' 
# eval $@ 
# if [ $? -eq 0 ]; 
# then 
#     echo "$CMD executed successfully" 
# else 
#     echo "$CMD terminated unsuccessfully" 
# fi

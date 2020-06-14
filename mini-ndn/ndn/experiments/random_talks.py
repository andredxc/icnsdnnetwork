import sys
import time
from random import randint
from ndn.experiments.experiment import Experiment

c_strEportCmd = 'export HOME=/home/osboxes/ && '

class RandomTalks(Experiment):

    def __init__(self, args):
        Experiment.__init__(self, args)


    def setup(self):

        for node in self.net.hosts:
            print('Node: ' + str(node))


    def run(self):

         # User defined experiment parameters
         nInterests  = 100
         nPoolSize   = 100
         nPayloadQtd = 6
         print('Running, nInterests=' + nInterests + '; nPoolSize=' + nPoolSize +
            '; nPayloadQtd=' + nPayloadQtd)

         # Other parameters
         nHosts = len(self.net.hosts)

         # Select producer/consumer pairs
         for nIteration in range(0, nInterests):
            # Generate producer/consumer pair
            (nProd, nCon) = selectProducerConsumer(nHosts)
            producer      = self.net.hosts[nProd]
            consumer      = self.net.hosts[nCon]
            strInterest   = randomDataInfoFromPool(nPayloadQtd, nPoolSize)

            print('run: Selected pair, nProducer=' + nProd + '; strProducer=' + str(producer) +
               '; nConsumer=' + nCon + '; strConsumer=' + str(consumer) + '; interest=' +
               strInterest)

            producer.cmd('producer ' + strInterest + ' &')

            time.sleep(1)

            consumer.cmd('consumer ' + strInterest + ' &')

            time.sleep(2)

         # print('strResult0=' + strResult0)
         # print('strResult1=' + strResult1)

         # for node in self.net.hosts:
         #     strResult = node.cmd('ifconfig')
         #     print(strResult)
         #     # Send output to a file


    def selectProducerConsumer(nHosts):
      """
      Randomly select a non-equal producer-consumer pair
      :return indexes for producer and consumer
      :rtype tuple of (int, int)
      """
      if(nHosts > 1):
         bDone     = False
         nConsumer = randint(0, nHosts-1)
         while (not bDone):
            # Find non-equal pair for consumer
            nProducer = randint(0, nHosts-1)
            if(nProducer != nConsumer):
               bDone = True
         # Return non-equal pair
         return (nProducer, nConsumer)
      else
         return (0,0)

    def randomDataInfoFromPool(nPayloadQtd, nPoolSize):
        """
        Generate C2 data info.
        """

        if (nPoolSize % nPayloadQtd != 0):
            print('randomDataInfoFromPool: Payload times not evenly distributed')
            raise ArgumentError

        # Determine which package it is
        nPackagesPerType = nPoolSize / nPayloadQtd
        nPackageID       = randint(0, nPackagesPerType)
        nPackageType     = rand(0, nPayloadQtd-1)
        strPackageName   = 'C2Data-' + nPackageID + '-Type' + nPackageType
        return strPackageName






Experiment.register("random-talks", RandomTalks)

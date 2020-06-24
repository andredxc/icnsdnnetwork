import sys
import time
from random import randint
from ndn.experiments.experiment import Experiment

c_strEportCmd = 'export HOME=/home/osboxes/ && '
c_strAppName  = 'C2Data'

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
      nHosts       = len(self.net.hosts)
      hshProducers = {}

      # Select producer/consumer pairs
      for nIteration in range(0, nInterests):
         # Generate producer/consumer pair
         nCon        = randint(0, nHosts-1)
         strInterest = randomDataInfoFromPool(nPayloadQtd, nPoolSize)

         if (strInterest not in hshProducers):
            # No producer has yet been assigned to this data
            nProd = randomHostPair(nCon, nHosts)
            hshProducers[strInterest] = nProd
            bNewProducer = True
         else:
            # Data already has a producer
            nProd = hshProducers[strInterest]
            bNewProducer = False

         producer    = self.net.hosts[nProd]
         consumer    = self.net.hosts[nCon]
         strProducer = str(producer)
         strConsumer = str(consumer)
         strFilter   = '/' + c_strAppName + '/' + strProducer + '/'

         if (bNewProducer):
            # Producer has not been initialized yet
            print('[run] producer ' + strFilter + ' &')
            producer.cmd('producer ' + strFilter + ' &')

         # Run consumer for the specific data
         strInterest = strFilter + strInterest
         print('[run] Selected pair, nProducer=' + nProd + '; strProducer=' + strProducer +
            '; nConsumer=' + nCon + '; strConsumer=' + strConsumer + '; interest=' + strInterest)

         print('[run] consumer ' + strInterest + ' ' + strConsumer + ' &')
         consumer.cmd('consumer ' + strInterest + ' ' + strConsumer + ' &')

         time.sleep(2) # Maybe

   def randomHostPair(nOriginal, nHosts):
      nPair = 0
      if (nHosts > 1):
         while (True):
            nPair = randint(0, nHosts-1)
            if (nPair != nOriginal):
               return nPair
      else:
         return 0

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
      else:
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

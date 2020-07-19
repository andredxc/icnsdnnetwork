import sys
import time
from random import randint
from ndn.experiments.experiment import Experiment

c_strEportCmd = 'export HOME=/home/osboxes/ && '
c_strAppName  = 'C2Data'
c_strLogFile  = '/home/osboxes/github/icnsdnnetwork/execution/logs/random_talks.log'


class RandomTalks(Experiment):

   def __init__(self, args):
      """
      Constructor. Meh
      """
      self.logFile = None
      Experiment.__init__(self, args)

   def setup(self):
      """
      Setup experiment
      """
      for node in self.net.hosts:
         self.log('setup', 'Node: ' + str(node))

   def run(self):
      """
      Experiment routine
      """
      # User defined experiment parameters
      nInterests  = 100
      nPoolSize   = 60
      nPayloadQtd = 6
      self.log('run', 'Running, nInterests=' + str(nInterests) + '; nPoolSize=' + str(nPoolSize) +
         '; nPayloadQtd=' + str(nPayloadQtd))

      # Other parameters
      nHosts       = len(self.net.hosts)
      lstProducers = []

      # Select producer/consumer pairs
      for nIteration in range(0, nInterests):

         self.log('run', 'Iteration ' + str(nIteration) + '/' + str(nInterests-1) + '--------------------')
         # Generate producer/consumer pair
         nCon        = randint(0, nHosts-1)
         nProd       = self.randomHostPair(nCon, nHosts)
         strInterest = self.randomDataInfoFromPool(nPayloadQtd, nPoolSize)

         if (nProd not in lstProducers):
            # This producer has not yet been initialized
            lstProducers.append(nProd)
            bNewProducer = True
         else:
            # Data already has a producer
            bNewProducer = False

         producer    = self.net.hosts[nProd]
         consumer    = self.net.hosts[nCon]
         strProducer = str(producer)
         strConsumer = str(consumer)
         strFilter   = '/' + c_strAppName + '/' + strProducer + '/'

         if (bNewProducer):
            # Producer has not been initialized yet
            self.log('run', 'instantiating new producer ' + strFilter + ' &')
            producer.cmd('producer ' + strFilter + ' &')

         # Run consumer for the specific data
         strInterest = strFilter + strInterest
         self.log('run', 'Selected pair, nProducer=' + str(nProd) + '; strProducer=' + strProducer +
            '; nConsumer=' + str(nCon) + '; strConsumer=' + strConsumer + '; interest=' + strInterest)

         self.log('run', 'instantiating new consumer ' + strInterest + ' ' + strConsumer + ' &')
         consumer.cmd('consumer ' + strInterest + ' ' + strConsumer + ' &')

         # time.sleep(2) # Maybe

      # Close log file
      if (self.logFile):
         self.logFile.close()

   def randomHostPair(self, nOriginal, nHosts):
      """
      Random host index different from nOriginal
      """
      nPair = 0
      if (nHosts > 1):
         while (True):
            nPair = randint(0, nHosts-1)
            if (nPair != nOriginal):
               return nPair
      else:
         return 0

   def selectProducerConsumer(self, nHosts):
      """
      Randomly select a non-equal producer-consumer pair
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

   def randomDataInfoFromPool(self, nPayloadQtd, nPoolSize):
      """
      Generate C2 data info.
      """
      if (nPoolSize % nPayloadQtd != 0):
         self.log('randomDataInfoFromPool', 'Payload times not evenly distributed ' +
            'poolSize=' + str(nPoolSize) + '; payloadQtd=' + str(nPayloadQtd))
         raise Exception

      # Determine which package it is
      nPackagesPerType = nPoolSize / nPayloadQtd
      nPackageID       = randint(0, nPackagesPerType-1)
      nPackageType     = randint(0, nPayloadQtd-1)
      strPackageName   = 'C2Data-' + str(nPackageID) + '-Type' + str(nPackageType)
      return strPackageName

   def log(self, strFunction, strContent):
      """
      Logs a line in the Andre standard format
      """
      if (not self.logFile):
         self.logFile = open(c_strLogFile, 'w')

      strLine = '[RandomTalks.' + strFunction + '] ' + strContent + '\n'
      self.logFile.write(strLine)
      print(strLine)

Experiment.register("random-talks", RandomTalks)

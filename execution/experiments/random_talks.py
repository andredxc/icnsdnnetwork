import sys
import time
from DataManager import *
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
      self.logFile         = None
      self.lstProducers    = []
      self.DataManager     = DataManger()
      self.nMissionMinutes = 0
      Experiment.__init__(self, args)

   def setup(self):
      """
      Setup experiment
      """
      for node in self.net.hosts:
         self.log('setup', 'Node: ' + str(node))
         lstHostNames = str(node)

      self.lstDataQueue = self.DataManager.generateDataQueue(lstHostNames, self.nMissionMinutes)

      for nIndex, node in enumerate(self.lstDataQueue):
         self.log('setup', 'Node[' + nIndex + ']: ' + node[0] + ', ' + node[1])

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

      sExperimentTimeSec = 100
      sInitialTimeSec = time.monotonic()
      sElapsedTimeSec = 0
      nDataIndex      = 0
      while ((sInitialTimeSec + sElapsedTimeSec) < sExperimentTimeSec):
         # Send data until the end of the experiment
         bShouldSendData = True
         while (bShouldSendData and (nDataIndex < len(self.lstDataQueue))):
            # Sweep queue and send data according to the elapsed time
            sElapsedTimeMili = int(sElapsedTimeSec/1000)
            pDataBuff = self.lstDataQueue[nDataIndex]

            if(pDataBuff[0] <= sElapsedTimeMili):
               # Send data
               self.send(pDataBuff)
               # Wait until next data is ready
               time.sleep(self.lstDataQueue[nDataIndex+1][0] * 1000)
            else:
               # Wait before sending next data
               bShouldSendData = False

         nDataIndex += 1
         sElapsedTimeSec = time.monotonic() - sInitialTimeSec

      # Close log file
      if (self.logFile):
         self.logFile.close()

   def send(self, pDataPackage):
      """
      Issues MiniNDN commands for sender and receiver of a data package
      """
      pDataPackage.strOrig
      pDataPackage.strDest
      pDataPackage.getInterestFilter()

      nProducer = self.findHostByName(pDataPackage.strOrig)
      nConsumer = self.findHostByName(pDataPackage.strDest)

      if((nProducer >= 0) and (nConsumer >= 0)):
         # Valid consumer and producer
         if(nProducer not in self.lstProducers):
            # Producer has not yet been instantiated
            strFilter = self.getFilterByHostname(pDataPackage.strOrig)
            self.log('send', 'instantiating new producer ' + strFilter + ' &')
            producer.cmd('producer ' + strFilter + ' &')
            self.lstProducers.append(nProducer)

         pProducer = self.net.hosts[nProducer]
         pConsumer = self.net.hosts[nConsumer]

         self.log('send', 'instantiating new consumer ' + strInterest + ' ' + strConsumer + ' &')
         consumer.cmd('consumer %s &' % (pDataPackage.getInterest()))
         self.log('send', 'Sending %s' % pDataPackage)
      else:
         raise Exception('[send] ERROR, invalid origin or destination hosts in data package=%s' % pDataPackage)

   def findHostByName(self, strName):
      """
      Finds a host in MiniNDN self.net.hosts by name
      """
      for (nIndex, pNode) in enumerate(self.net.hosts):
         if (str(pNode) == strName):
            return nIndex
      return -1

   def getFilterByHostname(self, strName):
      """
      Creates interest filter base on the producer`s name
      """
      return '/' + c_strAppName + '/' + strName + '/'

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



# Batata
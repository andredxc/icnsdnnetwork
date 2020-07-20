import logging
import random

logging.basicConfig(filename="DataManager.log", format='%(asctime)s %(message)s', level=logging.DEBUG)

def main():

    logging.info('STARTING------------------------------------------')
    DataMgr = DataManager()

    lstHosts        = ['d1', 'd2', 'd3', 'h1']
    nMissionMinutes = 1
    lstDataQueue    = DataMgr.generateDataQueue(lstHosts, nMissionMinutes)

    nCount = 0
    for pNode in lstDataQueue:
        logging.info('%s ms, %s' % (pNode[0], pNode[1]))
        print('%s ms, %s' % (pNode[0], pNode[1]))
        nCount += 1
    print('Total data queue size: %s' %(nCount))


class DataManager:

    def __init__(self):
        """
        Constructor
        """
        self.lstDataTypes = []
        # Initialize known dataTypes
        self.lstDataTypes.append(C2DataType(5000, 5, 1, 5000, ['d', 'h', 'v', 's']))   # INTEREST 1

    def generateDataQueue(self, lstHosts, nMissionMinutes):
        """
        Generates an unordered queue with packages and send time
        """
        lstDataQueue = []
        for strHost in lstHosts:
            # Generate data from each host
            if(strHost[0] == 'd'):
                # Drone
                logging.info('[generateDataQueue] Node type drone')
                self.lstDataTypes[0].generateDataQueue(strHost, nMissionMinutes, lstDataQueue, lstHosts)
            elif(strHost[0] == 'h'):
                # Human
                logging.info('[generateDataQueue] Node type human')
                self.lstDataTypes[0].generateDataQueue(strHost, nMissionMinutes, lstDataQueue, lstHosts)
            elif(strHost[0] == 's'):
                # Sensor
                logging.info('[generateDataQueue] Node type sensor')
                self.lstDataTypes[0].generateDataQueue(strHost, nMissionMinutes, lstDataQueue, lstHosts)
            elif(strHost[0] == 'v'):
                # Vehicle
                logging.info('[generateDataQueue] Node type vehicle')
                self.lstDataTypes[0].generateDataQueue(strHost, nMissionMinutes, lstDataQueue, lstHosts)
            else:
                # Unrecognized host type
                logging.error('[generateDataQueue] Unrecognized host type ' + strHost)

        lstDataQueue.sort(key=lambda x: x[0])
        return lstDataQueue


class C2DataType:

    def __init__(self, nTTL, nPeriod, nType, nSize, lstAllowedHostTypes):
        """
        Constructor
        """
        self.nTTL         = nTTL     # Time To Live in ms
        self.nPeriodSec   = nPeriod  # Creation period in s
        self.nType        = nType    # Type number
        self.nPayloadSize = nSize    # Package payload size
        self.nCurID       = 0        # Used for generating new packages

        self.lstAllowedHostTypes = lstAllowedHostTypes # Host types that can receive this data

    def generateDataQueue(self, strHost, nMissionMinutes, lstDataQueue, lstHosts):
        """
        Generates the data queue for a host
        """
        # Assemble list with possible receivers for this data type
        lstPossibleReceivers = self.generatePossibleReceiversList(strHost, lstHosts)

        # Assemble data queue
        nMissionSeconds = nMissionMinutes * 60
        nSecondsElapsed = 0
        nCount          = 0
        while (nSecondsElapsed <= nMissionSeconds):
            # Create data and add to list with miliseconds offset
            strDest = self.getRandomDestHost(lstPossibleReceivers)
            pData   = DataPackage(self.nType, self.nCurID, self.nPayloadSize, strHost, strDest)
            lstDataQueue.append([nSecondsElapsed*1000, pData])
            self.nCurID     += 1
            nCount          += 1
            nSecondsElapsed  = nSecondsElapsed + self.nPeriodSec

        return nCount

    def generatePossibleReceiversList(self, strHost, lstHosts):
        """
        Generates a list with the indexes of all hosts that can receive this data type
        """
        lstPossibleReceivers = []
        for strNode in lstHosts:
            # Letter 0 defines the type of node(drone, human, sensor, vehicle)
            if((strNode[0] in self.lstAllowedHostTypes) and (strNode != strHost)):
                lstPossibleReceivers.append(strNode)

        if (len(lstPossibleReceivers) == 0):
            raise Exception('[C2DataTypes.generatePossibleReceiversList] ERROR, no available nodes for data type %s' % self.nType)
        else:
            return lstPossibleReceivers

    def getRandomDestHost(self, lstPossibleReceivers):
        """
        Returns a randomly generated host who could receive this data type. Assumes receivers list is solid.
        """
        nRandIndex = random.randint(0, len(lstPossibleReceivers)-1)
        return lstPossibleReceivers[nRandIndex]


class DataPackage:

    def __init__(self, nType, nID, nPayloadSize, strHost, strDest):
        """
        Constructor
        """
        self.nID          = nID
        self.nPayloadSize = nPayloadSize
        self.nType        = nType
        self.strOrig      = strHost
        self.strDest      = strDest

    def __repr__(self):
        """
        Repr
        """
        return '<DataPackage_Type%s_ID%s (%s -> %s)>' %(self.nType, self.nID, self.strOrig, self.strDest)

    def getInterest(self):
        """
        Returns the string representation of the interest filter
        """
        strInterest = '/C2Data/' + self.strOrig + '/C2Data-'
        strInterest = strInterest + str(self.nID) + '-Type' + str(self.nType)
        return strInterest

if (__name__ == '__main__'):
    main()

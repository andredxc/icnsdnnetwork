import logging

logging.basicConfig(filename="DataManager.log", format='%(asctime)s %(message)s', level=logging.DEBUG)

def main():

    DataMgr = DataManager()

    lstHosts        = ['d1', 'd2', 'd3', 'h1']
    nMissionMinutes = 1
    lstDataQueue    = DataMgr.generateDataQueue(lstHosts, nMissionMinutes)

    lstDataQueue[len(lstDataQueue) - 1][0] = 1

    nCount = 0
    for node in lstDataQueue:
        print('%s ms, %s' % (node[0], node[1]))
        nCount += 1
    print('Total data queue size: %s' %(nCount))

    lstDataQueue = DataMgr.orderDataQueue(lstDataQueue)


class DataManager:

    def __init__(self):
        """
        Constructor
        """
        self.lstDataTypes = []
        # Initialize known dataTypes
        self.lstDataTypes.append(C2DataType(5000, 5, 1, 5000))   # INTEREST 1

    def generateDataQueue(self, lstHosts, nMissionMinutes):
        """
        Generates an unordered queue with packages and send time
        """
        # TODO: Define destination hosts for data packages
        strDest      = 'TBD'
        lstDataQueue = []
        for strHost in lstHosts:
            # Generate data from each host
            if(strHost[0] == 'd'):
                # Drone
                logging.info('[generateDataQueue] Node type drone')
                self.lstDataTypes[0].generateDataQueue(strHost, strDest, nMissionMinutes, lstDataQueue)
            elif(strHost[0] == 'h'):
                # Human
                logging.info('[generateDataQueue] Node type human')
                self.lstDataTypes[0].generateDataQueue(strHost, strDest, nMissionMinutes, lstDataQueue)
            elif(strHost[0] == 's'):
                # Sensor
                logging.info('[generateDataQueue] Node type sensor')
                self.lstDataTypes[0].generateDataQueue(strHost, strDest, nMissionMinutes, lstDataQueue)
            elif(strHost[0] == 'v'):
                # Vehicle
                logging.info('[generateDataQueue] Node type vehicle')
                self.lstDataTypes[0].generateDataQueue(strHost, strDest, nMissionMinutes, lstDataQueue)
            else:
                # Unrecognized host type
                logging.error('[generateDataQueue] Unrecognized host type ' + strHost)

        return lstDataQueue

    def orderDataQueue(self, lstDataQueue):
        """
        Order the queue based on the packages' time offset
        """
        return sorted(lstDataQueue, key=lambda x: x[0])


class C2DataType:

    def __init__(self, nTTL, nPeriod, nType, nSize):
        """
        Constructor
        """
        self.nTTL         = nTTL     # Time To Live in ms
        self.nPeriodSec   = nPeriod  # Creation period in s
        self.nType        = nType    # Type number
        self.nPayloadSize = nSize    # Package payload size
        self.nCurID       = 0        # Used for generating new packages

    def generateDataQueue(self, strHost, strDest, nMissionMinutes, lstDataQueue):
        """
        Generates the data queue for a host
        """
        nMissionSeconds = nMissionMinutes * 60
        nSecondsElapsed = 0
        nCount          = 0
        while (nSecondsElapsed <= nMissionSeconds):
            # Create data and add to list with miliseconds offset
            data = DataPackage(self.nType, self.nCurID, self.nPayloadSize, strHost, strDest)
            lstDataQueue.append([nSecondsElapsed*1000, data])
            self.nCurID     += 1
            nCount          += 1
            nSecondsElapsed  = nSecondsElapsed + self.nPeriodSec

        return nCount


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

import logging

logging.basicConfig(filename="DataManager.log", format='%(asctime)s %(message)s', level=logging.DEBUG)

class DataManager:

    def __init__(self):
        """
        Constructor
        """
        # Initialize known dataTypes
        self.lstDataTypes.append(C2DataType(5000, 5000, 1, 5000))   # INTEREST 1


        return 0

    def generateDataQueue(self, lstHosts, nMissionMinutes, sSimulationFactor):
        """
        Generates an unordered queue with packages and send time
        """
        # TODO: Define destination hosts for data packages
        strDest = 'TBD'
        for strHost in lstHosts:
            # Generate data from each host
            if(strHost[0] = 'd'):
                # Drone
                logging.info('[generateDataQueue] Node type drone')
                lstDataTypes[0].generateDataQueue(strHost, strDest, nMissionMinutes)
            else if(strHost[0] = 'h'):
                # Human
                logging.info('[generateDataQueue] Node type human')
            else if(strHost[0] = 's'):
                # Sensor
                logging.info('[generateDataQueue] Node type sensor')
            else if(strHost[0] = 'v'):
                # Vehicle
                logging.info('[generateDataQueue] Node type vehicle')
            else:
                # Unrecognized host type
                logging.error('[generateDataQueue] Unrecognized host type ' + strHost)
        return 0
    
    def orderDataQueue(self):
        """
        Order the queue based on the packages' time offset
        """
        return 0


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
        return 0

    def generateDataQueue(self, strHost, strDest, nMissionMinutes):
        """
        Generates the data queue for a host
        """
        nMissionSeconds = nMissionMinutes * 60
        nSecondsElapsed = 0
        lstData         = []
        while (nSecondsElapsed <= nMissionSeconds):
            # Create data and add to list with miliseconds offset
            data = DataPackage(self.nType, self.nCurID, self.nPayloadSize, strHost, strDest)
            lstData.append((data, nSecondsElapsed*1000))
            self.nCurID += self.nCurID
            nSecondsElapsed = nSecondsElapsed + self.nPeriodSec

        return lstData


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

    def getInterest(self):
        """
        Returns the string representation of the interest filter
        """
        strInterest = '/C2Data/' + self.strOrig + '/C2Data-'
        strInterest = strInterest + str(self.nID) + '-Type' + str(self.nType)
        return strInterest    

    
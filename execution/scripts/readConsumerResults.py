"""
Reads the raw results written by MiniNDN consumers.

Andre Dexheimer Carneiro        04/07/2020
"""
import os

# Constants
c_strBasePath = '/tmp/minindn'
c_strFileName = 'consumerLog.log'


def readResultFile(File):
    """
    Reads the content of a result file
    """
    lstLines  = []
    for strLine in File:
        # Lines are in the format "%s;%.4f;%s", interest, timeDiff, result
        lstContents = strLine.split(';')
        if (len(lstContents) != 3):
            print('[readResultFile] line with more than 3 fields line=' + strLine)
        else:
            print('[readResultFile] (' + lstContents[0] + ', ' + lstContents[1] + ', ' + lstContents[2] + ')')
            lstLines.append(lstContents)

    return lstLines

# Save all directories as node names
lstNodes = os.listdir(c_strBasePath)
hshNodes = {}

# Visit nodes (directories) one by one
for strNode in lstNodes:
    # Read result file for each node
    pFile = open(c_strBasePath + '/' + strNode + '/' + c_strFileName, 'r')
    if (pFile):
        print('[main] reading results for node=' + strNode)
        hshNodes[strNode] = readResultFile(pFile)
        pFile.close()
    else:
        print('[main] ERROR reading information for node=' + strNode)



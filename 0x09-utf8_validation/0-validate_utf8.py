#!/usr/bin/python3
def validUTF8(data):
    """
    """
    countBytes = 0
    oneVer = 1 << 7
    secondVer = 1 << 6
    for i in data:
        if countBytes == 0:
            while oneVer & i:
                countBytes += 1
                oneVer = oneVer >> 1

            if countBytes == 0:
                continue
            if countBytes == 1 or countBytes > 4:
                return False
        else:
            if not (i & oneVer and not (i & secondVer)):
                return False
        countBytes -= 1
    return countBytes == 0

#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only
    need to handle the 8 least significant bits of each integer
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

#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """
    Returns an integer
    If n is impossible to achieve, return 0
    """


    if not n or n < 2:
        return 0
    nOperations = 0
    for time in range(2, n+1):
        while(n % time == 0):
            nOperations += time
            n = n / time
    return(nOperations)


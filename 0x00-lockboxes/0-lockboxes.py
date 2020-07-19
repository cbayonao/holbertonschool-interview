#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    boxes is a list of lists
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
    """
    boxOne = [0]
    for key in boxOne:
        for keyBox in boxes[key]:
            if keyBox not in boxOne:
                if keyBox < len(boxes):
                    boxOne.append(keyBox)
    if len(boxOne) == len(boxes):
        return True
    return False

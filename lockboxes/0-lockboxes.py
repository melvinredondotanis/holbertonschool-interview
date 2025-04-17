#!/usr/bin/python3
"""Exercise to practice interview"""


def canUnlockAll(boxes):
    """Checks if all boxes can be unlocked"""
    n = len(boxes)
    unlocked = [False] * n
    unlocked[0] = True
    keys = boxes[0].copy()
    
    while keys:
        key = keys.pop()
        if 0 <= key < n and not unlocked[key]:
            unlocked[key] = True
            keys.extend([k for k in boxes[key] if 0 <= k < n and not unlocked[k]])
    
    return all(unlocked)

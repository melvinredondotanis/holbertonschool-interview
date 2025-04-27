#!/usr/bin/python3
"""Minimum Operations"""

def minOperations(n):
    """
    Function that calculates the fewest number of operations
    needed to result in exactly n H characters in the file.
    Args:
        n (int): The number of H characters in the file.
    Returns:
        int: The fewest number of operations needed to result
        in exactly n H characters in the file.
    """
    operations = 0
    summation = 1
    carrier = 0
 
    while summation < n:
        if n % summation == 0:
            carrier = summation
            summation *= 2
            operations += 1
        else:
            summation += carrier
        operations += 1

    return operations

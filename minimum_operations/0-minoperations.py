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
    if n <= 1:
        return 0

    operations = 0
    i = 2
    while i <= n:
        while n % i == 0:
            operations += i
            n //= i
        i += 1

    return operations

#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics
"""

from sys import stdin

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    list_status_codes = ["200",
                         "301",
                         "400",
                         "401",
                         "403",
                         "404",
                         "405",
                         "500"]

    for status in list_status_codes:
        status_codes[status] = 0

    count = 0
    try:
        for line in stdin:
            args = line.split(" ")
            if len(args) != 9:
                pass
            if args[-2] in list_status_codes:
                status_codes[args[-2]] += 1
            if args[-1][-1] == '\n':
                args[-1][:-1]

            total_size += int(args[-1])
            count += 1
            if count % 10 == 0:
                print(f"File size: {total_size}")
                for status in sorted(status_codes.keys()):
                    if status_codes[status] != 0:
                        print(f"{status}: {status_codes[status]}")
        print(f"File size: {total_size}")
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print(f"{status}: {status_codes[status]}")

    except KeyboardInterrupt as e:
        print(f"File size: {total_size}")
        for status in sorted(status_codes.keys()):
            if status_codes[status] != 0:
                print(f"{status}: {status_codes[status]}")
        raise e

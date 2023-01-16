import pytest


def test_average(salary, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.average(salary)
    assert answer == expected

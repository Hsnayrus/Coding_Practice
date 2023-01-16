import pytest


@pytest.mark.parametrize("n, expected", [
    (0, 0)
])
def test_hammingWeight(n, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.hammingWeight(n)
    assert answer == expected

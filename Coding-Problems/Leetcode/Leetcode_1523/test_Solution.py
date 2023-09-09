import pytest


@pytest.mark.parametrize("low, high, expected", [
    (0, 0, 0)
])
def test_countOdds(low, high, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.countOdds(low, high)
    assert answer == expected

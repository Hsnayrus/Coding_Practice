import pytest


@pytest.mark.parametrize("x, y, points, expected", [
    (0, 0, [[0]], 0)
])
def test_nearestValidPoint(x, y, points, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.nearestValidPoint(x, y, points)
    assert answer == expected

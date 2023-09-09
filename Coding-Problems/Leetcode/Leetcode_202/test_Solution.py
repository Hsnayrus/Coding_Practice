import pytest


@pytest.mark.parametrize("n, expected", [
    (0, False)
])
def test_isHappy(n, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.isHappy(n)
    assert answer == expected

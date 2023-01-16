import pytest


@pytest.mark.parametrize("n, expected", [
    (0, 0)
])
def test_subtractProductAndSum(n, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.subtractProductAndSum(n)
    assert answer == expected

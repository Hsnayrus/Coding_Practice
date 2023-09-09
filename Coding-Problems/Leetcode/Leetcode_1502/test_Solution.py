import pytest


@pytest.mark.parametrize("arr, expected", [
    ([], True)
])
def test_canMakeArithmeticProgression(arr, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.canMakeArithmeticProgression(arr)
    assert answer == expected

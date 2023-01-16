import pytest


@pytest.mark.parametrize("nums, expected", [
    ([0, 0, 0], 0)
])
def test_largestPerimeter(nums, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.largestPerimeter(nums)
    assert answer == expected

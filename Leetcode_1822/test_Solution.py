import pytest


@pytest.mark.parametrize("nums, expected", [
    ([], 0)
])
def test_arraySign(nums, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.arraySign(nums)
    assert answer == expected

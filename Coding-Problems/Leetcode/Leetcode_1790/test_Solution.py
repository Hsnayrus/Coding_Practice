import pytest


@pytest.mark.parametrize("str1, str2, expected", [
    ("bank", "kanb", True)
])
def test_areAlmostEqual(str1, str2, expected):
    from Solution import Solution
    s1 = Solution()
    answer = s1.areAlmostEqual(str1, str2)
    assert answer == expected

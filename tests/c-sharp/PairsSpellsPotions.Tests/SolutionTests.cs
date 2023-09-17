namespace PairsSpellsPotions.Tests;

public class SolutionTests
{
    private readonly Solution _target = new();

    [Fact]
    public void Example1Test()
    {
        IEnumerable<int> expected = new[] { 4, 0, 3 };
        var result = _target.SuccessfulPairs(new[] { 5, 1, 3 }, new[] { 1, 2, 3, 4, 5 }, 7);
        Assert.Equal(expected, result);
    }

    [Fact]
    public void Example2Test()
    {
        IEnumerable<int> expected = new[] { 2, 0, 2 };
        var result = _target.SuccessfulPairs(new[] { 3, 1, 2 }, new[] { 8, 5, 8 }, 16);
        Assert.Equal(expected, result);
    }

    [Fact]
    public void OverflowTest()
    {
        IEnumerable<int> expected = new[] { 3, 2, 1 };
        var result = _target.SuccessfulPairs(new[] { 85_899_345, 42_949_672, 21_474_836 }, new[] { 52, 104, 205 }, 4_294_967_296);
        Assert.Equal(expected, result);
    }
}

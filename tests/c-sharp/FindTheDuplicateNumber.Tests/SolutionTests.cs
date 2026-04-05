namespace FindTheDuplicateNumber.Tests;

public class SolutionTests
{
    private readonly Solution _target = new();

    [ClassData(typeof(FindDuplicateTestData))]
    [Theory]
    public void FindDuplicateTest(int[] input, int expected)
    {
        Assert.Equal(expected, _target.FindDuplicate(input));
    }
}

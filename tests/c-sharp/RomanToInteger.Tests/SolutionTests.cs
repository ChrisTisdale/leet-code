namespace RomanToInteger.Tests;

public class SolutionTests
{
    private readonly Solution _target = new();

    [Fact]
    public void Example1()
    {
        Assert.Equal(3, _target.RomanToInt("III"));
    }

    [Fact]
    public void Example2()
    {
        Assert.Equal(58, _target.RomanToInt("LVIII"));
    }

    [Fact]
    public void Example3()
    {
        Assert.Equal(1994, _target.RomanToInt("MCMXCIV"));
    }

    [Fact]
    public void Example4()
    {
        Assert.Equal(20, _target.RomanToInt("XX"));
    }
}

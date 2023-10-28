namespace RomanToInteger.Tests;

public class SolutionTests
{
    private readonly Solution _target = new();

    [Fact]
    public void Example1()
    {
        _target.RomanToInt("III").Should().Be(3);
    }

    [Fact]
    public void Example2()
    {
        _target.RomanToInt("LVIII").Should().Be(58);
    }

    [Fact]
    public void Example3()
    {
        _target.RomanToInt("MCMXCIV").Should().Be(1994);
    }

    [Fact]
    public void Example4()
    {
        _target.RomanToInt("XX").Should().Be(20);
    }
}

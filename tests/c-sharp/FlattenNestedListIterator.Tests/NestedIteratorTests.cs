namespace FlattenNestedListIterator.Tests;

public class NestedIteratorTests
{
    [ClassData(typeof(NestedIteratorTestData))]
    [Theory]
    public void InputTests(IList<NestedInteger> input, IEnumerable<int> expected)
    {
        var target = new NestedIterator(input);
        var result = new List<int>();
        while (target.HasNext())
        {
            result.Add(target.Next());
        }

        Assert.Equal(expected, result);
    }
}

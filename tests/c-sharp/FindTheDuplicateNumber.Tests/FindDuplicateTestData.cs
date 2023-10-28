namespace FindTheDuplicateNumber.Tests;

using System.Collections;

public class FindDuplicateTestData : IEnumerable<object[]>
{
    private static readonly List<object[]> TestData = new()
    {
        new object[]
        {
            new[] { 1, 3, 4, 2, 2 },
            2
        },
        new object[]
        {
            new[] { 2, 2, 2, 2, 2, 2, 2 },
            2
        },
        new object[]
        {
            new[] { 3, 1, 3, 4, 2 },
            3
        }
    };

    public IEnumerator<object[]> GetEnumerator() => TestData.GetEnumerator();

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
}

namespace FlattenNestedListIterator.Tests;

using System.Collections;

public class NestedIteratorTestData : IEnumerable<object[]>
{
    private static readonly List<object[]> TestData = new()
    {
        new object[]
        {
            new List<NestedInteger>
            {
                new ListNestedInteger { new IntListNestedInteger(1), new IntListNestedInteger(1) },
                new IntListNestedInteger(2),
                new ListNestedInteger { new IntListNestedInteger(1), new IntListNestedInteger(1) }
            },
            new[] { 1, 1, 2, 1, 1 }
        },
        new object[]
        {
            new List<NestedInteger>
            {
                new IntListNestedInteger(1),
                new ListNestedInteger { new IntListNestedInteger(4), new ListNestedInteger { new IntListNestedInteger(6) } }
            },
            new[] { 1, 4, 6 }
        },
        new object[]
        {
            new List<NestedInteger>
            {
                new ListNestedInteger { new ListNestedInteger() }
            },
            Array.Empty<int>()
        },
        new object[]
        {
            new List<NestedInteger>
            {
                new ListNestedInteger { new ListNestedInteger { new ListNestedInteger { new ListNestedInteger() } } }
            },
            Array.Empty<int>()
        },
        new object[]
        {
            new List<NestedInteger>
            {
                new ListNestedInteger { new ListNestedInteger { new ListNestedInteger { new ListNestedInteger() } } },
                new ListNestedInteger()
            },
            Array.Empty<int>()
        },
        new object[]
        {
            new List<NestedInteger>
            {
                new ListNestedInteger { new ListNestedInteger { new ListNestedInteger { new ListNestedInteger() } } },
                new IntListNestedInteger(1),
                new ListNestedInteger(),
                new ListNestedInteger { new ListNestedInteger() }
            },
            new[] { 1 }
        },
        new object[]
        {
            new List<NestedInteger>
            {
                new IntListNestedInteger(1), new IntListNestedInteger(2), new IntListNestedInteger(3), new IntListNestedInteger(4)
            },
            new[] { 1, 2, 3, 4 }
        }
    };

    public IEnumerator<object[]> GetEnumerator() => TestData.GetEnumerator();

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
}

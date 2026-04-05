namespace FlattenNestedListIterator.Tests;

using System.Collections;

public class NestedIteratorTestData : IEnumerable<TheoryDataRow<List<NestedInteger>, int[]>> {
    private static readonly List<TheoryDataRow<List<NestedInteger>, int[]>> TestData = [
        new(
            [
                new ListNestedInteger { new IntListNestedInteger(1), new IntListNestedInteger(1) },
                new IntListNestedInteger(2),
                new ListNestedInteger { new IntListNestedInteger(1), new IntListNestedInteger(1) }
            ],
            [1, 1, 2, 1, 1]
        ),
        new(
            [
                new IntListNestedInteger(1),
                new ListNestedInteger { new IntListNestedInteger(4), new ListNestedInteger { new IntListNestedInteger(6) } }
            ],
            [1, 4, 6]
        ),
        new(
            [new ListNestedInteger { new ListNestedInteger() }],
            []
        ),
        new(
            [new ListNestedInteger { new ListNestedInteger { new ListNestedInteger { new ListNestedInteger() } } }],
            []
        ),
        new(
            [
                new ListNestedInteger { new ListNestedInteger { new ListNestedInteger { new ListNestedInteger() } } },
                new ListNestedInteger()
            ],
            []
        ),
        new(
            [
                new ListNestedInteger { new ListNestedInteger { new ListNestedInteger { new ListNestedInteger() } } },
                new IntListNestedInteger(1),
                new ListNestedInteger(),
                new ListNestedInteger { new ListNestedInteger() }
            ],
            [1]
        ),
        new(
            [new IntListNestedInteger(1), new IntListNestedInteger(2), new IntListNestedInteger(3), new IntListNestedInteger(4)],
            [1, 2, 3, 4]
        )
    ];

    public IEnumerator<TheoryDataRow<List<NestedInteger>, int[]>> GetEnumerator() => TestData.GetEnumerator();

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
}

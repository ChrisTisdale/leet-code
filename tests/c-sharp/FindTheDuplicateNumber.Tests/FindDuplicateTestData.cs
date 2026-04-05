namespace FindTheDuplicateNumber.Tests;

using System.Collections;

public class FindDuplicateTestData : IEnumerable<TheoryDataRow<int[], int>> {
    private static readonly List<TheoryDataRow<int[], int>> TestData = [
        new(
            [1, 3, 4, 2, 2],
            2
        ),

        new(
            [2, 2, 2, 2, 2, 2, 2],
            2
        ),

        new(
            [3, 1, 3, 4, 2],
            3
        )
    ];

    public IEnumerator<TheoryDataRow<int[], int>> GetEnumerator() => TestData.GetEnumerator();

    IEnumerator IEnumerable.GetEnumerator() => GetEnumerator();
}

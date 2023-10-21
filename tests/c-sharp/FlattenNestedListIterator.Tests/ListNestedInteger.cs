namespace FlattenNestedListIterator.Tests;

public class ListNestedInteger : List<NestedInteger>, NestedInteger
{
    public bool IsInteger() => false;

    public int GetInteger() => throw new InvalidOperationException();

    public IList<NestedInteger> GetList() => this;
}

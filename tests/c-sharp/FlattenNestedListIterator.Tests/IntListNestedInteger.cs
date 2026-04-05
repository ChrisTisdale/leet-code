namespace FlattenNestedListIterator.Tests;

using Xunit.Sdk;

public record IntListNestedInteger : NestedInteger
{
    private readonly int _value;

    public IntListNestedInteger(int value) => _value = value;

    public bool IsInteger() => true;

    public int GetInteger() => _value;

    public IList<NestedInteger> GetList() => null!;
}

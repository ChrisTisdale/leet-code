namespace FlattenNestedListIterator;

public class NestedIterator
{
    private readonly IList<NestedInteger> _nestedList;
    private int _currentIndex;
    private NestedIterator? _iter;

    public NestedIterator(IList<NestedInteger> nestedList)
    {
        _nestedList = nestedList;
        PeekNext();
    }

    public bool HasNext() => _currentIndex < _nestedList.Count || (_iter?.HasNext() ?? false);

    public int Next()
    {
        if (_iter is not null)
        {
            if (_iter.HasNext())
            {
                var next = _iter.Next();
                if (_iter.HasNext())
                {
                    return next;
                }

                _iter = null;
                PeekNext();
                return next;
            }

            _iter = null;
        }

        var cur = _nestedList[_currentIndex++];
        if (cur.IsInteger())
        {
            PeekNext();
            return cur.GetInteger();
        }

        _iter = new NestedIterator(cur.GetList());
        return Next();
    }

    private void PeekNext()
    {
        while (_currentIndex < _nestedList.Count && (_iter is null || !_iter.HasNext()))
        {
            if (!_nestedList[_currentIndex].IsInteger())
            {
                _iter = new NestedIterator(_nestedList[_currentIndex++].GetList());
            }
            else
            {
                break;
            }
        }
    }
}

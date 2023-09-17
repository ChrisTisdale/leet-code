namespace RomanToInteger;

public sealed class Solution
{
    public int RomanToInt(string s)
    {
        var amount = 0;
        var last = int.MaxValue;

        for (var i = 0; i < s.Length; ++i)
        {
            var current = GetAmount(s[i]);
            if (current > last)
            {
                amount -= last;
                amount -= last;
            }

            amount += current;
            last = current;
        }

        return amount;
    }

    private static int GetAmount(char c) =>
        c switch
        {
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            _ => 1000
        };
}

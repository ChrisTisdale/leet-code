namespace PairsSpellsPotions;

public sealed class Solution
{
    public int[] SuccessfulPairs(int[] spells, int[] potions, long success)
    {
        var results = new int[spells.Length];
        Array.Sort(potions);

        for (var i = 0; i < spells.Length; ++i)
        {
            results[i] = Search(spells[i], potions, success);
        }

        return results;
    }

    private static int Search(long spell, IReadOnlyList<int> potions, long success)
    {
        var min = 0;
        var max = potions.Count - 1;
        var found = potions.Count;
        while (min <= max)
        {
            var mid = min + (max - min) / 2;
            var res = spell * potions[mid];
            if (res >= success)
            {
                max = mid - 1;
                found = mid;
            }
            else
            {
                min = mid + 1;
            }
        }

        return potions.Count - found;
    }
}

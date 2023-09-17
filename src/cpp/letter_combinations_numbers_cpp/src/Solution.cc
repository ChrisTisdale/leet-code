#include "Solution.h"

static const char TwoItems[] = {'a', 'b', 'c'};
static const char TheeItems[] = {'d', 'e', 'f'};
static const char FourItems[] = {'g', 'h', 'i'};
static const char FiveItems[] = {'j', 'k', 'l'};
static const char SixItems[] = {'m', 'n', 'o'};
static const char SevenItems[] = {'p', 'q', 'r', 's'};
static const char EightItems[] = {'t', 'u', 'v'};
static const char NineItems[] = {'w', 'x', 'y', 'z'};

std::vector<std::string> Solution::letterCombinations(std::string digits) {
    std::vector<std::string> result;
    for (size_t i = 0; i < digits.length(); ++i) {
        switch (digits[i])
        {
        case '2':
            result = getLetters(result, TwoItems);
            break;
        case '3':
            result = getLetters(result, TheeItems);
            break;
        case '4':
            result = getLetters(result, FourItems);
            break;
        case '5':
            result = getLetters(result, FiveItems);
            break;
        case '6':
            result = getLetters(result, SixItems);
            break;
        case '7':
            result = getLetters(result, SevenItems);
            break;
        case '8':
            result = getLetters(result, EightItems);
            break;
        case '9':
            result = getLetters(result, NineItems);
            break;
        default:
            break;
        }
    }

    return result;
}

template<std::size_t S>
std::vector<std::string> Solution::getLetters(const std::vector<std::string> &data, const char (&input)[S]) {
    if (data.empty()) {
        std::vector<std::string> result;
        result.reserve(S);
        for (size_t i = 0; i < S; ++i) {
            result.push_back(std::string(1, input[i]));
        }

        return result;
    }

    size_t len = data.size() * S;
    size_t c = 0;
    std::vector<std::string> result;
    result.reserve(len);
    for (size_t i = 0; i < len; ++i) {
        result.push_back(std::string(data[i % data.size()] + input[c % S]));
        if (result.size() % data.size() == 0) {
            ++c;
        }
    }

    return result;
}

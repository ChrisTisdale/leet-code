pub struct Solution {}

struct Roman<'a> {
    text: &'a str,
    value: i32,
}

#[macro_export]
macro_rules! roman {
    ($lhs: literal, $rhs: literal) => {
        Roman {
            text: $lhs,
            value: $rhs,
        }
    };
}

static ROMAN_LOOKUP: &[Roman] = &[
    roman!("M", 1000),
    roman!("CM", 900),
    roman!("D", 500),
    roman!("CD", 400),
    roman!("C", 100),
    roman!("XC", 90),
    roman!("L", 50),
    roman!("XL", 40),
    roman!("X", 10),
    roman!("IX", 9),
    roman!("V", 5),
    roman!("IV", 4),
    roman!("I", 1),
];

impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        let mut result = String::new();
        let mut slice = ROMAN_LOOKUP;
        while num > 0 {
            for lookup in slice.iter() {
                if num >= lookup.value {
                    num -= lookup.value;
                    result.push_str(lookup.text);
                    break;
                }

                slice = &slice[1..];
            }
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1_test() {
        let result = Solution::int_to_roman(3);
        assert_eq!(result, String::from("III"));
    }

    #[test]
    fn example_2_test() {
        let result = Solution::int_to_roman(58);
        assert_eq!(result, String::from("LVIII"));
    }

    #[test]
    fn example_3_test() {
        let result = Solution::int_to_roman(1994);
        assert_eq!(result, String::from("MCMXCIV"));
    }

    #[test]
    fn example_4_test() {
        let result = Solution::int_to_roman(20);
        assert_eq!(result, String::from("XX"));
    }
}

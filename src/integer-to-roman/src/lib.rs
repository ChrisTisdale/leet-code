pub struct Solution {}

struct Roman<'a> {
    text: &'a str,
    value: i32,
}

static ROMAN_LOOKUP: &[Roman] = &[
    Roman {
        text: "M",
        value: 1000,
    },
    Roman {
        text: "CM",
        value: 900,
    },
    Roman {
        text: "D",
        value: 500,
    },
    Roman {
        text: "CD",
        value: 400,
    },
    Roman {
        text: "C",
        value: 100,
    },
    Roman {
        text: "XC",
        value: 90,
    },
    Roman {
        text: "L",
        value: 50,
    },
    Roman {
        text: "XL",
        value: 40,
    },
    Roman {
        text: "X",
        value: 10,
    },
    Roman {
        text: "IX",
        value: 9,
    },
    Roman {
        text: "V",
        value: 5,
    },
    Roman {
        text: "IV",
        value: 4,
    },
    Roman {
        text: "I",
        value: 1,
    },
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
                } else {
                    slice = &slice[1..];
                }
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

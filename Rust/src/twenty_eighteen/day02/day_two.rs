use std::collections::HashMap;

#[allow(dead_code)]
pub fn solve(ids: &Vec<String>) -> Result<i32, String> {
    let mut twice: i32 = 0;
    let mut trice: i32 = 0;

    for id in ids {
        twice += count_char_occurrences(id).0;
        trice += count_char_occurrences(id).1;
    }

    return Ok((twice * trice) as i32);
}

#[allow(dead_code)]
pub fn solve_two(ids: &Vec<String>) -> Result<String, &str> {
    for i in 0..ids.len() {
        for j in i+1..ids.len() {
            if let Some(common)= common_correct_letters(&ids[i], &ids[j]) {
                return Ok(common);
            }
        }
    }
    Err("could not find two correct box ids")
}

#[allow(dead_code)]
fn count_char_occurrences(s: &str) -> (i32, i32) {
    let char_counts = s.chars().fold(HashMap::new(), |mut acc, c| {
        *acc.entry(c).or_insert(0) += 1;
        acc
    });

    let mut twice_count: i32 = 0;
    let mut thrice_count: i32 = 0;

    for count in char_counts.values() {
        if *count == 2 {
            twice_count = 1;
        } else if *count == 3 {
            thrice_count = 1;
        }
    }
    return (twice_count, thrice_count);
}

#[allow(dead_code)]
fn common_correct_letters(id1: &str, id2: &str) -> Option<String> {
    if id1.len() != id2.len() {
        return None;
    }

    let mut found_one_wrong = false;
    for (c1, c2) in id1.chars().zip(id2.chars()) {
        if c1 != c2 {
            if found_one_wrong {
                return None;
            }
            found_one_wrong = true;
        }
    }
    return Some(
        id1.chars().zip(id2.chars())
            .filter(|&(c1, c2)| c1 == c2)
            .map(|(c, _)| c)
            .collect::<String>()
    );
}

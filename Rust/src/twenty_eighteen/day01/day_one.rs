use std::collections::HashSet;
use std::num::ParseIntError;

#[allow(dead_code)]
pub fn solve(contents: &Vec<String>) -> Result<i32, ParseIntError> {
    let parsed_numbers: Result<Vec<i32>, _> = contents
        .iter()
        .map(|line| line.parse::<i32>())
        .collect();

    match parsed_numbers {
        Ok(numbers) => Ok(numbers.iter().sum()),
        Err(err) => Err(err)
    }
}

#[allow(dead_code)]
pub fn solve_two(contents: &Vec<String>) -> Result<i32, ParseIntError> {
    let parsed_numbers: Result<Vec<i32>, _> = contents
        .iter()
        .map(|line| line.parse::<i32>())
        .collect();

    let numbers: Vec<i32> = parsed_numbers?;

    let mut seen_sums: HashSet<i32> = HashSet::new();
    let mut sum = 0;

    loop {
        for number in &numbers {
            seen_sums.insert(sum);
            sum += number;

            if seen_sums.contains(&sum) {
                return Ok(sum);
            }
        }
    }
}

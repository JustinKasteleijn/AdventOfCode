#![feature(let_chains)]

mod utils {
    pub mod file;
}

mod twenty_eighteen {
    pub mod day04 {
        pub mod day_four;
    }
}

use utils::file::read_file_as_vector;
use crate::twenty_eighteen::day04::day_four::solve;

fn main() {
    let file_path = "C:/Users/justi/AdventOfCode/rust/src/twenty_eighteen/day04/input.txt";

    if let Ok(contents) = read_file_as_vector(file_path) {
        match solve(&contents) {
            Ok(val) => println!("{:?}", val),
            Err(err) => println!("Oops something went wrong {:?}", err)
        }
    } else {
        println!("File can not be read");
    }
}

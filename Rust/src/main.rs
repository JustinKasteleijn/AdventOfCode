#![feature(let_chains)]

mod utils {
    pub mod file;
}

mod twenty_eighteen {
    pub mod day03 {
        pub mod day_three;
    }
}

use utils::file::read_file_as_vector;
use crate::twenty_eighteen::day03::day_three::solve;

fn main() {
    let file_path = "C:/Users/justi/AdventOfCode/rust/src/twenty_eighteen/day02/input.txt";

    if let Ok(contents) = read_file_as_vector(file_path) {
        match solve(&contents) {
            Ok(checksum) => println!("{}", checksum),
            Err(err) => println!("Oops something went wrong {:?}", err)
        }
    } else {
        println!("File can not be read");
    }
}

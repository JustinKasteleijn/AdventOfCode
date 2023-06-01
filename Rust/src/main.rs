mod utils {
    pub mod file;
}

mod day01 {
    pub mod day_one;
}


use utils::file::read_file_as_vector;
use crate::day01::day_one::solve_two;

fn main() {
    let file_path = "C:/Users/justi/AdventOfCode/rust/src/day01/input.txt";

    if let Ok(contents) = read_file_as_vector(file_path) {
        match solve_two(contents) {
            Ok(sum) => println!("{}", sum),
            Err(err) => println!("Oops something went wrong {:?}", err)
        }
    } else {
        println!("File can not be read");
    }
}

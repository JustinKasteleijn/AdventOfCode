use std::{fs, io};
use std::io::BufRead;

pub fn read_file_as_string(file_path: &str) -> Result<String, io::Error> {
    return fs::read_to_string(file_path);
}

pub fn read_file_as_vector(file_path: &str) -> Result<Vec<String>, io::Error> {
    return io::BufReader::new(
        fs::File::open(file_path)?
    )
        .lines()
        .collect();
}


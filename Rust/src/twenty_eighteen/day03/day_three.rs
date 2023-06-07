use std::num::ParseIntError;
use lazy_static::lazy_static;
use regex::{Error, Regex};

#[derive(Debug)]
pub struct Fabric {
    x: i32,
    y: i32,
    width: i32,
    height: i32,
}

impl Fabric {
    pub fn new(x: i32, y: i32, width: i32, height: i32) -> Fabric {
        Fabric {
            x,
            y,
            width,
            height,
        }
    }
}

impl FromVec for Fabric {
    type Err = Box<Error>;

    fn from_vector(input: &Vec<String>) -> Result<Vec<Fabric>> {
        let mut result: Vec<Fabric> = Vec::with_capacity(input.len());

        lazy_static! {
            static ref RE: Regex = Regex::new(r"(?x)
                \#
                (?P<id>[0-9]+)
                \s+@\s+
                (?P<x>[0-9]+),(?P<y>[0-9]+):
                \s+
                (?P<width>[0-9]+)x(?P<height>[0-9]+)
            ").unwrap();
        }

        for line in input {
            let caps = RE.captures(line).ok_or("unrecognized claim")?;
            result.push(
                Fabric {
                    x: caps["x"].parse()?,
                    y: caps["y"].parse()?,
                    width: caps["width"].parse()?,
                    height: caps["height"].parse()?,
                }
            )
        }

        return Ok(result);
    }
}


pub fn solve(input: &Vec<String>) -> Result<i32, String> {
    let x = Fabric::from_vector(input);
    println!("{:?}", x);
    return Ok((0));
}

use lazy_static::lazy_static;
use regex::Regex;

#[derive(Debug)]
pub struct Fabric {
    id: i32,
    x: i32,
    y: i32,
    width: i32,
    height: i32,
}

pub trait FromVector {
    fn from_vector(input: &Vec<String>) -> Result<Vec<Fabric>, String>;
}

impl FromVector for Fabric {
    fn from_vector(input: &Vec<String>) -> Result<Vec<Fabric>, String> {
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
            result.push(Fabric {
                id: caps["id"].parse().map_err(|_| "Failed to parse id")?,
                x: caps["x"].parse().map_err(|_| "failed to parse x")?,
                y: caps["y"].parse().map_err(|_| "failed to parse y")?,
                width: caps["width"].parse().map_err(|_| "failed to parse width")?,
                height: caps["height"].parse().map_err(|_| "failed to parse height")?,
            });
        }
        Ok(result)
    }
}

#[allow(dead_code)]
pub fn solve2(input: &Vec<String>) -> Result<i32, String> {
    let mut grid: Vec<Vec<i8>> = vec![vec![0; 1000]; 1000];
    let fabrics = Fabric::from_vector(input)?;

    run_fabrics(&mut grid, &fabrics);

    for fabric in fabrics.iter() {
        let mut _match = true;
        for x in fabric.x..(fabric.x + fabric.width) {
            if !_match {
                continue;
            }
            for y in fabric.y..(fabric.y + fabric.height) {
                if grid[x as usize][y as usize] == 1 && _match {
                    continue;
                } else {
                    _match = false;
                    break;
                }
            }
        }
        if _match {
            return Ok(fabric.id);
        }
    }

    Err("No matching fabric found".to_string())
}

fn run_fabrics(grid: &mut Vec<Vec<i8>>, fabrics: &Vec<Fabric>) {
    fabrics.iter().for_each(|fabric: &Fabric| {
        for x in fabric.x..(fabric.x + fabric.width) {
            for y in fabric.y..(fabric.y + fabric.height) {
                grid[x as usize][y as usize] += 1;
            }
        }
    });
}

#[allow(dead_code)]
pub fn solve(input: &Vec<String>) -> Result<i32, String> {
    let mut grid: Vec<Vec<i8>> = vec![vec![0; 1000]; 1000];
    let fabrics = Fabric::from_vector(input)?;

    run_fabrics(&mut grid, &fabrics);

    return Ok(grid
        .into_iter()
        .flatten()
        .filter(|&value| value >= 2)
        .count() as i32);
}

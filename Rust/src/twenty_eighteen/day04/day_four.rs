use chrono::NaiveDateTime;
use nom::bytes::complete::is_not;
use nom::character::complete::char;
use nom::IResult;
use nom::sequence::delimited;

fn parse_datetime(input: &str) -> IResult<&str, &str> {
    return delimited(char('['), is_not("]"), char(']'))(input);
}

#[allow(dead_code)]
pub fn solve(input: &Vec<String>) -> Result<i32, &str> {
    let (remainder, datetime) = parse_datetime("[1518-11-01 00:00] Guard #10 begins shift").unwrap();
    dbg!(datetime);
    let official_datetime: NaiveDateTime = NaiveDateTime::parse_from_str(datetime, "%Y-%m-%d %H:%M").unwrap();
    dbg!(official_datetime);
    return Ok(22);
}

// 1, 7, 19, 37,
//   6  12  18
use std::io;
fn main()
{
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("failure");
    let input = input.trim();
    let input = input.parse::<u32>().expect("failure");

    let mut i = 1;
    let mut next = 1;
    loop {
        if input <= next {
            println!("{}", i);
            break;
        }
        next += 6*i;
        i += 1;
    }
}

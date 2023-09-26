use std::io::{self, Write};

fn is_prime(num: u32) -> bool {
    if num < 2 {
        false
    } else if num == 2 || num == 3 {
        true
    } else if num % 2 == 0 || num % 3 == 0 {
        false
    } else {
        let mut i = 5;
        while i * i <= num {
            if num % i == 0 || num % (i + 2) == 0 {
                return false;
            }
            i += 6;
        }
        true
    }
}

fn get_input() -> u32 {
    let mut input = String::new();
    loop {
        print!("Type a number: ");
        io::stdout().flush().unwrap();
        io::stdin().read_line(&mut input).unwrap();
        let k: u32 = match input.trim().parse() {
            Ok(num) if num >= 2 => num,
            _ => continue,
        };
        return k;
    }
}

fn print_primes(n: u32) {
    if n >= 2 {
        print_primes(n - 1);
        if is_prime(n) {
            println!("{}", n);
        }
    }
}

fn main() {
    let k = get_input();
    print_primes(k);
}

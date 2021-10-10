use std::env;
use std::error::Error;
use std::fmt;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let path = env::args()
        .nth(1)
        .expect("Error, You need to pass a file.txt like argument");
    let inverted =
        RGB::get_inverted_colors(&path).expect("Error, You need to pass numbers between: 0 - 255");
    for color in inverted {
        println!("{}\n", color);
    }
}

struct RGB {
    r: u8,
    g: u8,
    b: u8,
}

impl RGB {
    fn new(r: u8, g: u8, b: u8) -> RGB {
        RGB { r, g, b }
    }

    fn invert(&mut self) {
        self.r = 255 - self.r;
        self.g = 255 - self.g;
        self.b = 255 - self.b;
    }

    fn get_inverted_colors(path: &str) -> Result<Vec<RGB>, Box<dyn Error>> {
        let mut inverted: Vec<RGB> = Vec::new();
        let file = File::open(path).expect("Error opening the file");
        let reader = BufReader::new(file);

        for line in reader.lines() {
            let values = line.expect("Error reading line by line");
            let vec: Vec<&str> = values.split(" ").collect();
            let mut rgb = RGB::new(
                vec[0].parse::<u8>()?,
                vec[1].parse::<u8>()?,
                vec[2].parse::<u8>()?,
            );
            rgb.invert();
            inverted.push(rgb);
        }
        Ok(inverted)
    }
}

impl fmt::Display for RGB {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(
            f,
            "RGB: ({}, {}, {})\nHEX: (0x{:X}{:X}{:X})",
            self.r, self.g, self.b, self.r, self.g, self.b
        )
    }
}

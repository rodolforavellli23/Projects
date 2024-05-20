use std::process::Command;

fn build() -> String{
    //Execute the 'rustc --version' command
    let output = Command::new("rustc").arg("--version").output().expect("Failed to execute rustc!");

    //Convert output to String
    let version = String::from_utf8(output.stdout).expect("Invalid UTF-8 sequence!");

    //Print the rustc version to the console
    return version.chars().filter(|c| c.is_digit(10) || *c == '.').take(6).collect();
}

fn main() {
    //Retrieve the rustc version from the variable set by build()
    
    let rustc_version = build();
    println!("\n\tHello World! From rustc version: {}\n", rustc_version);
}

# leet-code

Project for all leet code problems.

## Building and running

### Setup

#### Rust

Install the rust tool chain <https://doc.rust-lang.org/book/ch01-01-installation.html>.

#### C#

Install the .net 7 SDK <https://dotnet.microsoft.com/en-us/download/dotnet/7.0>.

#### C++

##### Windows Installation

Install Visual Studio 2022 with C++ and CMake

##### Mac Installation

Install X-Code command-line utilities and cmake

##### Linux Installation

Install build-essentails and cmake

### Running

#### Rust

To run all the projects and their tests run:
```bash
cargo test --all-features
```

#### C#

To run all the projects and their tests run: 
```bash
dotnet test leet-code.sln
```

#### C++

##### Windows Builds

Open the folder in visual studio and run

##### Linux & Mac Builds

To run all the project and their tests run:
```bash
cmake -B build
cd build
make
ctest
```

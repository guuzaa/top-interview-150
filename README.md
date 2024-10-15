<h1 align="center"><code>CMaker</code></h1>

CMaker is a CMake template for C/C++ that adopts a Cargo-like package layout.

## What it does
- Designed for C and C++
- Opt for Cargo-like [`package layout`](https://doc.rust-lang.org/cargo/guide/project-layout.html) in CMake.
- Apply [`GoogleTest`](https://github.com/google/googletest) for test and [`Google Benchmark`](https://github.com/google/benchmark) for benchmark
- Use [`Clang-format` and `Clang-tidy`](https://github.com/llvm/llvm-project) for static program analysis (not ready yet)
- Use `Memory Sanitizer` for memory safety check

## Why do this
In my opinion, Cargo might be the best build system in the computer world. It helps us to create a library or an execuable as ease. In addition, it allows us to run some examples or tests of your choice by the cargo run command. However, Cargo is designed only for Rust programming language. If we use C/C++ more often, how can we configure CMake to function similarly to Cargo? `CMaker` is the answer.

## License
CMaker is under the [CC0 1.0 Universial](./LICENSE) license, which means it's in the world-wide public domain.
Header-only parsing and formatting of file sizes
==================================================

Small utility header for human-formatted input and output of file sizes in bytes:

* `5.55k`, `5.55 k`, `5.55kB`, `  5.55 kiB ` to number of bytes
* available case-sensitive prefixes are `k`, `M`, `G`, `T`, `P` (decimal) and `ki`, `Mi`, `Gi`, `Ti`, `Pi` (binary)
* throws exceptions for invalid inputs
* formats to 3-digit precision with affixed decimal units (e.g. `5.55 kB`)
* defined `operator<<` for iostream output
* exposes the type to the [fmt](https://github.com/fmtlib/fmt) library (if you don't want to `#include` fmt, `#define` `BYTESIZE_NO_FMTLIB` or delete offending lines in the header)
* defines c++ literals in `bytesize::literals` namespace

How to use
----------

* To parse a `std::string`, use `bytesize::bytesize::parse` static method
* To output, use `bytesize::bytesize::format`
* Output to ostream and `{}` formatting with [fmt](https://github.com/fmtlib/fmt) automatically
* `using namespace bytesize::literals` to do things like `5.55_kB` in your source


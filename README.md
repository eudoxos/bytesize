Header-only parsing and formatting of file sizes
==================================================

Small utility header for human-formatted input and output of file sizes in bytes:

* `5.55k`, `5.55 k`, `5.55kB`, `  5.55 kiB ` to number of bytes
* available case-sensitive prefixes are `k`, `M`, `G`, `T`, `P` (decimal) and `ki`, `Mi`, `Gi`, `Ti`, `Pi` (binary)
* throws exceptions for invalid inputs
* formats to 3-digit precision with affixed decimal units (e.g. `5.55 kB`)


# Peephole Contest
## Installation
Set environment variable `PEEPDIR` to refer to this directory permanently. Go to `JOOSA-src/` directory, then
```
make
```
## Usage
### Compile
Example: Go to `PeepholeBenchmarks/bench01/` directory, then
```
$PEEPDIR/joosc *.java
```
or the following to enable optimization
```
$PEEPDIR/joosc -O *.java
```
For `bench03`, use the following:
```
$PEEPDIR.joosc -O *.java *.joos
```
### Compute Size
Go to `PeepholeBenchmarks/` directory, then
```
awk '{sum += $3} END {print sum}' bench0*/*.size
```
### Run
As each of the benchmark programs are different, see their respective README files for instructions to run the programs.
### Clean
rm -rf *.class *.j *.optdump *.dump *.size *~

# Peephole Contest
## Installation
Set environment variable `PEEPDIR` to refer to this directory permanently.
Go to `JOOSA-src/` directory, then
```
cd JOOSA-src/
make
```
## Usage
### Make
Example:
Go to `PeepholeBenchmarks/bench01/` directory, then
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
As each benchmark program is different, see their README for instructions to run the program.
### Clean
rm -rf *.class *.j *.optdump *.dump *.size *~

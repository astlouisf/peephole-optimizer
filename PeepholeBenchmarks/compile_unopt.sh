for benchmark in bench01 bench02 bench04 bench05 bench07
do
cd $benchmark
$PEEPDIR/joosc *.java
cd ..
done

# benchmark 3
cd $benchmark
$PEEPDIR/joosc *.java *.joos
cd ..

echo ""
echo "Total size:"
awk '{sum += $3} END {print sum}' bench0*/dump.size

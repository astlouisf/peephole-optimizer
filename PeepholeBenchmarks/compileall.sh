for benchmark in bench01 bench02 bench04 bench05 bench07 # doesn't include benchmark 6
do
cd $benchmark
# $PEEPDIR/joosc *.java	# unoptimized
$PEEPDIR/joosc -O *.java
cd ..
done

# benchmark 3
cd $benchmark
$PEEPDIR/joosc -O *.java *.joos
cd ..


# awk '{sum += $3} END {print sum}' bench0*/dump.size	# unoptimized
echo ""
echo "Total size:"
awk '{sum += $3} END {print sum}' bench0*/optdump.size

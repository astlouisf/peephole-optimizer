# doesn't include benchmark 3 or 6
# bench01 bench02 bench03 bench04 bench05 bench06 bench07
for benchmark in bench01 bench02 bench04 bench05 bench07
do
cd $benchmark
# $PEEPDIR/joosc *.java	# unoptimized
$PEEPDIR/joosc -O *.java
cd ..
done

# awk '{sum += $3} END {print sum}' bench0*/dump.size	# unoptimized
echo ""
echo "Total size:"
awk '{sum += $3} END {print sum}' bench0*/optdump.size

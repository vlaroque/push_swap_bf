for ((i = 0; i < $1; i++)); do
	echo $i $RANDOM
done|
sort -k2|
cut -d" " -f1|
tr '\n' ' '

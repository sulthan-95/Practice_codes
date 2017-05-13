read n
for(( i=0 ; i < n ; ++i ))
do
	read k
	a[$i]=$k
done
echo ${a[*]}

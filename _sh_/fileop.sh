#echo "Enter a file name"
#read name 
i=0
cat $1 |
	while read line
	do
		while $i
		do
			word=`echo $line | cut -d " " -f$i`
			word1=$word
			k=`echo $word1 | cut -c $0`
			w=h
			if test $k == $w 
			then
				$word>>kkr.txt
			fi
			i=`expr $i + 1`
		done
	done


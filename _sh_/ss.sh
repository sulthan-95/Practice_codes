line=`grep 'Hello' hello.txt`
word=`echo $line | cut -d " " -f$0`

sed '1 s/Hello/mello/' hello.txt


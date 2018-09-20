for i in {1337..1488}
do
	echo "$(($(tail -n 1 numbers.txt) + 1))" >> numbers.txt
done


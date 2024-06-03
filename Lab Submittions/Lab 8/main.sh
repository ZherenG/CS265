# Lab8, Zheren Gu
	echo “”
  echo “For Q1”
	grep eggs eggs.txt

	echo “”
	echo “For Q2”
	grep [Hh]am eggs.txt

	echo “”
  echo “For Q3”
	grep ^[wW]ould eggs.txt

	echo “”
	echo “For Q4”
	grep -e "here" -e "there" eggs.txt

	echo “”
  echo “For Q5”
	grep .here eggs.txt

	echo “”
	echo “For Q6”
	grep ^I eggs.txt

	echo “”
	echo “For Q7”
	grep ^[^I] eggs.txt

	echo “”
	echo “For Q8”
	grep here.$ eggs.txt

	echo “”
	echo “For Q9”
	grep -n ^\s*$ eggs.txt

	echo “”
	echo “For Q10”
	grep [^\s*$] eggs.txt



	echo “”
  echo “For Q1”
	awk 'END{print NR}' heart.csv

	echo “”
	echo “For Q2”
  awk 'FNR<=5' heart.csv

	echo “”
  echo “For Q3”
  awk NF heart.csv

	echo “”
	echo “For Q4”
	awk '$1~/^1[123456789]/' heart.csv

	echo “”
  echo “For Q5”
	awk -F "\"*,\"*" '{print $4}' heart.csv

	echo “”
	echo “For Q6”
	awk -F ',' '{print NF,$0}' heart.csv

	echo “”
	echo “For Q7”
	awk -F "," 'END{print $NF}' heart.csv

	echo “”
	echo “For Q8”
	 awk -F ',' '{if($6==1) {print $6}}' heart.csv

	echo “”
	echo “For Q9”
	awk -F ',' 'END{print NR*NF}' heart.csv

	echo “”
	echo “For Q10”
	awk -F ',' ' BEGIN {count=0;}  { if ($3 == "F") count+=1} END {print count}' heart.csv 
 awk -F ',' ' BEGIN {count=0;}  { if ($3 == "M") count+=1} END {print count}' heart.csv 
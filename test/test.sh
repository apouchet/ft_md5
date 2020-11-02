#!/bin/sh

tools() {
	echo "Test Numero : $i";
	echo "echo $3 | md5 $1 $2"
	echo $3 | md5 $1 $2 > real
	echo $3 | ./ft_ssl MD5 $1 $2 > new
	difference md5 
	i=$((i+1))
}

fourth_test() {
	tools -stest -p 
	tools -stest -p "ok" 
	tools -stest -r "tes" 
	tools -p -r "123" 
	tools -pr -stest "ko" 
	tools -prqst -stest "asdasd"
	tools -rqst -stest "NULL"
	tools -pshello -p "test"
}

third_test() {
	input="custom"
	while IFS= read -r line
	do
		echo "Test Numero : $i";
		echo $line | openssl $1 > real
		echo $line | ./ft_ssl $1 > new
		difference $1 $line
		i=$((i+1))
	done < "$input"
}

second_test() {
	while ((i!=j))
	do
		echo "Test Numero : $i";
		number=`openssl rand -base64 $(( ( RANDOM % 50 ) + 1 ))`
		echo $number | openssl $1 > real
		echo $number | ./ft_ssl $1 > new
		difference $1 $number
		i=$((i+1))
	done
}

difference () {
	echo "\033[32m"
	cat real
	echo "\033[33m"
	cat new
	DIFF=$(diff real new)
	if [ "$DIFF" != "" ]
	then
		mkdir -p error_test 2> /dev/null || true
		printf "%-70s\033[31mKO\n"
		dif="error_test/$1-$i-diff"
		echo "for \"$2\"\n" > $dif
		echo "Real $1" >> $dif; cat real >> $dif
		echo "Your $1" >> $dif; cat new >> $dif
		echo "Création du fichier $dif\033[00m"
	else
		valid=$((valid+1))
		printf "%-70s\033[32mOK\033[00m\n\n"
	fi
	rm -f real new
}


first_test () {
	for fichier in ./files/*
		do
			echo $fichier
			if [ ! -e $fichier ]
			then
				break;
			else
				echo "Test Numero : $i";
				openssl $1 $fichier > real
				./ft_ssl $1 $fichier > new
				difference $1 $fichier
				echo "\n"
			fi
			i=$((i+1))
		done
}

md5_fun() {
	echo "\n\nMD5\n\n"
	i=1
	valid=0
	first_test MD5
	N=10
	#read -p "Combien de try ?\n" N
	j=$((i+$N))
	second_test MD5
	third_test MD5
	fourth_test
	echo "\033[33m[$valid / $((i-1))]\033[00m"
	read -p "Appuez sur Return pour continuer..."
}

sha224_fun () {
	echo "\n\nSHA224\n\n"
	i=1
	valid=0
	first_test SHA224
	#read -p "Combien de try ?\n" N
	N=10
	j=$((i+$N))
	second_test SHA224
	third_test SHA224
	echo "\033[33m[$valid / $((i-1))]\033[00m"
	read -p "Appuez sur Return pour continuer..."

}

sha256_fun () {
	echo "\n\nSHA256\n\n"
	i=1
	valid=0
	first_test SHA256
	#read -p "Combien de try ?\n" N
	N=10
	j=$((i+$N))
	second_test SHA256
	third_test SHA256
	echo "\033[33m[$valid / $((i-1))]\033[00m"
	read -p "Appuez sur Return pour continuer..."

}

sha384_fun () {
	echo "\n\nSHA384\n\n"
	i=1
	valid=0
	first_test SHA384
	#read -p "Combien de try ?\n" N
	N=10
	j=$((i+$N))
	second_test SHA384
	third_test SHA384
	echo "\033[33m[$valid / $((i-1))]\033[00m"
	read -p "Appuez sur Return pour continuer..."

}

sha512_fun () {
	echo "\n\nSHA512\n\n"
	i=1
	valid=0
	first_test SHA512
	#read -p "Combien de try ?\n" N
	N=10
	j=$((i+$N))
	second_test SHA512
	third_test SHA512
	echo "\033[33m[$valid / $((i-1))]\033[00m"
	read -p "Appuez sur Return pour continuer..."

}

cd test
cp ../ft_ssl .
rm -Rf error_test
while :
do
	clear
	echo " ------------------------------------------"
	echo "| 1.md5 2.sha224 3.sha256 4.sha384 |\n
		  | 5.sha512 6.all 0.Exit . |" | column -t
	echo " ------------------------------------------"
	read INPUT
	case $INPUT in
					1)
						md5_fun;;
					2)
						sha224_fun;;
					3)
						sha256_fun;;
					4)
						sha384_fun;;
					5)
						sha512_fun;;
					6)
						md5_fun
						#clear
						sha224_fun
						sha256_fun
						sha384_fun
						sha512_fun;;
					0)
						break ;
	esac
done
clear

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 12:53:43 by lruiz-es          #+#    #+#              #
#    Updated: 2024/02/24 14:29:20 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sh ./test.sh
#Coment when finished
DEBUG=
cd ./test_input_files
#test from console
#for f in *;
#do
#	cat $f | ../a.out > ../user_output/${f%.*}.output
#	echo "Test for the input file" $f "coming from std input fd0"
#	echo
#	diff ../test_output_files/${f%.*}.output ../user_output/${f%.*}.output
#	read -n 1 -s
#done
for f in *;
do
	../a.out $f > ../user_output/${f%.*}.out;
	hexdump ../user_output/${f%.*}.out > ../user_output/${f%.*}.dump;
	echo "Test for the input file:  ./test_input_files/"$f;
#	hexdump $f > ../test_output_files/${f%.*}.dump
	echo;
	read -n 1 -s;
	diff ../test_output_files/${f%.*}.dump ../user_output/${f%.*}.dump; 
done
echo *********************************************************************
echo ************PRUEBA DE LEAKS*****************************************
echo *****************************************************************
for f in *;
do	
	leaks --atExit -- ../a.out $f;
	echo;
	read -n 1 -s;
done;

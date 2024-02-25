# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 12:53:43 by lruiz-es          #+#    #+#              #
#    Updated: 2024/02/25 15:46:35 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sh ./test.sh
#Coment when finished
DEBUG=
#test from console

for s in BUFFER_SIZE=1 BUFFER_SIZE=2 BUFFER_SIZE=3 BUFFER_SIZE=4 BUFFER_SIZE=10 BUFFER_SIZE=20 BUFFER_SIZE=15 BUFFER_SIZE=30 BUFFER_SIZE=42 BUFFER_SIZE=4096
	do
		echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOK
		echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		echo $s $s $s $s $s $s $s $s $s $s $s $s $s
		echo OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		cc -Wall -Werror -Wextra -D $s *.c *.h
		echo Standard Input;
		cd ./test_input_files
		for f in *;
			do
				cat $f | ../a.out > ../user_output/${f%.*}.out;
				echo "Test for the input file" $f "coming from std input fd0";
				echo;
			hexdump ../user_output/${f%.*}.out > ../user_output/${f%.*}.output;
			diff ../test_output_files/${f%.*}.dump ../user_output/${f%.*}.output;

			done;
		echo Input From Files;
		for f in *;
			do
				../a.out $f > ../user_output/${f%.*}.out;
		    hexdump ../user_output/${f%.*}.out > ../user_output/${f%.*}.output;
				echo "Test for the input file:  ./test_input_files/" $f;
	
			diff ../test_output_files/${f%.*}.dump ../user_output/${f%.*}.output; 

			
			echo ************************************************************;
			echo ************PRUEBA DE LEAKS*********************************;
			echo ************************************************************;
			leaks --atExit -- ../a.out $f;
		

			done;
	cd ..
	done;

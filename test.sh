# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lruiz-es <lruiz-es@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 12:53:43 by lruiz-es          #+#    #+#              #
#    Updated: 2024/02/17 14:13:56 by lruiz-es         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sh ./test.sh
cd ./test_input_files
for f in *;
do
	../a.out $f > ../user_output/${f%.*}.output;
	echo "Test for the input file:  ./test_input_files/"$f;
	echo
	diff ../test_output_files/${f%.*}.output ../user_output/${f%.*}.output
done


 c=0
 while test $c != 6
 do
 
 	echo -e "\n1)Create \n2)View \n3)Insert \n4)Delete \n5)Modify \n6)Exit"
 	echo "Enter your Choice"
 	read c
 	
 	case $c in 
 	
 	1)
 	echo "Enter the File name"
 	read filename
 	touch $filename
 	echo -e "RollNo \t\t Name \t\t Phone Number \t\t Email Address \t\t" >> $filename
 	echo "File created successfully"
        ;;
 	
 	2)
 	echo "Enter the File name"
 	read filename
 	cat "$filename"
 	;;
 	
 	3)
 	echo "Enter the File name"
 	read filename
 	
 	echo "Enter the Roll no"
 	read roll
 	
 	echo "Enter the Name"
 	read name
 	pat="^[A-Za-z]"
 	
 	while [[ ! $name =~ $pat ]]
 	do
 		echo "Enter a valid name"
 		read name
 	done
 	
 	echo "Enter the Phone Number"
 	read phone
 	pat="^[0-9]{10}"
 	
 	while [[ ! $phone =~ $pat ]]
 	do
 		echo "Enter a valid Phone no"
 		read phone
 	done
 	
 	echo "Enter the Email Address"
 	read mail
 	pat="^([a-z0-9_%-+.]+@[a-z]+\.[a-z]{2,4})$"
 	
 	while [[ ! $mail =~ $pat ]]
 	do
 		echo "Enter a valid Email address"
 		read mail
 	done
 	
 	echo -e "$roll \t\t $name \t\t $phone  \t\t\t $mail \t\t\t" >> $filename 
 	echo "Record Inserted  successfully"
 	;;
 	
 	4)
 	echo "Enter the File name"
 	read filename
 	
 	echo "Enter the Roll no of record you want to delete"
 	read roll
 	sed -i "/$roll/d" $filename
 	;;
 	
 	5)
 	echo "Enter the File name"
 	read filename
 	
 	echo "Enter the name you want to modify"
 	read oldname
 	echo "Enter the new name after mofification"
 	read newname
 	sed -i "s/$oldname/$newname/" $filename
 	;;
 	
 	6)
 	echo "Successfully Exitted"
 	exit
 	;;
 	esac
 done
 exit

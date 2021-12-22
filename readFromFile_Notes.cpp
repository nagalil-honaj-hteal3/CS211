#In this section, you are to be introduced how to use a file in C++.
#The following example will show how to open up a file using a string.
#EX:   
      string fileName;
      cout << "Enter the file name you wish to enter: ";//output statement
      cin >> fileName;//the string that the compiler will read from the input
      fin.open(fileName.c_str());//this is to convert the string into a C string
      #OR
      fin.open(fileName.data())
#The following example will explain how to read data from an input file -- format 
      while(fin)//fin is the file input
      {
        //...example will be shown below 
      }
#EX:
#Input File 
      #Mike 25
      #Kathy 20
      #David 30
#.cpp file
      int total = 0;
      string name;
      int age;

      fin >> name >> age;//follows the format that is in the Input File
      while(fin)
      {
        total += age;//sets the total to the age of the first person and adds up with the other person
        fin >> name >> age;
      }
      cout << "The total age is " << total << endl;

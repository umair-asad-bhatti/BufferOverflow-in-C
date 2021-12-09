
//This program will demonstarate how buffer overflow occurs and how we can avoid buffer overflow
//Hackers can exploit the buffer overflow flaw in code to gain remote access(Remote code execution) to a machine
//so we should take care of these things while coding

//lets include the basic header files to get it working
#include <stdio.h>
#include <stdlib.h>
//main function
int main(int argc, char const *argv[])
{

    //lets declare the buffer
    char buff[6]; //this is limited to 6 characters including null character
    int pass = 0; //as pass is 0 so condition with wrong password should be met
    //as i am not changing the value of pass explicitly in code
    puts("Enter the password"); //prmpting
    //gets does not limit the buffer size and it will override the memory next to it if
    //string has length way more than the buffer size
    gets(buff); //getting user input in buffer

    //if we provide value like umair it will print wrong pass
    //but i provide the long string like "hhhhhhtttthththththt"
    //this will override the memory block of pass var and
    //and print correct

    //if we use fgets we can specify the string size to be put in buffer
    //In this way we can avoid the buffer overflow condition
    // fgets(buff,6,stdin);
    puts(buff); //printing the buffer for sake of unserstanding

    //conditional statements
    if (pass)
        puts("correct password");

    else
        puts("Wrong password");

    //pause the console before exiting the program
    system("pause");
    return 0;//return to OS from main function
}

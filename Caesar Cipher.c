#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I made this program for my final project in the first year of software engineering
// Change the two file location to wherever you want in marked lines
// Password of the encoded text is biggest divider prime factor of student number

void encodedFile(const char *text){                                                                             // To write encoded text to file
FILE *fp;
fp = fopen("/home/encodedtext.txt","w");                                               // <----  File location 1
fputs(text,fp);
fclose(fp);
}

int passwordConfirmation(int number){                                                                        // To find the biggest divider prime factor of student number
int primeNumber;
int i=0;
division:
for(int multiplier=2;multiplier<=number;multiplier++){
    if(number%multiplier==0){
        number=number/multiplier;
        if(number!=1){
        primeNumber=number;
        i++;
        }
    else{
        goto division;
    }
    }
}
return primeNumber;
}

void fileRead(){                                                                                                     // To read encoded text from file
FILE *fp;
char character[100][100];
int dimension[302];
int i;
printf("#####################\nEncoded text : ");
fp = fopen("/home/encodedtext.txt","r");                                                   // <----  File location 2
while(!feof(fp)){
    fscanf(fp,"%s",*character);
    printf("%s ",*character);
    i++;
}
fclose(fp);
}

const char* encryption(char studentInformation[]){                                                             // To encode the text
    for(int i=0;i<strlen(studentInformation);i++){
        if(studentInformation[i] == ' '){
        }
        else if (studentInformation[i] == 'z'){
            studentInformation[i] = 'f';
        }
        else{
                studentInformation[i] += 6;
                if(studentInformation[i]>=123 || 91<= studentInformation[i] && studentInformation[i] <= 96){
                    studentInformation[i] -=26;
                }
        }
    }
return studentInformation;
}

const char* decryption(char studentInformation[]){                                //To decode the text
    for(int i=0;i<strlen(studentInformation);i++){
        if(studentInformation[i] == ' '){
        }
        else{
            studentInformation[i] -= 6;
            if(91<=studentInformation[i] && studentInformation[i] <97 || 58<=studentInformation[i] && studentInformation[i]<=64){
                studentInformation[i] +=26;
            }
        }
    }
return studentInformation;
}

struct informations{
char name[150];
char surname[150];
int number;
int password;
}student1;

int main(){
char text[302];
printf("Please enter your student name   : ");
gets(student1.name);
printf("Please enter your student surname: ");
gets(student1.surname);
strcat(text,student1.name);
strcat(text," ");
strcat(text,student1.surname);
char *ptext[] = {text};
printf("What is your student number? ");
scanf("%d",&student1.number);
encodedFile(encryption(*ptext));
passwordQuery:
printf("What is the biggest prime factor of your student number? ");
scanf("%d",&student1.password);
    if(student1.password == passwordConfirmation(student1.number)){
        fileRead();
        printf("\nDecoded text : %s\n",decryption(*ptext));
    }
    else{
        printf("\nYou entered an incorrect password.");
        goto passwordQuery;
    }
    return 0;
}

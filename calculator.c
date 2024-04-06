#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <unistd.h>
#include <math.h>
//simple calculator with 5 operator: + - x / %
void func(char * so1,  char operato, char* so2);
void writef(double num) ;
double readf();
int int_readf();
void clear_input_buffer();
int main() {
    printf(">> ");
    char meow1[10];
    char meow2[10];
    char op;
     scanf(" %s", meow1);
if(strcmp(meow1, "EXIT") == 0){
    return 0;
}
   scanf(" %c",&op);
    scanf(" %s", meow2);
func(meow1,op,meow2);


while(1){
getch();
printf("\033[H\033[J");
printf(">> ");
    char so1[10];
    char so2[10];
    char operato;
  scanf(" %s", so1);
if(strcmp(so1, "EXIT") == 0){
    break;
}
   scanf(" %c",&operato);
    scanf(" %s", so2);

func(so1,operato,so2);
}

    return 0;
}
void writef(double num) {
    FILE *file = fopen("meow.txt", "w");

    fprintf(file, "%f", num);
    
    fclose(file);
}
double readf() {
    double num = 0;  
    FILE *file = fopen("meow.txt", "a+"); 
    fseek(file, 0, SEEK_END);
    if(ftell(file) == 0) {
        fprintf(file, "%f", num);  
    } else {
        rewind(file); 
        fscanf(file, "%lf", &num);  
    }

    fclose(file);
    return num;
}


void clear_input_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
void func(char* so1,  char operato, char* so2) {
    double num1,num2;
    int decimalCount = 0;
     int negativeSignCount = 0;

for(int i = 0; i < strlen(so1); i++) {
	if(strcmp(so1, "ANS") == 0){//are identical
	break;
	}
	if(so1[i] == '.') {
		decimalCount++;
       		if(decimalCount > 1) {
        		printf("SYNTAX ERROR");
        		return;
        		break;
       		}
        } 
	else if(so1[i] == '-') {
		if(strlen(so1)==1){
		
			printf("SYNTAX ERROR");
			return;
			break;
		}
		negativeSignCount++;
		if(negativeSignCount > 1 || (negativeSignCount == 1 && i != 0)) {
			printf("SYNTAX ERROR");
			return;
			break;
		}
	}
	else if(!isdigit(so1[i])) {
		printf("SYNTAX ERROR");                          
		return;
		break;
	}
	
	if(strlen(so1)<1){
	printf("SYNTAX ERROR");
			return;
			break;
	}
}
	if(strcmp(so1, "ANS") == 0)
	num1=readf();
	else
	num1 = atof(so1);
        
decimalCount = 0;
negativeSignCount=0;
for(int i = 0; i < strlen(so2); i++) {
	if(strcmp(so2, "ANS") == 0){
	break;
	}
	if(so2[i] == '.') {
		decimalCount++;
        if(decimalCount > 1) {
        	printf("SYNTAX ERROR");
        	return;
        	break;
        }
        } 
	else if(so2[i] == '-') {
		if(strlen(so2)==1){
			printf("SYNTAX ERROR");
			return;
			break;
		}
		negativeSignCount++;
		if(negativeSignCount > 1 || (negativeSignCount == 1 && i != 0)) {
			printf("SYNTAX ERROR");
			return;
			break;
		}
	}
	else if(!isdigit(so2[i])) {
		printf("SYNTAX ERROR");                          
		return;
		break;
	}
		

}
	if(strcmp(so2, "ANS") == 0)
	num2=readf();
	else
	num2 = atof(so2);
        
    

switch (operato) { 
        case '+':
           if (num1 + num2 == (int)(num1 + num2))
                printf("%d", (int)(num1 + num2));               
            else
                printf("%.2lf", num1 + num2);
            writef((double)(num1 + num2));
            break;
        case '-':
           if (num1 - num2 == (int)(num1 - num2))
                printf("%d", (int)(num1 - num2));
            else
                printf("%.2lf", num1 - num2);
            writef((double)(num1 - num2));
            break;
        case 'x':
           if (num1 * num2 == (int)(num1 * num2))
                printf("%d", (int)(num1 * num2));
            else
                printf("%.2lf", num1 * num2);
            writef((double)(num1 * num2));
            break;
        case '/':
            if (num2 != 0) {
               if (num1 / num2 == (int)(num1 / num2))
                printf("%d", (int)(num1 / num2));
               else
                printf("%.2lf", num1 / num2);
               writef((double)(num1 / num2));
               break;
            } else {
                printf("MATH ERROR");
            }
            break;
        case '%':
            if (num2 != 0) {
                double result = fmod(num1, num2);

    if (result < 0) {
                result = result*(-1);
    }
           if (result == (int)(result))
                printf("%d", (int)(result));
            else
                printf("%.2lf", result);
            writef((double)(result));
            break;
             }else {
                printf("MATH ERROR");
            
            break;}
        default:
            printf("SYNTAX ERROR");
    }
    }






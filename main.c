#include<stdio.h>

#ifndef OPERATOR
#define OPERATOR -
#endif

int isLetter(char letter){
	return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');

}
int isLower(char letter){
	return (letter >= 'a' && letter <= 'z');

}
int isUpper(char letter){
	return (letter >= 'A' && letter <= 'Z');

}
int modulo(int a, int b) {
  const int result = a % b;
  return result >= 0 ? result : result + b;
}

void shift(char* text, char* key){
	for(int i = 0, j = 0; text[i] != '\0'; i++){
		if(key[j] == '\0'){
			j = 0;
		}
		if(!isLetter(text[i])){
			continue;
		}
		text[i] = modulo(text[i]-isLower(text[i])*'a'-isUpper(text[i])*'A' OPERATOR isLetter(text[i])*(key[j]+isLower(key[j])*'a'+isUpper(key[j])*'A'), 26) + isLower(text[i])*'a'+isUpper(text[i])*'A';
		j++;
	}

}

int main(int argc, char *argv[]){
	shift(argv[1], argv[2]);
	puts(argv[1]);
}

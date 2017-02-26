// Sukwhan Youn


#include <stdio.h>
int readline(int *p1, int aNumber);
int* findmatch(int *p1, int *p2, int number1, int number2);
void printmessage(int *position, int *text, int patternlen, int textlen );

int patternStart = 0;
int indexT=0;		// index for Text
int indexp=0;		// index for pattern

int main() {
   int text[40], pattern[40], *position;
   int textlen, patternlen;


   printf("Enter text: ");
   textlen = readline(text, 40);
   printf("Enter pattern: ");
   patternlen = readline(pattern, 40);
   position = findmatch(pattern, text, patternlen, textlen);
   printmessage(position, text, patternlen, textlen);
}

int readline(int *p1, int aNumber){
	int c=getchar();
	int i=0;
	while (c != '\n' && c!='\0' && c!=32 && i<aNumber ){
		*p1 = c;
		p1++;
		i++;
		c=getchar();
	}
	return i;
}

int* findmatch(int *pattern, int *text, int patternlen, int textlen){ 
	while (indexp<patternlen){
		if (indexT==textlen){
			return NULL;
			break;
		}
		else if (*(pattern+indexp)=='?' || *(pattern+indexp) == *(text+indexT)){
			indexp++;
			indexT++;
		}
		else{
			indexp=0;
			patternStart++;
			indexT=patternStart;
		}
	}
	return (text + patternStart);
}
void printmessage(int *position, int *text, int patternlen, int textlen ){
	if (indexp==patternlen){
		printf("The pattern was found at char %d. The remaining text chars are: " ,patternStart+1 );
		int z = patternlen;
		for (z; z < textlen-patternStart; z++){
			printf("%c",*(position+z));

		}
		printf("\n");
	}
	else if (position==NULL){
		printf("no match\n");
  }
	else{
		printf("NO MATCH");
	}
}







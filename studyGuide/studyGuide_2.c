#include <stdlib.h>
#include <stdio.h>



/*
A string is being returned when the pointer match is found.
*/
char* doStuff(char s[], char c)
{
	char* p = s;
	while(*p != '\0')
	{
		if(*p == c)
		{
			return p;
		}
		p++;
	}
	return NULL;
}


/*
so the buffer stores 1 character at a time so it will recurse one at a time
*/

void mysteryC()
{
	char c;
	scanf(" %c", &c);

	if(c != '%')
	{
		printf("%c.", c);
		mysteryC();
	}
}


int main(void)
{
	// char message[81];
	// scanf("%s", message); // Do not use & here since you are dealing with pointers, and not the whole string.
	// printf("%s", message);
	// printf("\n");



	/*
	`scanf` will read the first word up until the first whitespace.
    Here, "Flames" will be taken from the input buffer and stored in `message`.
    The rest of the input (" in 2024\n") will remain in the buffer.
    `fgets` will then read the remaining characters from the buffer and overwrite `message` with " in 2024\n",
    thus replacing the previous content ("Flames") in `message`.
	*/
	// char message[81];
	// scanf("%s", message);
	// fgets(message, 81, stdin); // Name of the character array, The supposed size, And where to get this line from?
	// printf("%s", message);


	/*
	String scan formatted and string print formatted.
	sscanf takes in letters and reads the three words and then stores them in each variable.
	Strcat adds over to the variable called two
	sprintf takes the content of the three variables and then formats them as a single string and stores it in 4.

	*/
	// char letters[] = "moon is sun"; // String 
	// char one[81];
	// char two[81];
	// char three[81];
	// char four[250];

	// sscanf(letters, "%s %s %s", one, two, three);
	// strcat(two, " over");
	// sprintf(four, "%s %s %s", one, two, three);
	// printf("%s", four);

	// Ps is pointing to the first element in the string.
	// When you increment the pointer, the head of the string will be the next element.
	// char s[] = "fedcba";
	// char* ps = s;
	// ps += 1;
	// printf("%s", ps);
	// printf("\n");


	// printf("%s", doStuff("protest", 't'));

	mysteryC();

}


#include <stdio.h>

int main(void)
{
	FILE * infile;
	FILE * outfile;

	int age;
	char name[20];

	infile = fopen("myfile.txt", "r");
	outfile = fopen("dupfile.dat", "w");

	if(infile == NULL)
		puts("File not found");
	else
		puts("File found and program executed");

	while(fscanf(infile, "%s%d", name, &age) != EOF)
	{
		fprintf(outfile, "%s\t%d\n", name, age);
	}

	fclose(infile);
	fclose(outfile);

	return(0);
}//end main function

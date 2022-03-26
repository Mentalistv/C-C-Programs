#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <fstream.h>

int mod(int a, int b)
{
    int r = a % b;

    return r < 0 ? r + b : r;
}


bool leap_year(int year){

	if (year % 400 == 0) {
      	return true;
	}	

	else if (year % 100 == 0) {
		return false;
	}

	else if (year % 4 == 0) {
		return true;
	}

	else {
		return false;
	}

}


void display_calender (int month, int year, FILE *fp)
{
	int h, q, m, k, j, g, v, f, l, u;
	
	k=year%100; j=floor(year/100);
	
	int monthl [16]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
	
	fprintf(fp,"Month: %d  ", month);
	fprintf(fp, "Year: %d\n", year); 
	
	m=month;

	if (month==1) m=13;

	else if (month==2) m=14;

	if(leap_year){
		monthl[2]=29;
	}

	fprintf(fp,"sun\tmon\ttue\twed\tthu\tfri\tsat\n\n");

	for(q=1; q<=monthl[month]; q++)
	{	
		g = floor(13*(m+1)/5);
		v = floor(k/4);
		f = floor(j/4);
		l = (q + g + k + v + f - 2*j);
		
		h = mod(l,7);

		if(q==1&&h==0) fprintf(fp,"\t\t\t\t\t");
		if(q==1&&h==3) fprintf(fp,"\t");
		if(q==1&&h==4) fprintf(fp,"\t\t");
		if(q==1&&h==5) fprintf(fp,"\t\t\t");
		if(q==1&&h==6) fprintf(fp,"\t\t\t\t");
		
		if (h==0) fprintf(fp,"\t%d\n\n",q);
		if (h==1) fprintf(fp,"%d",q);
		if (h==2) fprintf(fp,"\t%d",q);
		if (h==3) fprintf(fp,"\t%d",q);
		if (h==4) fprintf(fp,"\t%d",q);
		if (h==5) fprintf(fp,"\t%d",q);
		if (h==6) fprintf(fp,"\t%d",q);
			
	}

	if(leap_year){
		monthl[2]=28;
	}
	
	fprintf(fp,"\n");
}	

int main()
{	int month, year;
	char cmd;

	system("clear");

	printf("enter the month (MM) and year (YYYY)");
	scanf("%d %d", &month, &year);
	
	display_calender(month, year, stdout);

	printf("Press: \n");
	printf("1. Left arrow key - go to the previous month \n");
	printf("2. Right arrow key - go to the next month \n");
	printf("3. Up arrow key - go to the next year \n");
	printf("4. Down arrow key - go to the previous year \n");
	printf("5. I - inesrt new month year \n");
	printf("6. P - print the month in a text file \n");
	printf("7. - exit the program\n"); 

	while(1)
	{	
		char c,d;

		c = getchar();
		scanf("%c", &cmd);

		switch(cmd)
		{
			case '\033':
				getchar();
				d = getchar();

				switch(d){
					case 'A': year++;
						    display_calender (month, year, stdout);
							break;

					case 'B': year--;
						    display_calender(month, year, stdout); 	  	
						    break;

					case 'C': if(month==12) {
								month=1; 
								year++;
							}
							else month++;
							display_calender(month, year, stdout);
							break;
							
					case 'D': if(month==1) {
								month=12; 
								year--;
							}
							else month--;
							display_calender(month, year, stdout);
							break;

					default: exit(0);		//esc
				}
				printf("\n");
				break;

			case 'I': system("clear");

					printf("enter the month (MM) and year (YYYY)");
					scanf("%d %d", &month, &year);
					display_calender(month, year, stdout);

					printf("Press: \n");
					printf("1. Left arrow key - go to the previous month \n");
					printf("2. Right arrow key - go to the next month \n");
					printf("3. Up arrow key - go to the next year \n");
					printf("4. Down arrow key - go to the previous year \n");
					printf("5. I - inesrt new month year \n");
					printf("6. P - print the month in a text file \n");
					printf("7. - exit the program\n"); 
					break;

			case 'P': FILE *fp;
					fp = fopen("output.txt", "w");

					if ( fp == NULL ) 
				    { 
				        printf( "Failed to open file." ) ; 
				    }  

				    else{
				    	printf("enter the month (MM) and year (YYYY)");
						scanf("%d %d", &month, &year);
				    	display_calender(month, year, fp);
						
				    	fclose(fp);

				    	printf("Press: \n");
						printf("1. Left arrow key - go to the previous month \n");
						printf("2. Right arrow key - go to the next month \n");
						printf("3. Up arrow key - go to the next year \n");
						printf("4. Down arrow key - go to the previous year \n");
						printf("5. I - inesrt new month year \n");
						printf("6. P - print the month in a text file \n");
						printf("7. - exit the program\n"); 

				    }

					break;

		}

	}

	return 0;

}
	

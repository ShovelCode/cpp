//Christopher Ray
//UID 900 192 325
//COSC 2420 C Programming
//Airplane seating program from page 270 of the book

#include <stdio.h>

#define SIZE 10


int main(void)
{
	int seats[10] = {0}; //represents 10 seats, 0 is empty, 1 is filled
	int i = 0; //loop control
	int option = 0; //1 is first class, 2 is economy, all else ends the program
	int willingness = 0; //1 means yes, 2 means no
	int seatNumber = 0; //Changes for the ticket
	int flightType = 0; //1 means first class, 2 means economy
	
	for(;;) //when prompted for First Class or Economy, enter anything but 1 or 2 to break out and end the program
	{
		puts("\nFirst class or economy (1 or 2)");
		scanf("%d", &option);
		
		if(option == 1)
		{
			if(seats[0] == 0)
			{
				seats[0] = 1;
				flightType = 1;
				seatNumber = 1;
			}
			else if(seats[1] == 0)
			{
				seats[1] = 1;
				flightType = 1;
				seatNumber = 2;
			}
			else if(seats[2] == 0)
			{
				seats[2] = 1;
				flightType = 1;
				seatNumber = 3;
			}
			else if(seats[3] == 0)
			{
				seats[3] = 1;
				flightType = 1;
				seatNumber = 4;
			}
			else if(seats[4] == 0)
			{
				seats[4] = 1;
				flightType = 1;
				seatNumber = 5;
			}
			else
			{
				printf("%s", "First class is full, is economy ok?(1 for yes, 2 for no)");
				scanf("%d",&willingness);
				if(willingness == 1)
				{
					if(seats[5] == 0)
					{
						seats[5] = 1;
						flightType = 2;
						seatNumber = 6;
					}
					else if(seats[6] == 0)
					{
						seats[6] = 1;
						flightType = 2;
						seatNumber = 7;
					}
					else if(seats[7] == 0)
					{
						seats[7] = 1;
						flightType = 2;
						seatNumber = 8;
					}
					else if(seats[8] == 0)
					{
						seats[8] = 1;
						flightType = 2;
						seatNumber = 9;
					}
					else if(seats[9] == 0)
					{
						seats[9] = 1;
						flightType = 2;
						seatNumber = 10;
					}
					else
						{
							printf("\n%s\n\n", "Plane full");
							return 0;
						}//end else
				}//end if
				else
				{
					printf("%s\n", "Next flight is in three hours");
					continue;
				}
			}//end else
				
				
		}//end if
		
		if(option == 2)
		{
			if(seats[5] == 0)
			{
				seats[5] = 1;
				flightType = 2;
				seatNumber = 6;
			}
			else if(seats[6] == 0)
			{
				seats[6] = 1;
				flightType = 2;
				seatNumber = 7;
			}
			else if(seats[7] == 0)
			{
				seats[7] = 1;
				flightType = 2;
				seatNumber = 8;
			}
			else if(seats[8] == 0)
			{
				seats[8] = 1;
				flightType = 2;
				seatNumber = 9;
			}
			else if(seats[9] == 0)
			{
				seats[9] = 1;
				flightType = 2;
				seatNumber = 10;
			}
			else
			{
				printf("%s", "Economy is full, how about First Class?(1 for yes, 2 for no)");
				scanf("%d",&willingness);
				if(willingness == 1)
				{
					if(seats[0] == 0)
					{
						seats[0] = 1;
						flightType = 1;
						seatNumber = 1;
					}
					else if(seats[1] == 0)
					{
						seats[1] = 1;
						flightType = 1;
						seatNumber = 2;
					}
					else if(seats[2] == 0)
					{
						seats[2] = 1;
						flightType = 1;
						seatNumber = 3;
					}
					else if(seats[3] == 0)
					{
						seats[3] = 1;
						flightType = 1;
						seatNumber = 4;
					}
					else if(seats[4] == 0)
					{
						seats[4] = 1;
						flightType = 1;
						seatNumber = 5;
					}
					else
						{
							printf("\n%s\n\n", "Plane full");
							return 0;
						}//end else
				}
				else
				{
					printf("%s\n", "Next flight is in three hours");
					continue;
				}
			}//end else
			
		}//end if
		
		if(option < 1 || option > 2)
			break;
			
		if(flightType == 1)
		{
			printf("First Class - Seat Number %d", seatNumber);
		}//end if
		else if(flightType == 2)
		{
			printf("Economy - Seat Number %d", seatNumber);
		}//end else
		
	}//end for
	
	return 0;
}//end main function

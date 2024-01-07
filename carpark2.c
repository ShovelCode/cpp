#include <stdio.h>
#include <math.h>

float calculateCharges(float);

int main()
{
    float hoursParked1 = 0.0;
    float hoursParked2 = 0.0;
    float hoursParked3 = 0.0;
    
    float charges1     = 0.0;
    float charges2     = 0.0;
    float charges3     = 0.0;
    
    float totalHours   = 0.0;
    float totalCharge  = 0.0;
    
    printf("Enter the hours parked for 3 cars: ");
    
    scanf("%f%f%f", &hoursParked1, &hoursParked2, &hoursParked3);
    
    charges1 = calculateCharges( hoursParked1 );
    charges2 = calculateCharges( hoursParked2 );
    charges3 = calculateCharges( hoursParked3 );
    
    totalHours = hoursParked1 + hoursParked2 + hoursParked3;
    totalCharge = charges1 + charges2 + charges3;
    
    puts("Car     Hours     Charge");
    printf("1      %4.1f     %4.2f\n", hoursParked1, charges1 );
    printf("2      %4.1f     %4.2f\n", hoursParked2, charges2 );
    printf("3      %4.1f     %4.2f\n", hoursParked3, charges3 );
    printf("Total     %4.2f    %5.2f\n", totalHours, totalCharge );
    

    return 0;
} //end function main

float calculateCharges( float hours){
    float charge = 0.0;
    
    if( hours <= 2.0)
        return 2.0;
    
    charge = 2.00 + (ceil(hours) - 3.0 ) * 0.50;
    
    if( charge > 10.00 )
         charge = 10.00;
         
    return charge;
}//end function calculateCharges

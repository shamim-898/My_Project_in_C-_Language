#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variable Declarations
    int passengerID;
    int busSelection;
    int ticketQuantity;
    int ticketFare = 0;
    int totalFare = 0;
    float discountAmount = 0.0;
    float finalFareAmount = 0.0;
    int menuChoice;

    // Virtual Database Variables for Ticket Print
    char routeName[50];
    char departureTime[20];
    int seatStartNumber = 12; // Dynamic starting seat number

    // Infinite Loop to keep the Bus Counter running continuously
    while(1)
    {
        // Welcome Screen Display Matrix
        printf("\n=============================================\n");
        printf("       WELCOME TO BUS COUNTER SYSTEM        \n");
        printf("=============================================\n");
        printf("1. Book a New Bus Ticket\n");
        printf("2. Exit the System Application\n");
        printf("---------------------------------------------\n");
        printf("Enter your choice (1-2): ");
        scanf("%d", &menuChoice);

        // System Control Flow based on Main Menu Choice
        if(menuChoice == 2)
        {
            printf("\nExiting System... Thank you for using our service!\n");
            break; // Breaks the infinite loop and terminates program
        }
        else if(menuChoice != 1)
        {
            printf("\n[ERROR] Invalid Menu Choice! Please try again.\n");
            continue; // Restarts the loop from beginning
        }

        // Section 1: Passenger Registration Module
        printf("\n>>> PASSENGER REGISTRATION <<<\n");
        printf("Enter Unique Passenger ID: ");
        scanf("%d", &passengerID);

        // Section 2: Dynamic Route and Schedule Menu Display
        printf("\n---------------------------------------------\n");
        printf("              AVAILABLE BUS ROUTES           \n");
        printf("---------------------------------------------\n");
        printf("1. Dhaka      | Fare: 500 Tk | Time: 08:30 AM\n");
        printf("2. Chittagong | Fare: 650 Tk | Time: 11:15 AM\n");
        printf("3. Sylhet     | Fare: 550 Tk | Time: 02:45 PM\n");
        printf("4. Rajshahi   | Fare: 600 Tk | Time: 09:00 PM\n");
        printf("---------------------------------------------\n");

        printf("Select Destination Bus Number (1-4): ");
        scanf("%d", &busSelection);

        // Section 3: Data Mapping and Validation Logic
        if(busSelection == 1)
        {
            ticketFare = 500;
            sprintf(routeName, "Dhaka");
            sprintf(departureTime, "08:30 AM");
        }
        else if(busSelection == 2)
        {
            ticketFare = 650;
            sprintf(routeName, "Chittagong");
            sprintf(departureTime, "11:15 AM");
        }
        else if(busSelection == 3)
        {
            ticketFare = 550;
            sprintf(routeName, "Sylhet");
            sprintf(departureTime, "02:45 PM");
        }
        else if(busSelection == 4)
        {
            ticketFare = 600;
            sprintf(routeName, "Rajshahi");
            sprintf(departureTime, "09:00 PM");
        }
        else
        {
            // Error Boundary Handling
            printf("\n[ERROR] Invalid Bus Selection! Ticket booking failed.\n");
            printf("Returning to main control screen...\n");
            continue;
        }

        // Section 4: Ticket Quantity Input and Calculation
        printf("Enter Total Number of Tickets to Purchase: ");
        scanf("%d", &ticketQuantity);

        // Validate if ticket quantity is valid
        if(ticketQuantity <= 0)
        {
            printf("\n[ERROR] Ticket quantity must be at least 1!\n");
            continue;
        }

        // Basic Fare Calculation
        totalFare = ticketFare * ticketQuantity;

        // Section 5: Commercial Group Discount Policy
        // If a passenger buys 3 or more tickets, they receive a 10% flat discount
        if(ticketQuantity >= 3)
        {
            discountAmount = totalFare * 0.10;
            printf("\n[PROMO] 10%% Bulk Purchase Discount Applied successfully!");
        }
        else
        {
            discountAmount = 0.0;
        }

        // Net Payable Amount Calculation
        finalFareAmount = totalFare - discountAmount;

        // Section 6: Official Invoice / Memo Generation Module
        printf("\n\n=============================================\n");
        printf("           OFFICIAL TRAVEL TICKET            \n");
        printf("=============================================\n");
        printf(" Passenger ID   : %d\n", passengerID);
        printf(" Destination    : %s\n", routeName);
        printf(" Departure Time : %s\n", departureTime);
        printf(" Allocated Seats: B%d to B%d\n", seatStartNumber, seatStartNumber + ticketQuantity - 1);
        printf("---------------------------------------------\n");
        printf(" Single Fare    : %d Tk\n", ticketFare);
        printf(" Total Quantity : %d\n", ticketQuantity);
        printf(" Sub-Total Fare : %d Tk\n", totalFare);
        printf(" Promo Discount : %.2f Tk\n", discountAmount);
        printf("---------------------------------------------\n");
        printf(" NET PAYABLE    : %.2f Tk\n", finalFareAmount);
        printf("=============================================\n");
        printf(" STATUS         : BOOKING SUCCESSFUL\n");
        printf("=============================================\n\n");

        // Simulating sequence shift for the next booking cycle
        seatStartNumber += ticketQuantity;
    }
    return 0;
}

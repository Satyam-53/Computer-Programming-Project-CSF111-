#######################################################################################################################################################################################
ReadMe for assignment submitted by 2019B1PS0188P
Practical section number: P8
Asignment question attempted: 6 (Railway Reservation System for Migrant Labourers)
#######################################################################################################################################################################################

Team:
1. 2019B1PS0188P   SATYAM SRIVASTAVA
2. 2019B1PS0986P   LATIKA NARVEKAR
3. 2019B1PS1035P   MANAN MANGAL

#######################################################################################################################################################################################

TO RUN THE PROGRAM:
-Switch over to the directory where the source code file is present.
-The entire code is stored in the .c file "2019B1PS0188P_P8.c".
-To compile the code using gcc compiler, use the command "gcc -o 2019B1PS0188P_P8 2019B1PS0188P_P8.c" in terminal/compiler.
-To run the program after compiling the code, use the command ".\2019B1PS0188P_P8". Please make sure that you do not change the directory
 throughout the process of compiling and running the code.

INSTRUCTIONS AND GENERAL INFORMATION:

1) Kindly run the program on FULL-SCREEN MODE.

2) Once you compile and run the code on gcc complier, a Menu-screen with five options will open up. They are:
   <1>View all Train Details
   <2>Book a Ticket
   <3>Cancel a Booking
   <4>Enquiry
   <5>View Ticket Details
You have to enter a number between 1 to 5 to proceed. The program will guide you accordingly. 
   -For Option<1>: You will be able to view tabular data of all the trains along with details like Source, Destination, Charges and Seats 	Left.
   -For Option<2>: You will be prompted to enter your First Name and Last Name separately (WITHOUT any white space), along with Source and 	Destination for the train.
       If that particualr train is available, the program will display the charges and ask for booking confirmation.
       After booking, the number of seats for that particular train will be decremented. The program will also show a confirmation message 	with train and passenger details.
   -For Option<3>: You will be asked to enter the PNR number of the booking you wish to cancel. 50% of the ticket charges will be 		displayed as REFUND amount. 
               That particular PNR entry will be deleted from the Ticket Data file. The seat for that train will also be incremented. 
   -For Option<4>: Program will prompt you to enter Source and Destination name. If that particular train is available, program will 		display the number of seats left and the charges.
   -For Option<5>: The details (PNR, Passenger Name, Source, Destination) of all the tickets booked/cancelled will be displayed.


3) Details of all the tickets booked will be stored in a file by the name "Ticket data-2019B1PS0188P_P8.txt" that will be be created on running the program.

4) Details of all the trains available will be stored in a file by the name "Train details-2019B1PS0188P_P8.txt" that will also be be created on running the program..

5) As mentioned in the question, trains are available only from ONE source, i.e., Delhi.

6) As mentioned in the question, this program has only been made for trains running for ONE DAY.

7) In our program, trains are available ONLY to the following destinations:
-Gorakhpur
-Bhopal
-Patna 
-Varanasi
-Hyderabad
-Bengaluru
-Jaipur
-Lucknow

9) AS MENTIONED IN THE QUESTION, everytime you compile and run the code, PNR Number will AUTOMATICALLY START from 1 (one) and auto-increment after every successful booking.

#######################################################################################################################################################################################

Contributions:
The contributions of all the team members overlapped. We contributed over regularly organised virtual meets (through GMeet).
Every team members inputs were taken into consideration. The implementation of every idea was discussed at length and then executed. 



/*
//////////////////////////////////////////////////////////////////////////////////////			
			RAILWAY RESERVATION SYSTEM FOR MIGRANT LABOURERS
//////////////////////////////////////////////////////////////////////////////////////
*/		

//preprocessor directives used
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//declaration of all the global variables
int pnr=0;	//global variable for pnr
int pnr_arr[10000] = {0};	//pnr array to store pnr information

struct pass_details{	//STRUCTURE DATA TYPE TO STORE PASSENGER DETAILS

char p_fname[100];
char p_lname[100];
char src[100];
char dest[100];

} p1;

struct train_details{	//STRUCTURE DATA TYPE TO STORE TRAIN DETAILS
	int t_number[9];
	int s_left[9];
	int charges[9];
} t1;

//declaration of all the functions used 

void strtoupr(char[]);

//declaration of all the functions related to train and enquiry
void set_train_details();
void set_train_variables();
void enquiry();
void view_all_train_details();
void view_ticket_details();

//declaration of function related to destination
int check_info(char[],char[]);


//declaration of all the functions related to booking
void booking();
void conf_booking(int);


//declaration of all the functions related to cancellation
void cancellation();



int main()
    {
    set_train_variables();

    char choice[100];

    	start:   //label for returning to main menu 
    	set_train_details();
    	
    	system("clear");
    	printf("\t\t\t\t\t\t***********************************\n");	//ticket portal layout
        printf("\t\t\t\t\t\t||                               ||\n");
		printf("\t\t\t\t\t\t||    <<-------------------->>   ||\n");
		printf("\t\t\t\t\t\t||        TICKET RESERVATION     ||\n");
        printf("\t\t\t\t\t\t||             PORTAL            ||\n");
		printf("\t\t\t\t\t\t||    <<-------------------->>   ||\n");
		printf("\t\t\t\t\t\t||                               ||\n");
		printf("\t\t\t\t\t\t||                               ||\n");
    	printf("\t\t\t\t\t\t***********************************\n\n\n\n\n");


		printf("\t\t\t\t\t\t\t__________________________\n");	//available choices
		printf("\t\t\t\t\t\t\t<1> VIEW ALL TRAIN DETAILS\n");
		printf("\t\t\t\t\t\t\t__________________________\n");

		printf("\t\t\t\t\t\t\t__________________________\n");
		printf("\t\t\t\t\t\t\t<2> BOOK A TICKET 	    \n");
		printf("\t\t\t\t\t\t\t__________________________\n");

		printf("\t\t\t\t\t\t\t__________________________\n");
		printf("\t\t\t\t\t\t\t<3> CANCEL A BOOKING      \n");
		printf("\t\t\t\t\t\t\t__________________________\n");

		printf("\t\t\t\t\t\t\t__________________________\n");
		printf("\t\t\t\t\t\t\t<4> ENQUIRY    		    \n");
		printf("\t\t\t\t\t\t\t__________________________\n");

		printf("\t\t\t\t\t\t\t__________________________\n");
		printf("\t\t\t\t\t\t\t<5> VIEW TICKET DETAILS 	\n");
		printf("\t\t\t\t\t\t\t__________________________\n\n\n");


   
        printf("\t\t\t\t\t\t\tSELECT FROM THE ABOVE OPTIONS-->\n");
        scanf("%s", choice);	//input a choice and compares it with the list of listed options
        fflush(stdin);

        if(!strcmp(choice, "1")){
        	view_all_train_details();		
        }
        else if(!strcmp(choice, "2")){
        	booking();
        }
        else if(!strcmp(choice, "3")){
        	cancellation();
        }
        else if(!strcmp(choice, "4")){
        	enquiry();
        }
        else if(!strcmp(choice, "5")){
        	view_ticket_details();
        }


		else{
			printf("INVALID CHOICE, PLEASE MAKE AN APPROPRIATE SELECTION !!!");
			system("clear");
			goto start;
		} 

	char opt[100];
	again:
	printf("\n\n\t\t\t\t\t\tPRESS 0 TO EXIT FROM THE ENTIRE PROGRAM OR 1 TO RETURN TO MAIN WINDOW\t");	//checking to continue the program
	scanf("%s", opt);
	fflush(stdin);
	if(!strcmp(opt,"0")){
	system("clear");
	return 0;
	}
	else if(!strcmp(opt,"1")) goto start;
	else{
		printf("INVALID CHOICE\n\n");
		goto again;
	}
}





void set_train_details(){	//function to set details of all the trains

	FILE *fp_tdetails;
	fp_tdetails =  fopen("Train details-2019B1PS0188_P8","w");

	fprintf (fp_tdetails, "TRAIN NUMBER\t\t SOURCE\t\t DESTINATION 	 \t\t CHARGES \t\t SEATS LEFT\n" );
	fprintf (fp_tdetails, "12568       \t\t DELHI \t\t GORAKHPUR   	 \t\t Rs.%d/- \t\t %d        \n",t1.charges[1], t1.s_left[1]);
	fprintf (fp_tdetails, "12569       \t\t DELHI \t\t BHOPAL    	 \t\t Rs.%d/- \t\t %d        \n",t1.charges[2], t1.s_left[2]);
	fprintf (fp_tdetails, "12570       \t\t DELHI \t\t PATNA    	 \t\t Rs.%d/- \t\t %d        \n",t1.charges[3], t1.s_left[3]);
	fprintf (fp_tdetails, "12571       \t\t DELHI \t\t VARANASI    	 \t\t Rs.%d/- \t\t %d        \n",t1.charges[4], t1.s_left[4]);
	fprintf (fp_tdetails, "12572       \t\t DELHI \t\t HYDERABAD    \t\t\t Rs.%d/-\t\t %d        \n",t1.charges[5], t1.s_left[5]);
	fprintf (fp_tdetails, "12573       \t\t DELHI \t\t BENGALURU   	 \t\t Rs.%d/- \t\t %d        \n",t1.charges[6], t1.s_left[6]);
	fprintf (fp_tdetails, "12574       \t\t DELHI \t\t JAIPUR  	     \t\t Rs.%d/- \t\t %d        \n",t1.charges[7], t1.s_left[7]);
	fprintf (fp_tdetails, "12575       \t\t DELHI \t\t LUCKNOW     	 \t\t Rs.%d/- \t\t %d        \n",t1.charges[8], t1.s_left[8]);

	fclose(fp_tdetails);
}

void set_train_variables(){	//function to set information related to train details
	for (int i = 1; i < 9; ++i)
	{
		t1.s_left[i] = 100;
		t1.charges[i] = 540 + 10*i;
		t1.t_number[i] = 12567 + i;
	}


}

void enquiry(){	//funtion for enquiry
	start:
	system("clear");

	char src[100], dest[100];		//input source and destination
	printf("ENTER THE SOURCE STATION\t");
	scanf("%s",src);
	fflush(stdin);
	strtoupr(src);

	printf("ENTER THE DESTINATION STATION\t");
	scanf("%s",dest);
	fflush(stdin);
	strtoupr(dest);

	int choice = check_info(src,dest);	//function to check if train is available between the desired source and destination

	switch(choice){	//sets the data according to the choice made
		case -1:
		goto start;
		break;
		case -2:
		return;

		case 1:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[1],t1.charges[1],t1.s_left[1]);
		break;
		case 2:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[2],t1.charges[2],t1.s_left[2]);
		break;
		case 3:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[3],t1.charges[3],t1.s_left[3]);
		break;
		case 4:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[4],t1.charges[4],t1.s_left[4]);
		break;
		case 5:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[5],t1.charges[5],t1.s_left[5]);
		break;
		case 6:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[6],t1.charges[6],t1.s_left[6]);
		break;
		case 7:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[7],t1.charges[7],t1.s_left[7]);
		break;
		case 8:
		printf("TRAIN NO.\t\tCHARGES\t\tSEAT LEFT\n\n");
		printf("%d\t\t%d\t\t%d\n\n",t1.t_number[8],t1.charges[8],t1.s_left[8]);
		break;
	}


}

void view_all_train_details(){	//function to view all the available train details
	system("clear");
	char f_data;
	FILE *fp_tdetails;
	fp_tdetails =  fopen("Train details-2019B1PS0188_P8","r");

	f_data = fgetc(fp_tdetails);
	while(f_data != EOF){
		printf("%c", f_data);
		f_data = fgetc(fp_tdetails);
	}

	fclose(fp_tdetails);
}



void booking(){	//function to make a booking
	start:
	system("clear");

	printf("\n\nENTER FIRST NAME OF THE PASSENGER WITHOUT ANY WHITESPACE\t" );	//input passenger first name
	scanf("%s",p1.p_fname);
	fflush(stdin);
	strtoupr(p1.p_fname);

	printf("ENTER LAST NAME OF THE PASSENGER WITHOUT ANY WHITESPACE\t");	//input passenger last name
	scanf("%s",p1.p_lname);
	fflush(stdin);
	strtoupr(p1.p_lname);

	printf("ENTER SOURCE\t");	//input source station
	scanf("%s", p1.src);
	fflush(stdin);
	strtoupr(p1.src);

	printf("ENTER DESTINATION\t");	//input destination station
	scanf("%s", p1.dest);
	fflush(stdin);
	strtoupr(p1.dest);

	int choice;
	choice = check_info(p1.src,p1.dest);	//check source and destination station

	switch(choice){	//sets data according to the choice made
		case -1:
		goto start;
		break;
		case -2:
		return;

		case 1:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[1]);
		if(t1.s_left[1]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[1]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 2:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[2]);
		if(t1.s_left[2]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[2]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 3:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[3]);
		if(t1.s_left[3]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[3]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 4:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[4]);
		if(t1.s_left[4]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[4]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 5:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[5]);
		if(t1.s_left[5]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[5]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 6:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[6]);
		if(t1.s_left[6]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[6]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 7:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[7]);
		if(t1.s_left[7]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[7]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
		case 8:
		printf("RESERVATION CHARGES\t%d\n\n",t1.charges[8]);
		if(t1.s_left[8]>0) printf("SEAT AVAILABLE--> %d\n\n", t1.s_left[8]);
		else {
			printf("NO SEAT AVAILABLE\n\n");
			return; }
		break;
	}
	
	char conf_choice[100];	//asks for the confirmation if the seat is available
	again:
	printf("PRESS 1 TO CONFIRM YOUR BOOKING OR 0 TO CANCEL BOOKING\n");	//confirm booking
	scanf("%s",conf_choice);
	if(!strcmp(conf_choice,"1")) conf_booking(choice);
	
	else if(!strcmp(conf_choice,"0")) return;
	else{
		printf("INVALID CHOICE\n\n");
		goto again;
	}
}

void conf_booking(int choice){	//function to confirm your booking
	pnr++;	//increasing pnr every time a booking is confirmed
	pnr_arr[pnr] = choice;
	t1.s_left[choice]--;
	FILE *fp;
	fp = fopen("Ticket data-2019B1PS0188_P8","a");	//appending booked ticket data to the ticket data file
	fprintf(fp,"%d\t%d\t\t %s %s\t\t\t\t %s\t\t %s\n", pnr,t1.t_number[choice],p1.p_fname,p1.p_lname, p1.src, p1.dest);
	system("clear");
	printf("\n****************TICKET DETAILS****************\n\n");
	printf("PNR NO.\tTRAIN NO.\t\tPASSENGER NAME\t\tSOURCE\t  \tDESTINATION\n");
	printf("\n%d\t%d\t\t %s %s\t\t %s\t TO \t%s \n\n", pnr,t1.t_number[choice],p1.p_fname,p1.p_lname, p1.src, p1.dest);
	printf("TICKET STATUS : CONFIRMED\n\n");
	fclose(fp);
	return;
}


void cancellation()	//function to cancel a booked ticket data
{
	FILE *fp1,*fp2;

    char str[100];
    int  current_pnr=1;
    int del_pnr;
    float charges;

    printf("Enter the PNR of the ticket:\n");
    scanf("%d",&del_pnr);
    if(pnr_arr[del_pnr]==0){	//checks if the ticket with the entered pnr exists or not
    	printf("TICKET WITH THE FOLLOWING PNR DOES NOT EXIST\n\n");
    	return;
    }

    charges = t1.charges[pnr_arr[del_pnr]];

    t1.s_left[pnr_arr[del_pnr]]++;
    pnr_arr[del_pnr] = 0;

    fp1=  fopen("Ticket data-2019B1PS0188_P8","r"); // open the file in read mode
    fp2 = fopen("temp.txt", "w"); // open the temporary file in write mode

    while(fgets(str,99,fp1) != NULL) //reads and copy lines with data to a temp file except for the one with the pnr to be deleted.
	{			             
		if(current_pnr != del_pnr)
			fputs(str,fp2);
		else
		fprintf(fp2,"THE TICKET WITH PNR %d IS CANCELLED !!!\n",del_pnr);
		current_pnr++;
	}       
    fclose(fp1);
    fclose(fp2);

    remove("Ticket data-2019B1PS0188_P8");  		     // remove the original file 
    rename("temp.txt", "Ticket data-2019B1PS0188_P8"); 	 // rename the temporary file to original name

    printf("Ticket with pnr %d is cancelled. \n\nREFUND AMOUNT = %f",del_pnr,0.5*charges);

    return;
}


int check_info(char src[],char dest[]){	//function to check the information entered by the user regarding source and destination

	if(strcmp(src, "DELHI")){	//checks if source is other than delhi
		char choice[100];
		printf("NO TRAINS AVAILABLE\n\n");
		again1:
		printf("PRESS 1 TO CONTINUE OR 0 TO RETURN TO MAIN WINDOW\t");
		scanf("%s",choice);
		if(!strcmp(choice, "1")) return -1;
		else if(!strcmp(choice, "0")) return -2;
		else{
			printf("INVALID CHOICE\n\n");
			goto again1;
		}
	}
	//checking destination from the available ones

	else if(!strcmp(dest, "GORAKHPUR")){
		return 1;
	}
	else if(!strcmp(dest, "BHOPAL")){
		return 2;
	}
	else if(!strcmp(dest, "PATNA")){
		return 3;
	}
	else if(!strcmp(dest, "VARANASI")){
		return 4;
	}
	else if(!strcmp(dest, "HYDERABAD")){
		return 5;
	}
	else if(!strcmp(dest, "BENGALURU")){
		return 6;
	}
	else if(!strcmp(dest, "JAIPUR")){
		return 7;
	}
	else if(!strcmp(dest, "LUCKNOW")){
		return 8;
	}
	else{
		char choice[100];
		printf("NO TRAINS AVAILABLE TO THE DESTINED STATION\n\n");
		again2:
		printf("PRESS 1 TO CONTINUE OR 0 TO RETURN TO MAIN WINDOW");
		scanf("%s",choice);
		if(!strcmp(choice, "1")) return -1;
		else if(!strcmp(choice, "0")) return -2;
		else{
			printf("INVALID CHOICE\n");
			goto again2;
		}
	}	

}    

void view_ticket_details(){	//function to view all the ticket details
	system("clear");
	FILE *f_tkt_details;
	char f_data;
	f_tkt_details = fopen("Ticket data-2019B1PS0188_P8","r");
	if(f_tkt_details == NULL){	//checks if there is a ticket data available or not
		printf("NO TICKET DATA AVAILABLE");
		return;
	}

	f_data = fgetc(f_tkt_details);
	while(f_data != EOF){	//displays all the ticket data, if available
		printf("%c", f_data);
		f_data = fgetc(f_tkt_details);
	}

	fclose(f_tkt_details);
	return;
}   

void strtoupr(char str[]){	//function to convert the entired string into uppercase
	 for(int i=0;i<=strlen(str);i++){
      if(str[i]>=97&&str[i]<=122)
         str[i]=str[i]-32;
   }
   return;
}


/****************************END OF PROGRAM*********************************/ 
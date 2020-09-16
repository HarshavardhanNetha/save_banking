#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <time.h>

int c_count=0; //no. of customers
FILE *fp;
//int read_file=0;


struct mainlist{
	//inputs
	char fullname[30];
	char aadhaar[30];
	char gender[7];
	char mob[30];
	int dob;
	int age;
	char address[100];
	//outputs
	char acnum[30];
	char atmnum[30];
	int atmpin;
	char tempac[30];
	char tempatm[30];
	int bal;
} ml[100];
	
int details(int i){
	printf("\nFullName: %s\nMobile: %s\nAadhaar : %s\nAC Number: %s\nATM Number: %s\nGender: %s\nAge: %d\nDOB: %d\nAddress: %s\n",(ml+i)->fullname,(ml+i)->mob,(ml+i)->aadhaar,(ml+i)->acnum,(ml+i)->atmnum,(ml+i)->gender,(ml+i)->age,(ml+i)->dob,(ml+i)->address);
	return 0;
}

int createAC(int cc){
	
	//cc+=1;
	printf("Aadhaar Number:");
	char temp[30];
	int x,flag=0;
	//scanf("%s",&(ml+cc)->aadhaar);
	scanf("%s",temp);
	fflush(stdin);

	for(x=0;x<=cc;x++){
		if(!strcmp((ml+x)->aadhaar,temp)){
			flag=1;
			printf("You already have an account. Your AC No: %s\n",(ml+x)->acnum); return cc;
		}
	}
		if(flag==0) { 
		 strcpy((ml+cc)->aadhaar,temp );
		 goto create;
		 }
	
create: {
	printf("Full Name (with no spaces):");
	scanf("%s",(ml+cc)->fullname);
	fflush(stdin);
	printf("Date of Birth (DDMMYYYY):");
	scanf("%d",&(ml+cc)->dob);
	fflush(stdin);
	int yy;
	yy=((ml+cc)->dob)%10000;
	(ml+cc)->atmpin=yy;
	printf("Enter Mobile Number:");
	scanf("%s",(ml+cc)->mob);
	fflush(stdin);
	printf("Age:");
	scanf("%d",&(ml+cc)->age);
	fflush(stdin);
	printf("Gender (Male / Female):");
	scanf("%s",(ml+cc)->gender);
	fflush(stdin);
	printf("Address (with no spaces):");
	scanf("%s",(ml+cc)->address);
	fflush(stdin);

	strcpy((ml+cc)->tempac,(ml+cc)->mob);
	strcpy((ml+cc)->acnum,strrev((ml+cc)->tempac));
	
	strcpy((ml+cc)->tempatm,(ml+cc)->aadhaar);
	strcpy((ml+cc)->atmnum,strrev((ml+cc)->tempatm));
	(ml+cc)->bal=0;

	printf("Your Account is Successfully Created.\nAC No.: %s\nATM No.: %s\nPIN: %d\n\n",(ml+cc)->acnum,(ml+cc)->atmnum,(ml+cc)->atmpin);
	fflush(stdout);
	c_count+=1;
	
	return 0;}
}
int search(int cc){
	char key[30];
	int i,flag=0,flag2=0,flag3=0;
	printf("\nSearch using...\n1. AC Number\n2. Aadhaar Number\n3.Atm Number\nEnter a number:");
	int temp;
	scanf("%d",&temp);
	switch(temp){
		case 1: {
			printf("Enter AC Number:");
			scanf("%s",key);
			for(i=0;i<cc;i++){
				if(!strcmp((ml+i)->acnum,key)){
				   details(i);
				   flag=1;
				   return 0;	
				}
			}
				if(flag==0) {
					printf("No details found.\n");
					return 0;
				}
			return 0;
		}
		case 2: {
			printf("Enter Aadhaar Number:");
			scanf("%s",key);
			for(i=0;i<cc;i++){
				if(!strcmp((ml+i)->aadhaar,key)){
				   details(i);
				   flag2=1;
				   return 0;	
				}
			}
				if(flag2==0) {
					printf("No details found.\n");
					return 0;
				}
			return 0;
		}
		case 3: {
			printf("Enter ATM Number:");
			scanf("%s",key);
			for(i=0;i<cc;i++){
				if(!strcmp((ml+i)->atmnum,key)){
				   details(i);	flag3=1;	return 0;
				}
			}
				if(flag3==0) {
					printf("No details found.\n");
					return 0;
				}
			return 0;
		}
		default : {
			printf("Invalid Input Redirecting to Main Menu...\n");
			sleep(1);
			return 0;
		}	
	}	
	return 0;
}

int dp(int i){      
					printf("\nHello %s..! Enter the Amount to deposit (min Rs.1/-):",(ml+i)->fullname);
					int amnt,flag;
					scanf("%d",&amnt);
					(ml+i)->bal+=amnt;
					printf("Deposit Successful. \nNew Balance = %d\n\n",(ml+i)->bal);
					flag=1;
					return 0;
}

int home_deposit(int cc){
	int option;
	printf("\nChoose an option to Deposit:\n1 - AC Number\n2 - Aadhaar\n3 - ATM\n0 - Exit\n");
	scanf("%d",&option);
	switch(option){
		int flag=0;
		case 1: {
			int i; char x[30];
			printf("Enter AC Num:");
			scanf("%s",x);
			for(i=0;i<cc;i++){
			//	bool null;
			//	null=;
				if(!strcmp((ml+i)->acnum,x)){
 					dp(i);
 					flag=1;
 					return main();
 				}}
				if(flag==0) {
					printf("Enter Correct Details... Returning to MAIN MENU.\n");
					sleep(1);
					return 0;
				}
			
			break;
		}
		case 2: {
			int i; char x[30];
			printf("Enter Aadhaar No:");
			scanf("%s",x);
			for(i=0;i<cc;i++){
				if(!strcmp(x,(ml+i)->aadhaar)){
					dp(i);
					flag=1;
					return main();
				}}
				if(flag==0) {
					printf("Enter Correct Details... Returning to MAIN MENU.\n");
					sleep(1);
					return 0;
				
			}
			break;
		}
		case 3: {
			int i; char x[30];
			printf("Enter ATM Num:");
			scanf("%s",x);
			for(i=0;i<cc;i++){
				if(!strcmp(x,(ml+i)->atmnum)){
					dp(i);
					flag=1;
					return main();
				}}
				if(flag==0) {
					printf("Enter Correct Details... Returning to MAIN MENU.\n");
					sleep(1);
					return 0;
				
			}
			break;
		}
		case 0: return 0;
	}
}

int wd(int i){		printf("\nHello %s..! Enter the Amount to withdraw (min Rs.1/-): ",(ml+i)->fullname);
					int amnt;
					scanf("%d",&amnt);
					int flag;
					if(amnt<=(ml+i)->bal){
						int pin;
						printf("Enter PIN Number:");
						scanf("%d",&pin);
						if(pin==(ml+i)->atmpin){
						(ml+i)->bal-=amnt;
						printf("Withdrawal Successful. \nNew Balance = %d\n",(ml+i)->bal);
						flag=1; }
						if(flag==0){ printf("Wrong PIN.\n");
						return main();
						}	
					}
					else printf("Insufficient Balance.\n");
					return 0;}

int home_withdraw(int cc){
	int option;
	printf("\nChoose an option to Withdraw:\n1 - AC Number\n2 - Aadhaar\n3 - ATM\n0 - Exit\n");
	scanf("%d",&option);
	switch(option){
		int flag=0;
		case 1: {
			int i; char x[30];
			printf("Enter AC Number:");
			scanf("%s",x);
			for(i=0;i<cc;i++){
				if(!strcmp(x,(ml+i)->acnum)){
					wd(i);
					flag=1;
					return main();
				}}
				if(flag==0) {
					printf("\nEnter Correct Details... Returning to MAIN MENU.\n");
					sleep(1);
					return 0;
				}
			
			break;
		}
		case 2: {
			int i; char x[30];
			printf("Enter Aadhaar Number:");			scanf("%s",x);
			for(i=0;i<cc;i++){
				if(!strcmp(x,(ml+i)->aadhaar)){
					wd(i);
					flag=1;
					return main();
				}}
				if(flag==0) {
					printf("Enter Correct Details... Returning to MAIN MENU.\n");
					sleep(1);
					return 0;
				}
			
			break;
		}
		case 3: {
			int i; char x[30];
			printf("Enter ATM Number:");
			scanf("%s",x);
			for(i=0;i<cc;i++){
				if(!strcmp(x,(ml+i)->atmnum)){
					wd(i);
					flag=1;
					return main();
				}}
				if(flag==1) {
					printf("Enter Correct Details... Returning to MAIN MENU.\n");
					sleep(1);
					return 0;
				}
			
			break;
		}
		case 0: return 0;
	}
}

int edit(int cc){
	char key[30];int i;
	printf("Enter AC Num:");
	scanf("%s",key);
	int flag=0;
	for(i=0;i<cc;i++){
		if(!strcmp(key,(ml+i)->acnum)){
			details(i);
			flag=1;
			break;
			}
		}
		if(flag==1){
		
		int option=1;
		printf("\nEnter what to Edit:\n1. Fullname\n2. Mobile No.\n3. Gender\n4. Date of Birth\n5. Age\n6. Address\n7. ATM Pin\n0 Exit\n");
		while(option){
				printf("Choose an option:");
				scanf("%d",&option);
				switch(option){
					case 1:{
						printf("Fullname :%s\n Enter new field :",(ml+i)->fullname);
						scanf("%s",(ml+i)->fullname);
						printf("Updated Successfully.\n");
						break;
					}
					case 2:{
						printf("Mobile Number :%d\n Enter new field :",(ml+i)->mob);
						scanf("%d",&(ml+i)->mob);
						printf("Updated Successfully.\n");
						break;
					}
					/*case 3:{
						printf("Email :%s\n Enter new field :",(ml+i)->email);
						scanf("%s",(ml+i)->email);
						printf("Updated Successfully.\n");
						break;
					}*/
					case 3:{
						printf("Gender :%s\n Enter new field :",(ml+i)->gender);
						scanf("%s",(ml+i)->gender);
						printf("Updated Successfully.\n");
						break;
					}
					case 4:{
						printf("Date of Birth :%s\n Enter new field :",(ml+i)->dob);
						scanf("%d",&(ml+i)->dob);
						printf("Updated Successfully.\n");
						break;
					}
					case 5:{
						printf("Age :%d\n Enter new field :",(ml+i)->age);
						scanf("%d",&(ml+i)->age);
						printf("Updated Successfully.\n");
						break;
					}
					case 6:{
						printf("Address :%s\n Enter new field :",(ml+i)->address);
						scanf("%s",(ml+i)->address);
						printf("Updated Successfully.\n");
						break;
					}
					case 7:{
						printf("ATMPin :%d\n Enter new field :",(ml+i)->atmpin);
						scanf("%d",&(ml+i)->atmpin);
						printf("Updated Successfully.\n");
						break;
					}
					case 0:{
						//printf("Email :%s\n Enter new field :",(ml+i)->email);
						//scanf("%s",(ml+i)->email);
						printf("Account Details Updated Successfully.\n\n");
						sleep(1);
						return 0;
					}
					default: {
						printf("Invalid Input returning to MAIN MENU...\n");
						sleep(1);
						return 0;
					}
				}
			}
		}
		else{
			printf("No details found.\n");
			return 0;
		}
	return 0;
}


int services(int cc){
	char read_ac[30]; int i;
	printf("Please Enter your AC Num:");
	scanf("%s",read_ac);
	int flag=0;
	for(i=0;i<cc;i++){
		
		if(!strcmp(read_ac,(ml+i)->acnum)){
			flag=1;
		//	int option=1;
			return serv(i,cc);
		}
	}
	if(flag==0){
		printf("Enter Correct AC Number.");
		return main();
	}
}

int serv(int i,int cc){	
	int option=1;
	while(option){
	printf("\nWelcome %s. Choose an option from below:\n1. Deposit\n2. Withdraw\n3. Transfer\n4. View Balance\n5. Exit\n",(ml+i)->fullname);
	scanf("%d",&option);
		switch(option){
			case 1:{
				deposit(i,cc);
				return serv(i,cc);
			}
			case 2:{
				withdraw(i,cc);
				return serv(i,cc);
			}
			case 3:{
				transfer(cc,i);
				return serv(i,cc);
			}
			case 4:{
				printf("Balance : %d\n",(ml+i)->bal);
				return serv(i,cc);
			}
			case 5:{
			//	goto edit;
				//return serv(i,cc);
				return main();
			}
			default: return serv(i,cc);
		}
	}
}
int deposit(int i,int cc){
	int amnt;
	printf("Please Enter amount to Deposit:");
	scanf("%d",&amnt);
	(ml+i)->bal+=amnt;
	printf("Deposit successful. New Balance: %d\n",(ml+i)->bal);
	return serv(i,cc);
}
int withdraw(int i,int cc){
	int amnt,flag=0;
	printf("Please Enter amount to be withdraw (min Rs.1/-):");
	scanf("%d",&amnt);
	if(amnt<=(ml+i)->bal){
		int pin;
		printf("Enter PIN Number:");
		scanf("%d",&pin);
		if(pin==(ml+i)->atmpin){
			(ml+i)->bal-=amnt;
			flag=1; 
			printf("Withdrawal Successful. New Balance: %d\n",(ml+i)->bal);
			}
		if(flag==0){ printf("Wrong PIN. Withdraw Failed.\n");
			return serv(i,cc);
		}	
	}
	else{
	    printf("Insufficient Balance. Withdraw Failed.\nBalance: %d\n",(ml+i)->bal);
		return serv(i,cc);
	}
}

int value(int i,int cc){
	char resp[30];
	printf("Please Enter recipient AC Num:");
	scanf("%s",resp);
	int j,flag=0;
	for(j=0;j<cc;j++){
		if(!strcmp(resp,(ml+j)->acnum)){
			flag=1;
			printf("Money will be tranfered to %s \nAC No. %s.\n",(ml+j)->fullname,(ml+j)->acnum);
			return j;			
		}
	}
		if(flag==0){
			printf("No recipient found. Please recheck AC Number.\n");
			return serv(i,cc);
		}
}

int transfer(int cc,int i){
	int j,amnt,flag=0;
	j=value(i,cc);
	printf("Please Enter amount to be transfered (min Rs.1/-):");
	scanf("%d",&amnt);
	if(amnt<(ml+i)->bal){
		int pin;
		printf("Enter YOUR PIN Number:");
		scanf("%d",&pin);
		if(pin==(ml+i)->atmpin){
			(ml+i)->bal-=amnt;
			flag=1; }
		if(flag==0){ printf("Wrong PIN. Transfer Failed.\n");
			return serv(i,cc);
		}	
	}
	else{
	    printf("Insufficient Balance. Transfer Failed.\nBalance: %d\n",(ml+i)->bal);
		;
	}
		
	if(flag==1){
	(ml+j)->bal+=amnt;
	printf("Transfer Successful.\nNew Balance:%d",(ml+i)->bal);
	return serv(i,cc);}
}
int main(){
//	sleep(0.5);
	printf("\t\t\t*******\n");
//	static int c_count=0;
	static int read_file=0;
	if(read_file==0){
		int i=0;
		fp=fopen("null.txt","r+");
		if(fp==NULL){
			printf("No file created.\n");
		}
		else{
			while(!feof(fp)){
			fscanf(fp,"%s %s %d %d %s %s %s %d %d %s %s",ml[i].fullname,ml[i].aadhaar,&ml[i].dob,&ml[i].age,ml[i].gender,ml[i].acnum,ml[i].atmnum,&ml[i].atmpin,&ml[i].bal,ml[i].mob,ml[i].address);
			i++;}
			c_count=i-1;
		}
		read_file=1;
		
		fclose(fp);
		//welcomeScreen
		
printf("WELCOME TO\n\n");
printf("	  ******       *****     **       **   *******\n");
printf("	 **           **   **     **     **    **       \n");
printf("	    **        ********     **   **     *****      \n");
printf("	      **      **    **      ** **      **          \n");
printf("	 *******      **    **       ***       ********     \n\n");

		
		}
		//rewind(fp);}

	int flag=1;
	while(flag){
		printf("1. Create an Account\n2. Edit Details\n3. Deposit\n4. Withdrawal\n5. Services\n6. Search\n0. Exit\n\n>>> ");
		scanf("%d",&flag);
		switch (flag){
			case 1:{
				createAC(c_count);
				//printf("\n 0 - Exit \t 1 to Create_Other...!");
				//printf("%d",c_count);
				return main();
			}
			case 2:{
				edit(c_count);
				return main();
			}
			case 3:{
				home_deposit(c_count);
				return main();
			}
			case 4:{
				home_withdraw(c_count);
				return main();
			}
			case 6:{
				search(c_count);
				return main();
			}
			case 5:{
				services(c_count);
				return main();
			}
			default:{// FILE fp;
			fp=fopen("null.txt","w");

					if(fp==NULL){
						printf("Cant access file.\n");
						return 0;
					}
					else{
						int i;
					for(i=0;i<c_count;i++){
						fprintf(fp,"%s %s %d %d %s %s %s %d %d %s %s\n",ml[i].fullname,ml[i].aadhaar,ml[i].dob,ml[i].age,ml[i].gender,ml[i].acnum,ml[i].atmnum,ml[i].atmpin,ml[i].bal,ml[i].mob,ml[i].address);
					}
					}
					fclose(fp);
				//printf("\n\n%d\n",c_count);
				
printf(" ********   **   **      ******      ***   **    **   **\n");  //fflush(stdout);sleep(0.2);
printf("    **      **   **     **    **     ** *  **    **  **\n");  //fflush(stdout);sleep(0.2);
printf("    **      *******     **     **    **  * **    ****\n");  //fflush(stdout);sleep(0.2);
printf("    **      **   **     *********    **   ***    **  **\n");  //fflush(stdout);sleep(0.2);
printf("    **      **   **     **     **    **    **    **   **\n\n"); // fflush(stdout);sleep(0.2);

printf("	     **    **    ****      **      **  \n");  //fflush(stdout);sleep(0.2);
printf("	      **  **   **    **    **      **  \n");  //fflush(stdout);sleep(0.2);
printf("	        **    **      **   **      **  \n");  //fflush(stdout);sleep(0.2);
printf("	        **     **    **     **    **   \n");  //fflush(stdout);sleep(0.2);
printf("	        **       ****         ****     \n") ;  // fflush(stdout);sleep(0.2);
				
				exit(0);
				//break;
			}
//			default: exit(0);
		}
	
	return 0;
}
}

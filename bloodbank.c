#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void homescreen();
int signup();
void signin();
int z=0;


struct userdata{
    char first_name[100];
    char last_name[50];
    char bloodtype[3];
    int age;
    float weight;
    char phone_no[11];
    char password[20];
}a[10];

void reset_pass(){
	int i=0;
	int value,value1;
	char phone[10];
	char blood[3];
	printf("Enter Phone Number: ");
	scanf("%s",&phone);
	printf("Enter Blood Type: ");
	scanf("%s",&blood);
	while(i<10){
	value=strcmp(phone,a[i].phone_no);
	value1=strcmp(blood,a[i].bloodtype);
	if(value==0 && value1==0){
	    printf("Enter New Password: ");
	    scanf("%s",a[i].password);
	    printf("Password Changed Successfully\n");
	    homescreen();
	    
	}
	else{
		printf("Incorrect Values Entered\n");
		reset_pass();
		}
	}
	
}

void donate(int i){
	if(a[i].weight<45){
		printf("Your Weight Is Less Than The Least Weight Required To Donate Blood(45KG)\n");
		homepage(i);
	}
	if(a[i].age<18 || a[i].age>60){
		printf("You Do Not Meet The Age Criteria To Donate Blood (18-60 y.o.)");
		homepage(i);
	}
	printf("You Are Eligible To Donate Blood \nWe Will Contact You On The Number Provided By You For Further Process\n");
	printf("Redirecting To Home Page \n");
	homepage(i);
	
}

void bloodav(int i){
	int j;
	char blood[3];
	printf("1. A+ \t2. A- \t3.B+ \t4. B-\n");
	printf("5.AB+ \t6. AB- \t7.O+ \t8. O-\n");
	printf("Enter A Number: ");
	scanf("%d",&j);
	switch(j){
		case 1: strcpy(blood,"A+");
		break;
		case 2: strcpy(blood,"A-");
		break;
		case 3: strcpy(blood,"B+");
		break;
		case 4: strcpy(blood,"B-");
		break;
		case 5: strcpy(blood,"AB+");
		break;
		case 6: strcpy(blood,"AB-");
		break;
		case 7: strcpy(blood,"O+");
		break;
		case 8: strcpy(blood,"O-");
		break;
		default:printf("Invalid Number\n");
		bloodav(i);
		break;	
	}
	printf("We Will Contact You On The Number Provided By You For Further Process\n");
	printf("Returning To Home Page \n");
	homepage(i);
}

void profile(int i){
	printf("PROFILE DETAILS\n");
	printf("Name: %s %s\n",a[i].first_name,a[i].last_name);
	printf("Blood Type: %s\n",a[i].bloodtype);
	printf("Age: %d\n",a[i].age);
	printf("Weight: %f\n",a[i].weight);
	printf("Phone No.: %s\n",a[i].phone_no);
	homepage(i);
}

void homepage(int i){
	int j;
    printf("Welcome Back %s %s \n",a[i].first_name,a[i].last_name);
    printf("1. Donate Blood \n2. Check Blood Availability \n3.Check Profile \n4. Log Out \n");
    printf("Enter Number: ");
    scanf("%d",&j);
    if(j>0 && j<5){
    	if(j==1){
    		printf("Redirecting To Blood Donation Page \n");
    		donate(i);
		}
		else if(j==2){
			printf("Redirecing To Blood Availability Page \n");
			bloodav(i);
		}
		else if(j==3){
			printf("Redirecting To Profile Page \n");
			profile(i);
		}
		else if(j==4){
			printf("Logging Out \n");
			homescreen();
		}
	}
	else{
		printf("Enter A Valid Number\n");
		homepage(i);
	}
}
void signin(){
	int i=0;
	int value;
	int value1;
	char check[11];
	char pass[20];
	printf("Enter Phone No: ");
	scanf("%s",&check);
	printf("Enter Password: ");
	scanf("%s",&pass);
	while(i<10){
	value=strcmp(check,a[i].phone_no);
	value1=strcmp(pass,a[i].password);
	if(value==0 && value1==0){
	    printf("Sign In successfull \nTaking You to Home page\n");
	    homepage(i);
	    break;
	    
	}
	else{
	    int y;
	    printf("Incorrect Phone No./Password Combination \n");
	    printf("1. Return To Sign In Page \n2.Redirect To Sign Up Page \n");
	    printf("Enter A Number: ");
	    scanf("%d",&y);
	    if(y==1){
	        signin();
	    }
	    else if(y==2){
	        signup();
	    }
	    else{
	        printf("Invalid Number \nReturning To Homescreen\n");
	        homescreen();
	    }
	}
	i++;
	}
}
int signup()
{
    printf("Please Enter The Following Details Carefully.\n");
    printf("First Name: ");
    scanf("%s",&a[z].first_name);
    printf("Last Name: ");
    scanf("%s",&a[z].last_name);
    printf("Blood Type: ");
    scanf("%s",&a[z].bloodtype);
    printf("Age: ");
    scanf("%d",&a[z].age);
    printf("Weight (in Kg): ");
    scanf("%f",&a[z].weight);
    printf("Contact No.: ");
    scanf("%s",&a[z].phone_no);
    printf("Password (max 20 characters): ");
    scanf("%s",&a[z].password);
    z=z+1;
    printf("Sign Up Successful.\n");
    printf("Redirecting To Sign In Page \n");
    signin();
    }


void homescreen() {
    int a;
    printf("Welcome To Blood Bank Management System \n");
    printf("1. Existing User Log In  \n");
    printf("2. New User Sign Up \n");
    printf("3. Reset Password \n");
    printf("Enter A Number: ");
    scanf("%d",&a);
    if(a>0 && a<4){
        if(a==1){
            printf("Redirecting To Sign In Page \n");
            signin();
        }
        else if(a==2){
            printf("Redirecting To Sign Up Page \n");
            signup();
        }
        else if(a==3){
            printf("Redirecting To Password Reset Page \n");
            reset_pass();
        }
    }
    else{
        printf("Please Enter A Valid Number \n");
        homescreen();
    }
}


int main() {
    homescreen();
}


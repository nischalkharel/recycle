#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

//Functions 
int user_identification();
int user_action(), recycling_score(int [][4]);
void item_lookup(), recycle_pros(), user_register(int [][4]),carbon_footprint(),score_calculation(),other_help();
int collector_verify();
void score_edit();


int main()
{

//Variables used
int identity;
int actionR, user_score;
int user[9999][4];
int runAgain = 0;
//Let users know that they need to select options using numbers.
do
{
printf("\nEnter the number that represents your selection!");
identity = user_identification();

	
//user is a RESIDENT
if (identity == 1)
{
actionR = user_action();

	switch (actionR)
	{
		//Resident wants to look up an item.
	case 1:
		item_lookup();
		break;
		
		//Resident wants to check recycling score
	case 2:
		user_score = recycling_score(user);
		if (user_score != -1)
		{
		printf("\nYour recycling score is %d", user_score);
		}
		break;
		
		//Resident wants to check the benefits of recycling.
	case 3:
		recycle_pros();
		break;
		
		//Resident wants to register as a new user.
	case 4:
		user_register(user);
		break;
		
		//Resident wants to calculate their carbon footprint.
	case 5:
		carbon_footprint();
		break;
		
		//Resident wants to know how the recycling scores are calculated
	case 6:
		score_calculation();
		break;
		//Resident wants other help
	case 7:
		other_help();
		break;
	}
}

//user is a waste collector
if(identity == 2)
	{
		int access = collector_verify();
		if (access == 1)
		{
			score_edit();
		}
	}
	do
	{
printf("\n\nWould you like to run the program again?\n\t1)Yes!\n\t2)No!");
printf("\nYour selection: ");
scanf("%d", &runAgain);
	}while(runAgain != 1 && runAgain !=2);
	
	if (runAgain == 2)
	{
		printf("\n\n\n\t\tThank You for recycling!");
	}
}while(runAgain == 1);
return 0;	
}

//user is a resident or waste collector
int user_identification()
{
	int identity;
	printf("\nAre you:\n\t1) Resident\n\t2) Waste Collector\n");
	printf("\nYour Section: ");
	scanf("%d", &identity);
	
	while(identity != 1 && identity != 2)
	{
	
	printf("Try Again:\n\t1) Resident\n\t2) Waste Collector\n");
	printf("\nYour Section: ");
	scanf("%d", &identity);
	
	}

return identity;
}
//RESIDENT: choice of actions
int user_action()
{
	int actionR;
	
	printf("\nSelect the appropriate action from the list below:\n");
	printf("\n\t1)Are you looking to check if an item is recyclable?");
	printf("\n\t2)Do you want to check your recycling score?");
	printf("\n\t3)Do you want to see the benefits of recycycling?");
	printf("\n\t4)Register as a new user");
	printf("\n\t5)Calculate your Carbon Footprint?");
	printf("\n\t6)How are recycling scores calculated?");
	printf("\n\t7)Other questions/concerns?\n");
	printf("\nYour Section: ");
	scanf("%d",&actionR);
	
	while(actionR>7 || actionR<1)
	{
		printf("\nTry Again");
		printf("\nYour Section: ");
		scanf("%d",&actionR);
	}
	
	return actionR;
}
//RESIDENT: 1.1 Item look up
void item_lookup()
{
	int selected_item;
	
	
		printf("\nSelect a number from 1-14 to check if a specific item is recyclable or not: ");
		printf("\n\t1. Books\n\t2. Batteries\n\t3. Plastic containers and bottles");
		printf("\n\t4. Cans\n\t5. Paper\n\t6. Glass container and bottles\n\t7. Ink cartridges");
		printf("\n\t8. Food tained items\n\t9. Medical waste\n\t10. Foil cups or containers");
		printf("\n\t11. Plastic utensils\n\t12. Loose plastic bags\n\t13. Food waste\n\t14. Light bulbs\n");
		printf("\nYour Section: ");
		scanf("%d", &selected_item);
	while(selected_item>14)
	{
		printf("\nTry Again");
		printf("\nYour Section: ");
		scanf("%d",&selected_item);
	}
	
		switch (selected_item)
		{
			case 1:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 2:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 3:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 4:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 5:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 6:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 7:
			printf("\nIt is recyclable! Be sure to put it in the recycling bin!");
			break;
			case 8:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
			case 9:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
			case 10:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
			case 11:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
			case 12:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
			case 13:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
			case 14:
			printf("\nIt is NOT recyclable! Throw it in trash or the compost bin!");
			break;
		}
}
//RESIDENT: 1.2 check recycling score
int recycling_score(int user[][4])
{
	int user_score=-1, user_ID, status=0, rows=0, pass_word,other_more=0;
	
	//int user_ID, user_score=5; 
	FILE *database;
	database = fopen("user_database.txt","r");
	
	printf("\nEnter your user ID: ");
	scanf("%d", &user_ID);
	
	printf("\nEnter your password: ");
	scanf("%d", &pass_word);
	
	
	while (status != EOF)
	{
		status = fscanf(database, "%d %d %d %d", &user[rows][0], &user[rows][1],&user[rows][2], &user[rows][3]);
		if (status == EOF)
		{
			break;
		}
		if (user_ID == user[rows][0])
		{
			if(pass_word==user[rows][3])
			{
				user_score = user[rows][1];
			}
			while(pass_word!=user[rows][3])
			{
				printf("\nIncorrect password!");
				printf("\nTry Again: \nPassword: ");
				scanf("%d", &pass_word);
				if(pass_word==user[rows][3])
				{
					user_score = user[rows][1];
					break;
				}
			}
		}
		rows++;
	}
	//incase where user id is wrong!
	if(user_score == -1)
	{
		printf("\n\nUser not found!");
	}
	else
	{
		for(int j=0; j<rows; j++)
		{
			if(user_score<user[j][1])
			{
				other_more = other_more +1;
			}
		}
		int rank=0;
		rank = other_more+1;
		printf("\nYou rank %d on the leaderboard.", rank);
	}
	
	fclose(database);
	return user_score;
}
//RESIDENT: 1.3 benefits of recycling
void recycle_pros()
{			
printf("\nRecycling is the process of collecting and processing materials that would otherwise be thrown away as trash and turning them into new products.");
printf(" Recycling can benefit your community and the environment.");
printf("\nBelow are some benefits of Recycling:");
printf("\n\n\t1.Reduces the amount of waste sent to landfills and incinerators.");
printf("\n\n\t2.Conserves natural resources such as timber, water and minerals.");
printf("\n\n\t3.Increases economic security by tapping a domestic source of materials.");
printf("\n\n\t4.Prevents pollution by reducing the need to collect new raw materials.");
printf("\n\n\t5.Saves energy.");
printf("\n\n\t6.Supports American manufacturing and conserves valuable resources.");
printf("\n\n\t7.Helps create jobs in the recycling and manufacturing industries in the United States.");
printf("\n\nAnd so much more...");
}
//RESIDENT: 1.4 user register
void user_register(int user[][4])
{
	int new_ID = 0;
	//opens to receive the row number
	int status=0,rows=0;
	FILE *databaseA;
	databaseA = fopen("user_database.txt","r");
	
	
	while (status != EOF)
	{
		status = fscanf(databaseA, "%d %d %d %d", &user[rows][0], &user[rows][1],&user[rows][2], &user[rows][3]);
		if (status == EOF)
		{
			break;
		}
		rows++;
	}
	fclose(databaseA);
	new_ID = user[rows-1][0]+1;
	int new_score = 0;
	int home_num;
	
	//ask for the house number
	printf("\nEnter Your house number: ");
	scanf("%d", &home_num);
	
	for(int i=0;i<rows;i++)
	{
		//Check if the house number is already registered.
		if(home_num == user[i][2])
		{
		printf("\nUser is already registered from this house number!");
		printf("\nTry Again!\nHouse Number: ");
		scanf("%d", &home_num);
		i=0;
		}
		
	}
	
	int pass_word;
	//ASK TO CREATE A PASSCODE
	printf("\nEnter 4-digit password: ");
	scanf("%d", &pass_word);
	while(pass_word>9999)
	{
	printf("\nOnly 4 digit password is allowed!\nEnter 4-digit password: ");
	scanf("%d", &pass_word);
	}
	//now open file to append new user
	FILE *database;
	database = fopen("user_database.txt", "a");
	fprintf(database, "\n%d %d %d %d", new_ID, new_score, home_num, pass_word);
	fclose(database);
	
	
	
	printf("\n\nThank You for Registering!\n\n"
	"\tYour User ID is %d.", new_ID);
	
	printf("\n\tYour current recycling score is %d", new_score);
	printf("\n\tYou are registered under the house number %d", home_num);
}
//RESIDENT: 1.5 Carbon Footprint
void carbon_footprint()
{
	
double amt_waste;
int carbon_footprint;
double total_carbon_footprint;
	do
	{
		printf("\n\nDo you want to calculate your waste carbon footprint?");
		printf("\n\t1)Yes!\n\t2)No!");
		printf("\n\nYour Section: ");
		scanf("%d",&carbon_footprint);
	}while(carbon_footprint!=1 && carbon_footprint!=2);

	if (carbon_footprint==1)
	{
		printf("\n\nEstimate the amount of waste you produce each week?");
		printf("\n\nEstimate(in kg): ");
		scanf("%lf",&amt_waste);
		double USCarbonIntensity = 5011686600;
		total_carbon_footprint = (amt_waste*52)*USCarbonIntensity;
		printf("\n\nEstimated carbon footprint is %.2lfkg CO2e/yr: ",total_carbon_footprint);
		printf("\nThis score was calculated by taking your weekly waste and multiplying by 52 to get your annual waste production.");
		printf(" Then it was multiplied by a carbon intensity to get your footprint.");
		printf(" The intensity will differ greatly from country to country depending on how much waste goes to landfill, how much is incinerated and how much is recycled.");
		printf("\n\n\tBe sure to recycle to lower your carbon footprint!");
	}
}
//Resident: 1.6 How recycling scores are calculated
void score_calculation()
{
	printf("\nWaste collecters give you points based on the items you have on your recycling bin. ");
	printf("If you have only recyclabe items on your bin, you can earn a maximum of 100 points every week."); 
	printf(" On the other hand, you lose 20 points per every non-recyclable item found on your recycling bin.\n");
	printf("\n\tRecycle more and recycle right to top the leaderboard!");
}
//RESIDENT: 1.7 Questions and Concerns
void other_help()
{
	printf("If you have any other questions or concerns you can mail them to the address below");
	printf("\nMailing Address:");
	printf("\n\tU.S. Environmental Protection Agency");
	printf("\n\tOffice of Resource Conservation and Recovery");
	printf("\n\t1200 Pennsylvania Ave, NW (5306T)"); 
	printf("\n\tWashington DC 20460");
}
//Waste collector password test
int collector_verify()
{
	int keyEntered = 69420;
	int i=0;
	int access = 0;
	int attemptsLeft = 0;
	
	printf("\nEnter your passkey: ");
	scanf("%d", &keyEntered);
	while(keyEntered != 69420)
	{
			attemptsLeft = 4-i;
			printf("\n\nThe passkey does not match!\n");
			printf("\nTry Again (%d attempts left)\n", attemptsLeft);
			printf("Passkey: ");
			scanf("%d", &keyEntered);
		
		if(attemptsLeft==1)
		{
			printf("\nYou have been locked out.");
			access = 0;
			break;
		}
		i++;
	}
	if (keyEntered == 69420)
	{
		access = 1;
	}
	return access;
}
//WASTE COLLECTOR: change the recycling score
void score_edit()
{
	int userID, houseNumber, status=0,rows=0, user[999][4], both_matched=0, change=0;
	FILE *database;
	printf("\nEnter Resident Information!");
	printf("\n\tUser ID: ");
	scanf("%d", &userID);
	printf("\n\tHouse Number: ");
	scanf("%d", &houseNumber);
	
	
	
	database = fopen("user_database.txt","r");
	
	
	while (status != EOF)
	{
		status = fscanf(database, "%d %d %d %d", &user[rows][0], &user[rows][1],&user[rows][2], &user[rows][3]);
		if (status == EOF)
		{
			break;
		}
		if(userID == user[rows][0])
		{
			if(houseNumber == user[rows][2])
			{
				printf("\n\nCurrent Resident's Recycling Score: %d", user[rows][1]);
				printf("\n\tUse \"-\" before the change amount if intended to decrease the current score.");
				printf("\n\nEnter the change: ");
				scanf("%d", &change);
				if((user[rows][1]+change)<0)
				{
					printf("\nThe score can not be negative.");
					both_matched = 1;
				}
				else
				{
				user[rows][1] = user[rows][1]+change;
				printf("The new score is %d", user[rows][1]);
				both_matched = 1;
				}
			}
			else
			{
				printf("\n\nUser ID does not match the House Number entered!\nTRY AGAIN!\n");
				printf("\n\tUser ID: ");
				scanf("%d", &userID);
				printf("\n\tHouse Number: ");
				scanf("%d", &houseNumber);	
				rows = -1;
			}
		}
		rows++;
	}
	fclose(database);
	
	FILE *databaseW;
	databaseW = fopen("user_database.txt","w");
	for(int i=0;i<rows;i++)
	{
	fprintf(databaseW,"\n%d %d %d %d", user[i][0], user[i][1], user[i][2], user[i][3]);
	}
	fclose(databaseW);
	if (both_matched != 1)
	{
		printf("\nUser ID not valid!");
	}
fclose(database);
}

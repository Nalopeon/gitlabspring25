//contributors
//GP
//Jovanny Gonzalez
//Joel Castro
//Ryan A
//Nicole Brooks
//Yoonhong Min
// Jessenia Hernandez Mora
//Gerard McCallion

//Bryant Garcia
// Angela Jovanovic

//jessie flores


// Angela Jovanovic
//Josephine Kingslee

//Fatoma Babonjo


//Santiago Tecuanhuey Garcia


//Alex Pham


//Jared Hernandez


// Omar Salem

// Stanley Navarrete

//Victor Gonzalez Bustillo

// Nanu Panchamurthy

// carlos acevedo

// Raymond Lee

//Jesse Navarro
// Aziz Haouchine


#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

//place function prototypes here

void FarStarTrader(void);
void theGambitsFortune(int itemCounts[], int numInventory);



int main(int argc, char *argv[])
{
	int choice = 0;
	char name[30] = "bob";
	srand(time(NULL));

	printf("Please enter your name: ");
	scanf("%s",name);
	printf("Hello %s welcome to the RPG Game!\n",name);
	while(choice != 99)
	{
		puts("You find yourself in a dark room and you are not sure how you got here.");
		puts("As you look around you see the room has 55 doors, each labeled with a number.");
		puts("The room starts filling with water and you must choose a door to open or you will likely drown. you may quit anytime by selecting option 99.");
		puts("What door do you choose?");
		scanf("%d",&choice);
		switch(choice)
		{

		case 11:
		{
			puts("room11");
			FarStarTrader();

			const char *inventory[] =
			{
				"Item 1: Ambrosia of Eternity",
				"Item 2: The Sword of Damnation",
				"Item 3: Heavy Armour of Unencumbrance",
				"Item 4: The Bow of Immense Accuracy",
				"Item 5: Rubber Duck"
			};

			char name[] = "Archemedes";
			int choice;
			int itemCounts[5] = {0};
			int playerChoice;
			int numInventory = sizeof(inventory) / sizeof(inventory[0]);
			int playerLuck;
			srand(time(0));

			printf("You enter a trading post full of weapons and gear from a far-off land.\n");
			printf("A merchant who's face is scarred, tired, and beaten looks at you. \n");
			printf("%s: Welcome friend to the Far Star Trading Post. \n", name);
			printf("I have just the thing you need for your adventures.\n");
			printf("You stand there, deciding on whether you want to stay or leave.\n");

			do
			{
				printf("Press 1 to follow the merchant, press 2 to leave: ");
				scanf("%d", &choice);

				if (choice == 1)
				{
					printf("%s: I have many wares for you, each unique in their own ways. Pick one!\n",name);

					while(1)
					{
						printf("Available Items:\n");

						for (int i = 0; i< numInventory; i++)
						{
							printf("%d. %s\n", i + 1, inventory[i]);
						}
						printf("0. Exit\n");
						printf("%s: Choose an item by it's number (1-5) or 0 to exit: ", name);
						scanf("%d", &playerChoice);

						if (playerChoice == 0)
						{
							printf("Exiting the shop.\n");
							break;
						}
						else if (playerChoice >0 && playerChoice <= numInventory)
						{
							itemCounts[playerChoice - 1]++;
							int randomBonus = rand() % 100 + 1;
							printf("Ah, I see you decided on %s! Great choice!\n You now have %d in your inventory.\n",
							       inventory[playerChoice - 1], itemCounts[playerChoice -1]);
							printf("You also received a random bonus of %d gold coins!\n", randomBonus);

							printf("Would you like to test your luck with the Gambit's Fortune?\n");
							printf("Press 1 to test your luck, or 2 to skip: \n");
							scanf("%d", &playerLuck);

							if (playerLuck == 1)
							{

								printf("You chose to try your luck.\n");
								theGambitsFortune(itemCounts, numInventory);

							}
							else if (playerLuck == 2)
							{
								printf("You decided not to test your luck");
							}
							else
							{
								printf("Invalid option try again");
							}
						}
						else if (choice == 2)
						{
							printf("You decided to leave the trading post.\n");
						}
						else
						{
							printf("Invalid choice! Pick between the two options.\n");
						}

					}
				}

			} while (choice!=2);
			return 0;
		}
		}
	}
}

void FarStarTrader(void)
{
	printf("cscuser11\n");
}

void theGambitsFortune(int itemCounts[], int numInventory)
{
	const char *fortunes[] = {
		"If Lady Fortune smiles upon you, you will be rewarded with riches.",
		"Beware traveler, this may hold a dangerous outcome or an opportunity for fortune.",
		"Your next decision could bring either suffering or reward!",
		"May generosity favor you!"
	};

	int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
	int randomIndex = rand() % numFortunes;

	printf("\nBefore you leave, Archemedes says:\n");
	printf("\"%s\"\n\n", fortunes[randomIndex]);

	int luckRoll = rand() % 2;

	if (luckRoll == 1) {
		int bonusGold = rand() % 200 + 50;
		printf("Lady luck smiles upon thee, traveler! Take your %d gold coins!\n", bonusGold);
	} else {
		printf("Looks like Lady Luck has abandoned you! You lose all items in your inventory!\n");

		for (int i = 0; i < numInventory; i++) {
			itemCounts[i] = 0;  // Correct: Now `itemCounts` is properly recognized as an array
		}
	}
	printf("Your luck has been tested. Hopefully, you have succeeded!\n");
}

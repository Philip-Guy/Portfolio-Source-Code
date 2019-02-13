/*	Philip Guy
	CGP400 Assignment 1
	SD1_3
	09/11/2014
*/

//Header files:
#include <conio.h> //Provides console input/output.
#include <stdio.h> //Allows inputs/outputs and operates with physical devices such as keyboards.
#include <stdlib.h> //Allows random number generation.
#include <time.h> //Used in random number generation, defines 'NULL'.
using namespace std;
  
	enum eMenu {
		eInstructions = 1,
		ePlayGame,
		eHighScores,
		eExit
	}; //enumeration for the user selection of instructions, gameplay, highscores or exiting the console.

   enum eActions {
		eSTANDARD_ATTACK = 1,
		eHEAVY_ATTACK,
		eCOUNTER_ATTACK,
		eUSE_AMULET,
		eDEFEND
	}; //enumeration for the selection of actions, from numbers 1 to 5.

   enum eSecond_Action {
		eSTANDARD_ATTACK_2 = 1,
		eHEAVY_ATTACK_2,
		eCOUNTER_ATTACK_2,
		eUSE_AMULET_2,
		eDEFEND_2
   }; //enumeration for the second selection of actions when the user chooses to use action 4 'Use Amulet' which grants a second action that turn.

   int main()

   {

	   int menu;
	   int high_score = 100;
	   int action;
	   int second_action;

	   int monster_action;
	   int second_monster_action;

	   int turn = 1; //Variable for the turn counter.
	   int player_hitpoints = 100; //Variable for player hitpoints.
	   int monster_hitpoints = 100; //Variable for monster hitpoints.

	   double standard_attack_damage = 10;
	   double heavy_attack_damage = 20;
	   double counter_attack_damage = 6;

	   double monster_standard_attack_damage = 10;
	   double monster_heavy_attack_damage = 20;
	   double monster_counter_attack_damage = 6;

	   int standard_attack_chance = 0;
	   int heavy_attack_chance = 0;
	   int counter_attack_chance = 0;

	   int monster_standard_attack_chance = 0;
	   int monster_heavy_attack_chance = 0;
	   int monster_counter_attack_chance = 0;

	   int attack_power_1 = 20;
	   int attack_power_2 = 10;
	   int attack_power_3 = 8;
	   int attack_power_4 = 1;
	   int attack_power_5 = 10;

	   int monster_attack_power_1 = 20;
	   int monster_attack_power_2 = 10;
	   int monster_attack_power_3 = 8;
	   int monster_attack_power_4 = 1;
	   int monster_attack_power_5 = 10;

	   srand(time(NULL)); //Initialisation for the random number generator, passed as seed.

	   system("cls"); //system("cls") clears the console of any text that was previously visible.
	   printf("Philip Guy CGP400 Assignment 1 - Turn-Based Strategy Game\n");
	   printf("[1] Instructions\n");
	   printf("[2] Play Game\n");
	   printf("[3] Highscore\n");
	   printf("[4] Exit\n");
	   scanf_s("%d", &menu); //Allows the user to input an decimal integer (1-9) which is stored as variable 'menu'.

	   switch (menu) //switch statement to determine which option the user chooses.
	   {

	   case eInstructions:
		   menu = 1;
		   system("cls"); //Clears text from the menu.
		   printf("\nInstructions:\n\n"); //Prints a series of instructions.
		   printf("1) You and your enemy begin with 100 hitpoints, and to win you must deplete the enemy's hitpoints to 0 before your own hitpoints reach 0!\n");
		   printf("2) You will both select one action per turn, you will choose your action before the enemy chooses its.\n");
		   printf("3) You should use numbers 1 to 5 on the keypad to select your action and press enter to confirm.\n\n");
		   printf("The Actions:\n\n"); //Prints descriptions of each action, with hit chance, damage and any other special attributes of that action.

		   printf("Action 1: 'Normal Attack' is a standard strike on the enemy, with an 80% chance to hit 10 hitpoits of damage\n\n");
		   printf("Action 2: 'Heavy Attack' is a hard strike on the enemy, there is a 50% chance to hit 20 hitpoints of damage\n\n");
		   printf("Action 3: 'Counter Attack' allows the enemy to attack first as you attempt to dodge the incoming attack (Reducing the enemy's chance of hitting by 20%) and then immediately launching a counter attack, with a 65% chance to hit with 6 hitpoints damage\n\n");
		   printf("Action 4: 'Use Amulet' increases all damage by 1.5 times the original value, but has ONE use only. Using this action does not use a turn to activate so you will immediately be able to select another action\n\n");
		   printf("Action 5: 'Defend' regain 5 hitpoints, however you cannot exceed the starting health and you cannot attack this turn. Also reduces enemy's chance of hitting by 30%\n\n");
		   printf("Enter any number to return to the menu.\n");
		   scanf_s("%d", &menu); //Allows the user to return from the instructions screen back to the menu.

		   return main(); //Returns to int main()
		   break; //break; stops the program from executing any other cases within the switch statement.

	   case ePlayGame:
		   menu = 2;
		   system("cls");
		   printf("The Battle has begun!\n\n");

		   for (turn = 1; turn < 100; turn++) //Main function is to allow incrementation of variable 'turn' after both the player and the monster have taken their turns.
		   {

			   do //A do-while loop which allows the program to loop until a condition is met.
			   {
				   printf("Turn %d\n\n", turn); //prints information for the battle, such as turn number and action details.
				   printf("It is your turn, select an action from 1-5:\n");
				   printf("Action 1: 'Normal Attack' | 80 percent hit chance | 10 damage | %d uses\n", attack_power_1);
				   printf("Action 2: 'Heavy Attack'  | 50 percent hit chance | 20 damage | %d uses\n", attack_power_2);
				   printf("Action 3: 'Counter Attack'| 65 percent hit chance | 6 damage  | %d uses\n", attack_power_3);
				   printf("Action 4: 'Use Amulet'    | 1.5 damage multiplier | %d use only\n", attack_power_4);
				   printf("Action 5: 'Defend'        | Regain 5 hitpoints    | Reduces enemy hit chance by 30 percent | %d uses\n", attack_power_5);
				   scanf_s("%d", &action); //Allows the user to select a number from 1-5 that chooses their action.
				   system("cls");

				   switch (action) //Nested switch statement for the execution of the chosen action.
				   {

				   case eSTANDARD_ATTACK:

					   if (attack_power_1 > 0) //If statement allows the action to be used as long as there is not 0 attack power.
					   {
						   action = 1;
						   attack_power_1--; //decrements the attack power by 1.
						   standard_attack_chance = rand() % 100 + 1; //Random number generation for the attack chance from 1-100.

						   if ((standard_attack_chance >= 1) && (standard_attack_chance <= 80)) //Nested if statement determines whether the attack hits or misses.
						   {
							   printf("Attack successful! You damage the monster for 10 hitpoints.\n");
							   monster_hitpoints = (monster_hitpoints - standard_attack_damage);
							   break;
						   }
						   else //The condition if the 80% hit chance is not met.
						   {
							   printf("Attack failed, the monster takes no damage!\n");
							   break;
						   }

					   }
					   else //The condition if the player has 0 attack power for this action.
					   {
						   printf("You have run out of attack power, try a different attack!\n");
						   scanf_s("%d", &action);//Prompts the user to choose another move, so a turn is not used up.
						   break;
					   }

				   case eHEAVY_ATTACK:

					   if (attack_power_2 > 0) //If statement for whether there is enough attack power to execute the action.
					   {
						   action = 2;
						   attack_power_2--; //Decrements the attack power for this action by 1.
						  //heavy_attack_chance = rand() % 100 + 1; //Generates a random number for this action.

						   if ((heavy_attack_chance >= 1) && (heavy_attack_chance <= 50)) //Nested if statement determines whether the attack hits or misses.
						   {
							   printf("Attack successful! You damage the monster for 20 hitpoints.\n");
							   monster_hitpoints = (monster_hitpoints - heavy_attack_damage);
							   break;
						   }
						   else //The condition if the 50% hit chance is not met.
						   {
							   printf("Attack failed, the monster takes no damage!\n");
							   break;
						   }

					   }
					   else
					   {
						   printf("You have run out of attack power, try a different attack!\n");
						   scanf_s("%d", &action);
						   break;
					   }

				   case eCOUNTER_ATTACK:

					   if (attack_power_3 > 0)
					   {
						   action = 3;
						   attack_power_3--;
						   counter_attack_chance = rand() % 100 + 1; //Generates random number from 1-100.

						   if ((counter_attack_chance >= 1) && (counter_attack_chance <= 65))
						   {
							   printf("The monster attacks first!\n");
							   printf("Counter Attack successful! You damage the monster for 6 hitpoints and reduce their attack chance by 20 percent\n");
							   monster_standard_attack_chance = (monster_standard_attack_chance + 20); //Increases the enemy's attack chance variable and therefore decreasing chance of a successful hit for each of the enemy's damaging actions.
							   monster_heavy_attack_chance = (monster_heavy_attack_chance + 20);
							   monster_counter_attack_chance = (monster_counter_attack_chance + 20);
							   monster_hitpoints = (monster_hitpoints - counter_attack_damage); //Updates the enemy's hitpoints for the damage from counter attack.
							   break;
						   }
						   else //Condition if the hit chance is not met.
						   {
							   printf("Attack failed, the monster takes no damage!\n");
							   break;
						   }
					   }
					   else //Condition if there is not enough attack power.				   
					   {
						   printf("You have run out of attack power, try a different attack!\n");
						   scanf_s("%d", &action);
						   break;
					   }

				   case eUSE_AMULET:

					   if (attack_power_4 > 0) //Fufills the function of this action only having one use.
					   {
						   action = 4;
						   attack_power_4--;
						   turn--; //Effectively allows the user to make two actions in the same turn as the variable 'turn' is decremented by 1 and is executed before the monster chooses it's move.
						   printf("Use Amulet is active! Please select another action\n");
						   scanf_s("%d", &second_action); //Stores user input of their second action into variable 'second_action'.
					   }
					   else
					   {
						   printf("You have run out of attack power, try a different attack!\n");
						   scanf_s("%d", &action);
						   break;
					   }

					   switch (second_action) //Another nested switch statement for the second action when the player uses 'Use Amulet'
					   {

					   case eSTANDARD_ATTACK_2:
						   second_action = 1;

						   if (attack_power_1 > 0) //Ensures that even though a turn is not used, one 'attack power' is.
						   {
							   standard_attack_chance = rand() % 100 + 1;

							   if ((standard_attack_chance >= 1) && (standard_attack_chance <= 80))
							   {
								   printf("Attack successful! You damage the monster for 15 hitpoints.\n");
								   monster_hitpoints = (monster_hitpoints - (standard_attack_damage * 1.5)); //Applies the damage multiplier effect of action 'Use Amulet'.
								   break;
							   }
							   else
							   {
								   printf("Attack failed, the monster takes no damage!\n");
								   break;
							   }

						   }
						   else
						   {
							   printf("You have run out of attack power, try a different attack!\n");
							   scanf_s("%d", &second_action);
							   break;
						   }

					   case eHEAVY_ATTACK_2:
						   second_action = 2;

						   if (attack_power_2 > 0)
						   {
							   heavy_attack_chance = rand() % 100 + 1;

							   if ((heavy_attack_chance >= 1) && (heavy_attack_chance <= 50));
							   {
								   printf("Attack successful! You damage the monster for 30 hitpoints.\n");
								   monster_hitpoints = (monster_hitpoints - (heavy_attack_damage * 1.5)); //Applies the damage multiplier.
								   break;
							   }

							   if ((heavy_attack_chance > 5) && (heavy_attack_chance <= 10))
							   {
								   printf("Attack failed, the monster takes no damage!\n");
								   break;
							   }

						   }
						   else
						   {
							   printf("You have run out of attack power, try a different attack!\n");
							   scanf_s("%d", &second_action);
							   break;
						   }

					   case eCOUNTER_ATTACK_2:
						   second_action = 3;

						   if (attack_power_3 > 0)
						   {
							   counter_attack_chance = rand() % 100 + 1;

							   if ((counter_attack_chance >= 1) && (counter_attack_chance <= 65))
							   {
								   printf("The monster attacks first!\n");
								   printf("Counter Attack successful! You damage the monster for 9 hitpoints and reduce their attack chance by 20 percent\n");
								   monster_standard_attack_chance = (monster_standard_attack_chance - 20);
								   monster_heavy_attack_chance = (monster_heavy_attack_chance - 20);
								   monster_counter_attack_chance = (monster_counter_attack_chance - 20);
								   monster_hitpoints = (monster_hitpoints - (counter_attack_damage * 1.5));
								   break;
							   }
							   else
							   {
								   printf("Attack failed, the monster takes no damage!\n");
								   break;
							   }

						   }
						   else
						   {
							   printf("You have run out of attack power, try a different attack!\n");
							   scanf_s("%d", &second_action);
							   break;
						   }

					   case eUSE_AMULET_2:
						   second_action = 4;

						   if (attack_power_4 < 1) //if statement for if the player attempts to use this ability again.
						   {
							   printf("You cannot use action 'Use Amulet' more than once! Please try a different action.\n");
							   scanf_s("%d", &second_action); //Allows the user to enter another action without ending the the turn.
							   break;
						   }

					   case eDEFEND_2:
						   second_action = 5;
						   attack_power_5--;
						   if (attack_power_5 > 1) //Ensures there is enough attack power.
						   {
							   action = 5;

							   if (player_hitpoints <= 95) //Nested if statement to check if the player has lost at least 5 hitpoints
							   {
								   player_hitpoints = (player_hitpoints + 5);
								   printf("You regenerate 5 hitpoints and reduce the enemy's chance of hitting by 30 percent!\n");
								   monster_standard_attack_chance = (monster_standard_attack_chance + 30);
								   monster_heavy_attack_chance = (monster_heavy_attack_chance + 30);
								   monster_counter_attack_chance = (monster_counter_attack_chance + 30);
								   break;
							   }
							   else
							   {
								   printf("You cannot use this action if you have not lost at least 5 hitpoints, please try another action!");
								   scanf_s("%d", &second_action);
								   break;
							   }

						   }
						   else
						   {
							   printf("You have run out of attack power, try a different attack!\n");
							   scanf_s("%d", &second_action); //Allows the user to enter another action without ending the the turn.
							   break;
						   }

					   default: //the default case if the user does not enter a number from 1 to 5.
						   if (action != 1 && 2 && 3 && 4 && 5);
						   {
							   turn--; //Offsets the turn incrementation further along the code.
							   system("cls");
							   printf("Error! Invalid number entered, please enter a number from 1 to 5.\n");
							   break;
						   }
					}

				   case eDEFEND:

					   if (attack_power_5 > 1)
					   {
						   action = 5;
						   attack_power_5--;

						   if (player_hitpoints <= 95)
						   {
							   player_hitpoints = (player_hitpoints + 5); //Increases the player's hitpoints by 5.
							   printf("You regenerate 5 hitpoints and reduce the enemy's chance of hitting by 30 percent!\n");
							   monster_standard_attack_chance = (monster_standard_attack_chance + 30); //Increases the enemy's attack chance variables for all damaging actions, therefore decreasing it's chance of hitting.
							   monster_heavy_attack_chance = (monster_heavy_attack_chance + 30);
							   monster_counter_attack_chance = (monster_counter_attack_chance + 30);
							   break;
						   }
						   else
						   {
							   printf("You cannot use this action if you have not lost at least 5 hitpoints, please try another action!");
							   scanf_s("%d", &action);
							   break;
						   }
					   }

					   else
					   {
						   printf("You have run out of attack power, try a different attack!\n");
						   scanf_s("%d", &action); //Allows the user to enter another action without ending the the turn.
						   break;
					   }

					   
				   default: //the default case if the user does not enter a number from 1 to 5.
					   if (action != 1 && 2 && 3 && 4 && 5);
					   {
						   turn--; //Offsets the turn incrementation further along the code.
						   system("cls");
						   printf("Error! Invalid number entered, please enter a number from 1 to 5.\n");
						   break;
					   }
				   }

				   monster_action = rand() % 5 + 1; //Random number generator for the monster AI - randomly chooses a number from 1 to 5.

				   switch (monster_action) //Switch statement for the generated number of 'monster_action'.

				   {

				   case eSTANDARD_ATTACK:

					   if (monster_attack_power_1 > 1) //If statement ensures the monster has enough attack_power for this action.
					   {
						   monster_action = 1;
						   monster_standard_attack_chance = rand() % 100 + 1; //Generates a random number from 1 to 100 for the hit chance.

						   if ((monster_standard_attack_chance >= 1) && (monster_standard_attack_chance <= 80)) //Nested if statement for if the hit is successful.
						   {

							   printf("The monster's attack was successful! You are damaged for 10 hitpoints.\n");
							   player_hitpoints = (player_hitpoints - monster_standard_attack_damage);  //Decreases the player's hitpoints by the monster's actions damage.
							   break;
						   }
						   else
						   {
							   printf("The monster's attack failed, you take no damage!\n");
							   break;
						   }

					   }

					   if (monster_attack_power_1 < 1)
					   {
						   monster_action = rand() % 5 + 1; //Generates a new number if there is not any attack power left, will continue to do so until a valid action is chosen.
						   break;
					   }

				   case eHEAVY_ATTACK:

					   if (monster_attack_power_2 > 1)
					   {
						   monster_action = 2;
						   monster_heavy_attack_chance = rand() % 100 + 1;

						   if ((monster_heavy_attack_chance >= 1) && (monster_heavy_attack_chance <= 50));
						   {
							   printf("The monster's attack was successful! You are damaged for 20 hitpoints.\n");
							   player_hitpoints = (player_hitpoints - monster_heavy_attack_damage);
							   break;
						   }
						   if ((monster_heavy_attack_chance > 5) && (monster_heavy_attack_chance <= 10))
						   {
							   printf("The monster's attack failed, you take no damage!\n");
							   break;
						   }

					   }
					   else
					   {
						   monster_action = rand() % 5 + 1;
						   break;
					   }

				   case eCOUNTER_ATTACK:
					   monster_action = 3;
					   monster_counter_attack_chance = rand() % 100 + 1;

					   if (monster_attack_power_3 > 1)
					   {

						   if ((monster_counter_attack_chance >= 1) && (monster_counter_attack_chance <= 65))
						   {
							   printf("The player attacks first!\n");
							   printf("The monster's Counter Attack was successful! You are damaged for 6 hitpoints and your hit chance is reduced by 20 percent\n");
							   standard_attack_chance = (standard_attack_chance + 20); // Increases the player's attack chance for each damaging action, therefore decreasing their chance of hitting.
							   heavy_attack_chance = (heavy_attack_chance + 20);
							   counter_attack_chance = (counter_attack_chance + 20);
							   player_hitpoints = (player_hitpoints - monster_counter_attack_damage); //Reduces the player's hitpoints for the damage value of counter attack.
							   break;
						   }
						   else
						   {
							   printf("The monster's attack failed, you take no damage!\n");
							   break;
						   }

					   }
					   else
					   {
						   monster_action = rand() % 5 + 1;
						   break;
					   }

				   case eUSE_AMULET:

					   if (monster_attack_power_4 > 1) //Ensures the monster cannot use this ability more than once.
					   {
						   monster_action = 4;
						   monster_attack_power_4--; //Decrements attack power for this action.
						   turn--; //Decrements the turn value.

						   printf("The Monster uses 'Use Amulet' and selects another action!\n");
						   second_monster_action = rand() % 5 + 1;


						   switch (second_monster_action) //Nested switch statement for the monster's second action if it chooses 'Use Amulet'.
						   {

						   case eSTANDARD_ATTACK_2:

							   if (monster_attack_power_1 > 1)
							   {
								   second_monster_action = 1;
								   monster_standard_attack_chance = rand() % 100 + 1;

								   if ((monster_standard_attack_chance >= 1) && (monster_standard_attack_chance <= 80))
								   {

									   printf("The monster's attack was successful! You are damaged for 15 hitpoints.\n");
									   player_hitpoints = (player_hitpoints - (monster_standard_attack_damage * 1.5));
									   break;
								   }
								   else
								   {
									   printf("The monster's attack failed, you take no damage!\n");
									   break;
								   }

							   }
							   else
							   {
								   second_monster_action = rand() % 5 + 1;
								   break;
							   }

						   case eHEAVY_ATTACK_2:

							   if (monster_attack_power_2 > 1)
							   {
								   second_monster_action = 2;
								   monster_heavy_attack_chance = rand() % 100 + 1;

								   if ((monster_heavy_attack_chance >= 1) && (monster_heavy_attack_chance <= 50));
								   {
									   printf("The monster's attack was successful! You are damaged for 30 hitpoints.\n");
									   player_hitpoints = (player_hitpoints - (monster_heavy_attack_damage * 1.5));
									   break;
								   }
								   if ((monster_heavy_attack_chance > 50) && (monster_heavy_attack_chance <= 100))
								   {
									   printf("The monster's attack failed, you take no damage!\n");
									   break;
								   }

							   }
							   else
							   {
								   second_monster_action = rand() % 5 + 1;
								   break;
							   }

						   case eCOUNTER_ATTACK_2:

							   if (monster_attack_power_3)
							   {
								   second_monster_action = 3;
								   monster_counter_attack_chance = rand() % 100 + 1;

								   if ((monster_counter_attack_chance >= 1) && (monster_counter_attack_chance <= 65))
								   {
									   printf("The player attacks first!\n");
									   printf("The monster's Counter Attack was successful! You are damaged for 9 hitpoints and your hit chance is reduced by 20 percent\n");
									   standard_attack_chance = (standard_attack_chance + 20);
									   heavy_attack_chance = (heavy_attack_chance + 20);
									   counter_attack_chance = (counter_attack_chance + 20);
									   player_hitpoints = (player_hitpoints - (monster_counter_attack_damage * 1.5));
									   break;
								   }
								   else
								   {
									   printf("The monster's attack failed, you take no damage!\n");
									   break;
								   }

							   }
							   else
							   {
								   second_monster_action = rand() % 5 + 1;
								   break;
							   }


							   if ((action = 3) && (monster_action = 3)) //If statement for scenarios that both the player and the monster use 'Counter Attack', currently not fully functional.
							   {
								   printf("You both attempt a counter attack.. but nobody attacks!\n");
								   turn++;
								   break;
							   }

						   case eUSE_AMULET_2:

							   second_monster_action = 4;

							   if (second_action = 4)
							   {
								   printf("The monster attempts 'Use Amulet' but cannot use it again! Instead it attempts a another action.\n");
								   second_monster_action = rand() % 5 + 1;
								   break;
							   }

						   case eDEFEND_2:

							   if (monster_attack_power_5 > 1)
							   {
								   second_monster_action = 5;

								   if (monster_hitpoints <= 95)
								   {
									   monster_hitpoints = (monster_hitpoints + 5);
									   printf("The monster regenerates 5 hitpoints and reduces your hit chance by 30 percent!\n");
									   standard_attack_chance = (standard_attack_chance + 30); //Increases the player's attack chance for each damaging ability by 30.
									   heavy_attack_chance = (heavy_attack_chance + 30);
									   counter_attack_chance = (counter_attack_chance + 30);
									   break;
								   }
								   else
								   {
									   monster_hitpoints = (monster_hitpoints + 0); //The condition if the monster has more than 95 hitpoints.
									   break;
								   }

							   }
							   else
							   {
								   second_monster_action = rand() % 5 + 1;
								   break;
							   }

							   break;
						   }

					   }
					   else
					   {
						   second_monster_action = rand() % 5 + 1;
						   break;
					   }

				   case eDEFEND:
					   if (monster_attack_power_5 > 1)
					   {
						   monster_action = 5;
						   if (monster_hitpoints <= 95)
						   {
							   monster_hitpoints = (monster_hitpoints + 5);
							   printf("The monster regenerates 5 hitpoints and reduces your hit chance by 30 percent!\n");
							   standard_attack_chance = (standard_attack_chance + 30);
							   heavy_attack_chance = (heavy_attack_chance + 30);
							   counter_attack_chance = (counter_attack_chance + 30);
							   break;
						   }
						   else
						   {
							   monster_hitpoints = (monster_hitpoints + 0);
							   break;
						   }

					   }
					   else
					   {
						   monster_action = rand() % 5 + 1;
						   break;
					   }
				   }

				   printf("Players Health: %d\n", player_hitpoints); //Displays the current hitpoints of both the player and the monster after each turn is executed.
				   printf("Monsters Health: %d\n", monster_hitpoints);
				   turn++; //Increments the turn by 1.

			   }

			   while ((player_hitpoints > 1) && (monster_hitpoints > 1)); //The condition of the 'do-while' loop that ends the game if either the player's or the monster's hitpoints is 0.
	  
		   if (player_hitpoints < 0) //if statement that outputs to the player whether they've won or lost depending on who's hitpoints is 0.
		   {
			   printf("You lose!\n");
		   }
		   else if (monster_hitpoints < 0)
		   {
			   printf("You win!\n");
		   }

		   if (turn < high_score)
		   {
			   printf("New Highscore!");
			   high_score = turn;
			   printf("%d ", high_score);
		   }

		   printf("Press any number to return to the main menu\n"); //Allows the user to return to the main menu after playing a game.
		   scanf_s("%d", &menu); //Allows the user to input a number, returning them to the menu.
		   return main();
		   system("cls"); //Clears the console of all text from the gameplay so that the menu text is all that is present on the console.
		   break;
	   }

	   case eHighScores: //case to display highscores
		   menu = 3;
		   system("cls");
		   printf("Highscores\n\n");
		   printf("1) %d\n", high_score);
		   printf("Enter any number to return to the menu.\n");
		   scanf_s("%d", &menu);
		   return main();
		   break; 

	   case eExit: //case for if the user chooses to exit from the console.
		   menu = 4;
		   exit(0); //exits the console immediately.
		   break;

	   default: //default case if the user enters a number that is not 1, 2 or 3.
		   menu != 1 || 2 || 3 || 4;
		   system("cls");
		   printf("Error! invalid number entered, press any number to try again\n\n");
		   scanf_s("%d", &menu); //Allows the user to enter a number then returns to the menu.
		   return main();
		   break;

		   _getch(); //Used to pause the program so that while testing I can see what is being displayed before the program exits.
		   return 0;
	   }
   }
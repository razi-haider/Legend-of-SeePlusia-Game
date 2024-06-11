#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 20, nCrystalsFound = 0; // Variable to store apples and crystals. Initially with 20 apples and 0 crystals.
string gameState  = "Running";// There are three game states. Won, Lost and Running. Initially game state is ruuning.
string currentState = "Enchanted_Forest"; // Current state tells the position of you. Initially current state is Enchanted Forest.

int crystal_of_Marsh = 0, crystal_of_Hill = 0, crystal_of_Tunnel = 0, crystal_of_Swamps = 0; // Initiazing crystals in the map

// functions to find crystals.
void crystalOfMarsh(string direction){//function to find crytal at Marsh of Undead.
	if (crystal_of_Marsh == 0){
		nCrystalsFound +=1;
 		crystal_of_Marsh += 1;
	}
}
void crystalOfHill(string direction){//function to find crystal at Werewolf Hill.
	if (crystal_of_Hill == 0){
		nCrystalsFound +=1;
 		crystal_of_Hill += 1;
	}
}
void crystalOfTunnel(string direction){//function to find crystal at Eisten Tunnel.
	if (crystal_of_Tunnel == 0){
		nCrystalsFound +=1;
 		crystal_of_Tunnel += 1;
	}
}
void crystalOfSwamps(string direction){//function to find crystal at Swamps of Despair.
	if (crystal_of_Swamps == 0){
		nCrystalsFound +=1;
 		crystal_of_Swamps += 1;
	}
}

// functions for "gamestate = won" or functions for gamestate = "lost"
void wonState(string direction){// function when game has been won
	if (direction == "East"){ //When Right Arrow is pressed
		cout<<"You have already won the game."<<endl;
	}
	else if (direction == "West"){//When Left Arrow is pressed
		cout<<"You have already won the game."<<endl;
	}
	else if (direction == "North"){
		cout<<"You have already won the game."<<endl;
	}
	else if (direction == "South"){
		cout<<"You have already won the game."<<endl;
	}
}
void lostState(string direction){// function when game has been lost
	if (direction == "East"){//When Right Arrow is pressed
		cout<<"You have already lost the game."<<endl;
	}
	else if (direction == "West"){//When Left Arrow is pressed
		cout<<"You have already lost the game."<<endl;
	}
	else if (direction == "North"){
		cout<<"You have already lost the game."<<endl;
	}
	else if (direction == "South"){
		cout<<"You have already lost the game."<<endl;
	}
}

// functions to make coding efficient.
void invalidMove(string direction){
	applesLeft -=1;
	gameState = "Running";
	cout<<"Invalid Move"<<endl;
}
void starvationWithInvalidMove(string direction){
	applesLeft -=1;
	gameState = "Lost";
	cout<<"Invalid Move and you have died of starvation."<<endl;
}
void dieOfStarvation(string direction){
	applesLeft -= applesLeft;
	gameState = "Lost";
	cout<<"You have arrived at " <<  currentState << " but you have died of starvation."<<endl;
}
void validMove(string direction){
	gameState = "Running";
	cout<<"You have arrived at " << currentState << "."<<endl;
}
void won(string direction){
	currentState = "Castle";
	gameState = "Won";
	cout<<"You have won."<<endl;
}

// functions for different directions when warrior's current state is Enchanted Forest.
void eastForest(string direction){// funcion to move towards east of Enchated Forest.
	moveEast();
	applesLeft -=1;
	currentState = "Sands_of_Quick";
	gameState = "Lost";
	cout<<"You have lost the game."<<endl;
}
void westForest(string direction){// funcion to move towards west of Enchated Forest.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}	
}
void northForest(string direction){// funcion to move towards north of Enchated Forest.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void southForest(string direction){// funcion to move towards west of Enchated Forest.
	if (applesLeft > 3){
		moveSouth();
		applesLeft -=3;
		currentState = "Wampire_Cove";
		validMove(direction);
	}
	else if (applesLeft == 3){
		moveSouth();
		currentState = "Wampire_Cove";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 2 ){
		invalidMove(direction);

	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void enchantedForest(string direction){// function when warrior is at Enchanted Forest.
	if (direction == "East"){//When Right Arrow is pressed
		eastForest(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westForest(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northForest(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southForest(direction);
	}
}

// functions for different directions when warrior's current state is Wampire Cove.
void eastCove(string direction){// funcion to move towards east of Wampire Cove.
	crystalOfMarsh(direction);
	if (applesLeft > 1){
		moveEast();
		currentState = "Marsh_of_Undead";
		applesLeft -=1;
		validMove(direction);
	}
	else if (applesLeft == 1){
		moveEast();
		currentState = "Marsh_of_Undead";
		dieOfStarvation(direction);
	}
}
void westCove(string direction){// funcion to move towards west of Wampire Cove.
	crystalOfSwamps(direction);
	if (applesLeft > 1){
		moveWest();
		currentState = "Swamps_of_Despair";
		applesLeft -=1;
		validMove(direction);
	}
	else if (applesLeft == 1){
		moveWest();
		currentState = "Swamps_of_Despair";
		dieOfStarvation(direction);
	}	
}
void northCove(string direction){// funcion to move towards north of Wampire Cove.
	if (applesLeft > 3){
		moveNorth();
		applesLeft -=3;
		currentState = "Enchanted_Forest";
		validMove(direction);
	}
	else if (applesLeft == 3){
		moveNorth();
		currentState = "Enchanted_Forest";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 2 ){
		invalidMove(direction);
	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void southCove(string direction){// funcion to move towards south of Wampire Cove.
	if (applesLeft > 3){
		moveSouth();
		crystalOfHill(direction);
		applesLeft -=3;
		currentState = "Werewolf_Hill";
		validMove(direction);
	}
	else if (applesLeft == 3){
		moveSouth();
		crystalOfHill(direction);
		currentState = "Werewolf_Hill";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 2 ){
		invalidMove(direction);
	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void wampireCove(string direction){// function when warrior is at Wampire Cove.
	if (direction == "East"){//When Right Arrow is pressed
		eastCove(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westCove(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northCove(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southCove(direction);
	}
}

// functions for different directions when warrior's current state is Marsh of Undead.
void eastMarsh(string direction){// funcion to move towards east of Marsh of Undead.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void westMarsh(string direction){// funcion to move towards west of Marsh of Undead.
	if (applesLeft > 1){
		moveWest();
		currentState = "Wampire_Cove";
		applesLeft -=1;
		validMove(direction);
	}
	else if (applesLeft == 1){
		moveWest();
		currentState = "Wampire_Cove";
		dieOfStarvation(direction);
	}
}
void northMarsh(string direction){// funcion to move towards north of Marsh of Undead.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void southMarsh(string direction){// funcion to move towards south of Marsh of Undead.
	moveSouth();
	applesLeft -=1;
	applesLeft +=6;
	currentState = "Apples_Orchard";
	validMove(direction);
}
void marshOfUndead(string direction){// function when warrior is at Marsh of Undead.
	if (direction == "East"){//When Right Arrow is pressed
		eastMarsh(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westMarsh(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northMarsh(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southMarsh(direction);
	}
}

// functions for different directions when warrior's current state is Apples Orchard.
void eastOrchard(string direction){// funcion to move towards east of Apples Orchard.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void westOrchard(string direction){// funcion to move towards west of Apples Orchard.
	crystalOfHill(direction);
	if (applesLeft > 1){
		moveWest();
		currentState = "Werewolf_Hill";
		applesLeft -=1;
		validMove(direction);
	}
	else if (applesLeft == 1){
		moveWest();
		currentState = "Werewolf_Hill";
		dieOfStarvation(direction);
	}
}
void northOrchard(string direction){// funcion to move towards north of Apples Orchard.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void southOrchard(string direction){// funcion to move towards south of Apples Orchard.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void applesOrchard(string direction){// function when warrior is at Apples Orchard.
	if (direction == "East"){//When Right Arrow is pressed
		eastOrchard(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westOrchard(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northOrchard(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southOrchard(direction);
	}
	
}

// functions for different directions when warrior's current state is Werewolf Hill.
void eastHill(string direction){// funcion to move towards east of Werewolf Hill.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void westHill(string direction){// funcion to move towards west of Werewolf Hill.
	if (applesLeft > 2){
		moveWest();
		applesLeft -=2;
		currentState = "Elvin_Waterfall";
		validMove(direction);
	}
	else if (applesLeft == 2){
		moveWest();
		currentState = "Elvin_Waterfall";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void northHill(string direction){// funcion to move towards north of Werewolf Hill.
	if (applesLeft > 3){
		moveNorth();
		applesLeft -=3;
		currentState = "Wampire_Cove";
		validMove(direction);
	}
	else if (applesLeft == 3){
		moveNorth();
		currentState = "Wampire_Cove";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 2 ){
		invalidMove(direction);
	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void southHill(string direction){// funcion to move towards south of Werewolf Hill.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void werewolfHill(string direction){// function when warrior is at Werewolf Hill.
	if (direction == "East"){//When Right Arrow is pressed
		eastHill(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westHill(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northHill(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southHill(direction);
	}
}

// functions for different directions when warrior's current state is Elvin Waterfall.
void eastWaterfall(string direction){// funcion to move towards east of Elvin Waterfall.
	if (applesLeft > 2){
		moveEast();
		applesLeft -=2;
		currentState = "Werewolf_Hill";
		validMove(direction);
	}
	else if (applesLeft == 2){
		moveEast();
		currentState = "Werewolf_Hill";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void westWaterfall(string direction){// funcion to move towards west of Elvin Waterfall.
	if (applesLeft > 2){
		moveWest();
		crystalOfTunnel(direction);
		applesLeft -=2;
		currentState = "Eisten_Tunnel";
		validMove(direction);
	}
	else if (applesLeft == 2){
		moveWest();
		crystalOfTunnel(direction);
		currentState = "Eisten_Tunnel";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 1 ){
		starvationWithInvalidMove(direction);
	}
}
void northWaterfall(string direction){// funcion to move towards north of Elvin Waterfall.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void southWaterfall(string direction){// funcion to move towards south of Elvin Waterfall.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void elvinWaterfall(string direction){// function when warrior is at Elvin Waterfall.
	if (direction == "East"){//When Right Arrow is pressed
		eastWaterfall(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westWaterfall(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northWaterfall(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southWaterfall(direction);
	}
}

// functions for different directions when warrior's current state is Swamps of Despair.
void eastSwamps(string direction){// funcion to move towards east of Swamps of Despair.
	if (applesLeft > 1){
		moveEast();
		currentState = "Wampire_Cove";
		applesLeft -=1;
		validMove(direction);
	}
	else if (applesLeft == 1){
		moveEast();
		currentState = "Wampire_Cove";
		dieOfStarvation(direction);
	}
}
void westSwamps(string direction){// funcion to move towards west of Swamps of Despair.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
	starvationWithInvalidMove(direction);
	}
}
void northSwamps(string direction){// funcion to move towards north of Swamps of Despair.
	if (applesLeft > 1){
		moveNorth();
		currentState = "Bridge_of_Death";
		applesLeft -=1;
		validMove(direction);
	}
	else if (applesLeft == 1){
		moveNorth();
		currentState = "Bridge_of_Death";
		dieOfStarvation(direction);
	}
}
void southSwamps(string direction){// funcion to move towards south of Swamps of Despair.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void swampsOfDespair(string direction){// function when warrior is at Swamps of Despair.
	if (direction == "East"){//When Right Arrow is pressed
		eastSwamps(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westSwamps(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northSwamps(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southSwamps(direction);
	}
}

// functions for different directions when warrior's current state is Bridge of Death.
void eastBridge(string direction){// funcion to move towards east of Bridge of Death.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void westBridge(string direction){// funcion to move towards west of Bridge of Death.
	if (applesLeft >=5){
		if (nCrystalsFound==4){
			moveWest();
			applesLeft -=5;
			won(direction);
		}
		else{
			applesLeft -=1;
			currentState = "Bridge_of_Death";
			gameState = "Running";
			cout<<"Invalid move! You should have 4 crystals and atleast 5 apples to enter the Wizard's_Castle from Bridge_of_Death."<<endl;
		}
	}
	else if (applesLeft==4 || applesLeft ==3 || applesLeft==2 ){
		applesLeft -=1;
		currentState = "Bridge_of_Death";
		gameState = "Running";
		cout<<"Invalid move! You should have 4 crystals and atleast 5 apples to enter the Wizard's_Castle from Bridge_of_Death."<<endl;
	}
	else if (applesLeft ==1){
		starvationWithInvalidMove(direction);
	}
}
void northBridge(string direction){// funcion to move towards north of Bridge of Death.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void southBridge(string direction){// funcion to move towards south of Bridge of Death.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void bridgeOfDeath(string direction){// function when warrior is at Bridge of Death.
	if (direction == "East"){//When Right Arrow is pressed
		eastBridge(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westBridge(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northBridge(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southBridge(direction);
	}
}

// functions for different directions when warrior's current state is  Eisten Tunnel.
void eastTunnel(string direction){// funcion to move towards east of Eisten Tunnel.
	if (applesLeft > 2){
		moveEast();
		applesLeft -=2;
		currentState = "Elvin_Waterfall";
		validMove(direction);
	}
	else if (applesLeft == 2){
		moveEast();
		currentState = "Elvin_Waterfall";
		dieOfStarvation(direction);
	}
	else if(applesLeft == 1 ){
		currentState = "Eisten_Tunnel";
		starvationWithInvalidMove(direction);
	}
}
void westTunnel(string direction){// funcion to move towards west of Eisten Tunnel.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void northTunnel(string direction){// funcion to move towards north of Eisten Tunnel.
	if (applesLeft >=10 ){
		if (nCrystalsFound>=3){
			moveNorth();
			moveNorth();
			applesLeft -=10;
			won(direction);
		}
		else{
			applesLeft -=1;
			currentState = "Eisten_Tunnel";
			gameState = "Running";
			cout<<"Invalid move! You should have at least 3 crystals and 10 apples to enter the Wizard's Castle from Eisten_Tunnel."<<endl;
		}
	}
	else if ( applesLeft==9 || applesLeft ==8 || applesLeft==7 || applesLeft ==6 ||applesLeft==5 || applesLeft ==4 || applesLeft==3 || applesLeft==2 ){
		applesLeft -=1;
		currentState = "Eisten_Tunnel";
		gameState = "Running";
		cout<<"Invalid move! You should have at least 3 crystals and 10 apples to enter the Wizard's Castle from Eisten_Tunnel."<<endl;
	}
	else if (applesLeft ==1){
		starvationWithInvalidMove(direction);
	}
}
void southTunnel(string direction){// funcion to move towards south of Eisten Tunnel.
	if (applesLeft > 1){
		invalidMove(direction);
	}
	else if (applesLeft == 1){
		starvationWithInvalidMove(direction);
	}
}
void eistenTunnel(string direction){// function when warrior is at Eisten Tunnel.
	if (direction == "East"){//When Right Arrow is pressed
		eastTunnel(direction);
	}
	else if (direction == "West"){//When Left Arrow is pressed
		westTunnel(direction);
	}
	else if (direction == "North"){//When Up Arrow is pressed
		northTunnel(direction);
	}
	else if (direction == "South"){//When Down Arrow is pressed
		southTunnel(direction);
	}
}

void makeMove(string direction){
	if (gameState == "Running"){
		if (currentState == "Enchanted_Forest"){
			enchantedForest(direction);
		}
		else if (currentState == "Wampire_Cove"){
			wampireCove(direction);
		}
		else if (currentState == "Marsh_of_Undead"){
			marshOfUndead(direction);	
		}
		else if (currentState == "Apples_Orchard"){
			applesOrchard(direction);
		}
		else if (currentState == "Werewolf_Hill"){
			werewolfHill(direction);
		}
		else if (currentState == "Elvin_Waterfall"){
			elvinWaterfall(direction);
		}
		else if (currentState == "Swamps_of_Despair"){
			swampsOfDespair(direction);
		}
		else if (currentState == "Bridge_of_Death"){
			bridgeOfDeath(direction);
		}
		else if (currentState == "Eisten_Tunnel"){
			eistenTunnel(direction);
		}
	}
	else if (gameState == "Won"){
		wonState(direction);
	}
	else if (gameState == "Lost"){
		lostState(direction);	
	}
}
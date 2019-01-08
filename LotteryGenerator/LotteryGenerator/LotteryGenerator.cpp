//12/25/2018	-	Needed to reorder the reshuffle.
//12/25/2018	-	Framework 80% done.
//12/27/2018	-	Framework Done!
//				-	Need to implement choice of powerball or megamillion
//				-	Needed to implement formating.

#include "LotteryType.h"

//lottoGeneration()
//megaMillions()
//reshuffleGenerator()
//reshuffleDeck();
//printList();
//


int main() {
	srand(time(NULL));

	lottoGeneration();
	megaMillions();

	cout << "Welcome to Lottery Picker. Here the list of selected numbers: " << endl << endl;
	printList();
	cout << endl << endl;

	cout << "Here is the selected numbers: " << endl << endl;
	printDeck();
	cout << endl;

	cout << endl;
	selectionMenu();

	cout << "System is done! Thank you." << endl;
	system("pause");
	return 0;
}
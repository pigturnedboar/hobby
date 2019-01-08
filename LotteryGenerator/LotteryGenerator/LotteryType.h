#pragma once
#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

set<int> lottoStore;
set<int> pickedNum;
set<int>::const_iterator itr;

//number generation for large 15 number piece - also reshuffles when called again.
void lottoGeneration() {
	lottoStore.clear();
	for (int i = 0; i < 15; i++) {
		int num = rand() % 70 + 1;
		lottoStore.insert(num);
	}
	int counter = 0;
	while (true) {

		for (itr = lottoStore.begin(); itr != lottoStore.end(); ++itr) {
			if (*itr != NULL) {
				counter++;
			}
		}

		if (counter < 15) {
			int fillIn = 15 - counter;
			for (int i = 0; i < fillIn; i++) {
				int num = rand() % 70 + 1;
				lottoStore.insert(num);
				counter = 0;
			}
		}
		else
			break;
	}
	cout << "Here is counter: " << counter << endl;
}


//number picker for 5 random numbers - Also reshuffles.
void megaMillions() {
	pickedNum.clear(); // clears list to set[0]
	for (int j = 0; j < 5; j++) {
		int numPos = rand() % 14 + 1;
		set<int>::const_iterator itr(lottoStore.begin());
		advance(itr, numPos);
		pickedNum.insert(*itr);
	}

	int counter = 0;
	while (true) {

		set<int>::const_iterator itr;
		for (itr = pickedNum.begin(); itr != pickedNum.end(); ++itr) {
			if (*itr != NULL) {
				counter++;
			}
		}

		if (counter < 5) {
			int fillIn = 5 - counter;
			for (int i = 0; i < fillIn; i++) {
				int num = rand() % 70 + 1;
				pickedNum.insert(num);
				counter = 0;
			}
		}
		else
			break;
	}
}

//reshuffler functions
void reshuffleGenerator() {
	lottoGeneration();
}

void reshuffleDeck() {
	megaMillions();
}

void specialNumber() {
	int num = rand() % 25 + 1;
	cout << "Special Number: " << num << endl;
}

void printList() {
	//position lister
	cout << "Position:\t";
	for (int i = 1; i <= 15; i++) {
		cout << i << "\t";
	}
	cout << endl << endl;

	//number lister
	cout << "Number:\t\t";
	for (itr = lottoStore.begin(); itr != lottoStore.end(); ++itr) {
		cout << *itr << "\t";
	}
}

void printDeck() {

	for (itr = pickedNum.begin(); itr != pickedNum.end(); ++itr) {
		cout << *itr << "\t";
	}
	specialNumber();
}

void selectionMenu() {
	string choice;
	while (true) {
		cout << "Would you like to reshuffle? ( Yes | No ) ";
		cin >> choice;
		if (choice == "Y" || choice == "y" || choice == "yes" || choice == "Yes") {
			cout << "What would you like to reshuffle?" << endl;
			cout << "List" << endl;
			cout << "Deck" << endl;
			cout << "Exit" << endl;
			cin >> choice;
			if (choice == "l" || choice == "L" || choice == "List" || choice == "list") {
				lottoGeneration();
				cout << "Here is the new list of numbers: " << endl;
				printList();
				cout << endl;
			}
			else if (choice == "d" || choice == "D" || choice == "Deck" || choice == "deck") {
				megaMillions();
				cout << "Here is the new deck of numbers: " << endl;
				printDeck();
				cout << endl;
			}
			else if (choice == "e" || choice == "E" || choice == "Exit" || choice == "exit") {
				break;
			}
			else
				cout << "Please enter the beginning letter of the option or the full word." << endl;
		}

		if (choice == "N" || choice == "n" || choice == "no" || choice == "No") {
			break;
		}

	}
}
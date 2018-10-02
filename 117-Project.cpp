
#include <iostream>

using namespace std;



struct node {

	int key;
	int next;
	int mark;
};


node table[11];
int head1 = -1;
int freeL = 1;
int head2 = -1;

void printTable();
void insertN(int &list, int key);
void deleteN(int &list, int key);
void insertionSort(int &list);
void garbageCollection();




void insertN(int &list, int key) {
	int temp = freeL;
	int traverse = list;
	if (freeL != -1)
	{
		freeL = table[freeL].next;
	}
	if (list == -1)
	{
		list = temp;
		table[list].next = -1;
		table[list].key = key;
	}
	else
	{
		for (traverse; table[traverse].next != -1; traverse = table[traverse].next)
		{

		}

		table[traverse].next = temp;
		table[temp].next = -1;
		table[temp].key = key;
	}

}

void deleteN(int &list, int key)
{
	int p = -1;

	int trav;
	for (trav = list; table[trav].key != key; trav = table[trav].next) {
		p = trav;
	}
	if (trav == list){
		list = table[list].next;
		table[trav].key = -9999999;

	}
	else {
		table[trav].key = -9999999;
		table[p].next = table[trav].next;
		table[trav].next = -1;

	}
}

void garbageCollection()
{
	int i;

	for (i = head1; i != -1; i = table[i].next) {
		table[i].mark = 1;

	}
	for (i = head2; i != -1; i = table[i].next) {
		table[i].mark = 1;

	}
	for (i = freeL; i != -1; i = table[i].next) {
		table[i].mark = 1;

	}
	for (i = 1; i < 11; i++) {
		if (table[i].mark == 1) {
			table[i].mark = 0;
		}
		else {
			if (freeL == -1) {
				freeL = i;
			}
			else {
				table[i].next = freeL;
				freeL = i;
			}
		}
	}

}



void printTable() {
	for (unsigned int i = 1; i < 11; i++)
	{
		cout << '[' << i << ']' << "\t";
	}
	cout << endl;

	for (unsigned int i = 1; i < 11; i++)
	{
		if (table[i].key == -9999999) {
			cout << " " << "\t";
		}
		else
		{
			cout << table[i].key << "\t";
		}


	}

	for (unsigned int i = 1; i < 11; i++)
	{
		cout << table[i].next << "\t";

	}
	for (unsigned int i = 1; i < 11; i++)
	{
		cout << table[i].mark << "\t";

	}
	cout << endl << endl;
	cout << "list 1:" << head1 << "\t" << "list 2: " << head2 << "\t" << "Free list: " << freeL << endl << endl;
}





void insertionSort(int &list) {
	int trav;
	int p = -1;
	int curr = list;
	int n = table[curr].next;


	while (n != -1)
	{

		if (table[curr].key > table[n].key){

			table[curr].next = table[n].next;
			trav = list;
			p = -1;
			for (trav = list; trav != curr && table[trav].key < table[n].key; trav = table[trav].next) {
				p = trav;
			}
			if (trav == list) {
				list = n;

			}
			else {
				table[p].next = n;
			}
			table[n].next = trav;
			curr = n;

		}


		else {
			curr = n;
			if (n != -1) {
				n = table[curr].next;
			}
		}


	}

}


int main() {

	int a = 2;
	int inputs = 0;
	for (int i = 1; i < 11; i++) {
		table[i].key = -9999999;
		table[i].mark = 0;
		table[i].next = a;
		a++;
		if (i == 10) {
			table[i].next = -1;
		}
	}



	printTable();


	while (inputs != 5) {
		cout << endl;
		cout << "1 : insert to table" << endl;
		cout << "2 : print table" << endl;
		cout << "3 : delete from table" << endl;
		cout << "4 : Garbage collect" << endl;
		cout << "Enter option: ";
		cin >> inputs;
		if (inputs == 1) {
			int value;
			cout << endl;
			cout << "1 : list 1" << endl;
			cout << "2 : list 2" << endl;
			cout << endl;
			cout << "Which list?: ";
			cin >> inputs;
			cout << "enter value:";
			cin >> value;
			if (inputs == 1) {
				insertN(head1, value);
				insertionSort(head1);

			}
			else if (inputs == 2) {
				insertN(head2, value);
				insertionSort(head2);
			}

		}
		else if (inputs == 2) {
			printTable();
		}



		else if (inputs == 3) {
			int value2;
			cout << endl;
			cout << "1 : list 1" << endl;
			cout << "2 : list 2" << endl;
			cout << endl;
			cout << "pick list to insert to: ";
			cin >> inputs;
			cout << "enter value:";
			cin >> value2;
			if (inputs == 1) {
				deleteN(head1, value2);


			}
			else if (inputs == 2) {
				deleteN(head2, value2);

			}



		}
		else if (inputs == 4) {
			garbageCollection();

		}
		

	}

	cin.get();
	return 0;
}





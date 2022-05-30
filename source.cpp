#include <iostream>
#include <ctime>

using namespace std;

const int SIZE = 100;

void fill(int arr[], int size);
void show(int arr[], int size);
bool even_digit(int element);


int main()
{
	srand(time(NULL));

	int fake_size;
	cout << "Enter SIZE value" << endl;
	cin >> fake_size;

	int arr[SIZE];

	fill(arr, fake_size);
	show(arr, fake_size);

	int arr1[SIZE + 1]{};

	bool swich = 1;

	int first_even;

	for (int i = 0; i < fake_size; i++){
		if (even_digit(arr[i])) {
			if (swich) {
				first_even = i;
				swich = false;
			}
		}
	}

		swich = true;

		for (int i = 0; i < fake_size + 1; i++)
		{
			if (i == first_even) {
				swich = false;
				arr1[i] = arr[i];
				continue;
			}
			(swich) ? (arr1[i] = arr[i]) : (arr1[i] = arr[i - 1]);
		}
		show(arr1, fake_size);

		cout << "Here you can put any integer number: ";
		cin >> arr1[first_even + 1];

		show(arr1, fake_size+1);

	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int arr2[SIZE + 1];

	for (int i = 0; i < SIZE + 1; i++)
	{
		if (!(arr1[i] % 2)) {
			continue;
		}
		arr2[i] = arr1[i];
	}
	cout << "No evens array: " << endl;
	show(arr2, fake_size+1);

	/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int big = 0;

	for (int i = 0; i < fake_size; i+=2)
	{
		if ((i%2)==0) {
			if (arr[i] > big) {
				big = arr[i];
			}
		}
	}

	cout << "Biggest number: " << big;

}

void fill(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void show(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool even_digit(int element) {
	int calc = 0;
	while (element != 0) {
		element /= 10;
		calc++;
	}
	return (calc % 2) ? false : true;
}

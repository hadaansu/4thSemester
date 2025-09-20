// Lab 6.2: WAP to design TM that accepts even palindrome.
#include <iostream>
#include <string>
using namespace std;

bool tm(string input)
{
	char state = 'A';
	int head = 0;
	input.push_back('B');

	while (true)
	{
		switch (state)
		{
		case 'A':
			if (input[head] == 'a')
			{
				input[head] = 'B';
				state = 'B';
				head++;
			}
			else if (input[head] == 'b')
			{
				input[head] = 'B';
				state = 'E';
				head++;
			}
			else if (input[head] == 'B')
			{
				state = 'G';
				head++;
			}
			else
				return false;
			break;

		case 'B':
			if (input[head] == 'a' || input[head] == 'b')
				head++;
			else if (input[head] == 'B')
			{
				state = 'C';
				head--;
			}
			else
				return false;
			break;

		case 'C':
			if (input[head] == 'a')
			{
				input[head] = 'B';
				state = 'D';
				head--;
			}
			else
				return false;
			break;

		case 'D':
			if (input[head] == 'a' || input[head] == 'b')
				head--;
			else if (input[head] == 'B')
			{
				state = 'A';
				head++;
			}

			else
				return false;
			break;
		case 'E':
			if (input[head] == 'a' || input[head] == 'b')
				head++;
			else if (input[head] == 'B')
			{
				state = 'F';
				head--;
			}

			else
				return false;
			break;
		case 'F':
			if (input[head] == 'b')
			{
				input[head] = 'B';
				state = 'D';
				head--;
			}

			else
				return false;
			break;
		case 'G':
			return true;
		}
	}
}

int main()
{
	string input;
	cout << "Enter input: ";
	cin >> input;

	for (int i = 0; i < input.length(); i++)
		if (input[i] != 'a' && input[i] != 'b')
		{
			cout << "Invalid input. The alphabet is {a,b}.";
			return 0;
		}

	if (tm(input))
		cout << "TM accepts the string: " << input;
	else
		cout << "TM rejects the string: " << input;
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
//c++ program for bit stuffing and destuffing
int main()
{
	string input, output;
	string flag = "01111110";
	cout << "Enter input as a stream of 0's and 1's \n";
	cin >> input;
	int count = 0;
	output += flag;   //appending flag at the start of the data
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '1')
		{
			while (input[i] == '1'&&i < input.size() && count <= 5)
			{
				count++;
				output += input[i];
				i++;
				if (count == 5)
					break;
			}
			if (count == 5)                  //if 5 consecutive ones are encountered add '0' to output
			{
				output += '0';
				output += input[i];
				count = 0;
			}
			else
			{
				count = 0;
				output += input[i];
				

			}

		}

		else
			output += input[i];
	}

	output += flag;     //appending flag to end of the data

	cout << "The stuffed data is\n";
	cout << output << endl;
	
	//destuffing the stuffed data
	output.erase(0, 8);                 //removing flag from the start of data
	output.erase(output.size() - 8, 8);   //removing flag from the end of data
	

    string destuffed;
	count = 0;
	for (int i = 0; i < output.size(); i++)
	{
		if (output[i] == '1')
		{
			while (output[i] == '1'&&i < output.size())
			{
				count++;
				destuffed += output[i];
				i++;

			}

			if (count == 5)
			{
				count = 0;

			}

		    else
			{
				count = 0;
				destuffed += output[i];

			}
		}

			else
				destuffed += output[i];
	}

    cout << "The destuffed data is \n";
	cout << destuffed << endl;

	system("pause");
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
//c++ program for character stuffing and destuffing
int main()
{   
	string input, output;
	cout << "Enter input data\n";
	cin >> input;
	output += "dlestx ";
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 'd'&&input[i + 1] == 'l'&&input[i + 2] == 'e') //every occurrence of "dle" in input data is preceded by "dle" in output data
			output += "dle";
		output += input[i];
	}
	output += " dleetx";
	cout << "The stuffed data is \n";
	cout << output << endl;
	//destuffing the stuffed data
	string destuffed;
	output.erase(0, 6);            //removing the start characters
	output.erase(output.size() - 6, 6);   //removing the end characters
	
	for (int i = 0; i < output.size(); i++)
	{
		if (output[i] == 'd'&&output[i + 1] == 'l'&&output[i + 2] == 'e')  //replacing every occurrence of "dledle" with "dle"
		{
			i = i + 3;
		}
		destuffed += output[i];
	}

	cout << "The data after destuffing is\n";
	cout << destuffed << endl;


	system("pause");
	return 0;

}
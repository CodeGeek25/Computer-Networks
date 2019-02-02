#include<iostream>
#include<string>
using namespace std;
//c++ program for byte stuffing
int main()
{
	string flag, escape;
	int i, j, k, x, n;
	cout << "Enter the flag sequence(8 bits exactly)\n";
	cin >> flag;
	cout << "Enter the escape sequence(8 bits exactly)\n";
	cin >> escape;
	cout << "Enter number of bytes in data\n";
	cin >> n;
	string input[20];
	cout << "Enter the bytes one by one (exactly 8 bits in each byte)\n";
	for (i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	string output[20];
	output[0] = flag; 
	j = 1;//appending flag to start of data
	for (int i = 0; i < n; i++)
	{
		if (input[i].compare(flag) == 0 || input[i].compare(escape) == 0) //every occurrence of escape or flag is preceded by escape in output 
		{
			output[j] = escape;
			j++;
		}
		output[j] = input[i];
		j++;
	}

	output[j]= flag;     //appending flag to end of data
	cout << "The data after byte stuffing is \n";
	for (int i = 0; i<=j; i++)
	{
		cout << output[i];
		cout << " ";
	}
	cout << endl;
	
	//destuffing the stuffed data
	string destuffed[20];
	k = 0;
	for (i = 1; i < j; i++)
	{
		if (output[i].compare(escape) == 0 && output[i + 1].compare(flag) == 0) //replacing every occurrence of ESC FLAG to FLAG
		{
			destuffed[k] = output[i + 1];
			i++;
			k++;
		}
		else if (output[i].compare(escape) == 0 && output[i + 1].compare(escape) == 0)   //replacing every occurrence of ESC ESC to ESC
		{
			destuffed[k] = output[i + 1];
			i++;
			k++;
		}
		else
		{
			destuffed[k] = output[i];
			k++;
		}

	}
	cout << "The data after destuffing is\n";
	for (i = 0; i <= k; i++)
	{
		cout << destuffed[i]<<" ";
	}

    system("pause");
	return 0;
}
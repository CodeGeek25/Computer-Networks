#include<iostream>
#include<vector>
#include<time.h>
using namespace std;
//program to implement cyclic redundancy check
vector<int> doXor(vector<int> x, vector<int> y) //function to compute xor
{
	vector<int> result;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == y[i])
			result.push_back(0);
		else
			result.push_back(1);
	}
	return result;
}
vector<int> mod2Division(vector<int> dividend, vector<int> divisor)
{ 
	//function to perform modulo-2 division
	vector<int> temp;
	int k = divisor.size();
	int n = dividend.size();
	for (int i = 0; i < k; i++)
	{
		temp.push_back(dividend[i]);
	}
	int pick = k;
	vector<int> allZeroes;   //vector of all zeroes
	for (int i = 0; i < k; i++)
	{
		allZeroes.push_back(0);
	}
	while (pick < n)
	{
		if (temp[0] == 1)
		{
			temp = doXor(temp, divisor);
			if (temp[0] == 0)
			{
				temp.erase(temp.begin());
				temp.push_back(dividend[pick]);
			}
		}
		else
		{
			temp = doXor(temp, allZeroes);
			if (temp[0] == 0)
			{
				temp.erase(temp.begin());
				temp.push_back(dividend[pick]);
			}
		}
		pick += 1;
	}
	if (temp[0] == 1)
		temp = doXor(temp, divisor);
	else
		temp = doXor(temp, allZeroes);
	return temp;
}

int main()
{   
	int n, k,x;
	vector<int> data, generator;
	cout << "Enter the number of bits to be transmitted\n";
	cin >> n;
	cout << "Enter the data bit by bit\n";  //n-bit data
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		data.push_back(x);
	}
	cout << "Enter the number of bits in the generator polynomial\n";
	cin >> k;
	cout << "Enter the generator polynomial bit by bit\n";  //k-bit generator polynomial
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		generator.push_back(x);
	}
	for (int i = 0; i < k - 1; i++) //augment the data with k-1 zeros
	{
		data.push_back(0);
	}
	vector<int> remainder = mod2Division(data, generator);
	cout << "The remainder is\n";
	for (int i = 0; i < remainder.size(); i++)
	{
		cout << remainder[i];
	}
	cout << endl;
	
	
	for (int i =1; i <remainder.size(); i++)  //augmenting the data with the remainder
	{   
		
		data[i + n-1] = remainder[i];
	}
	cout << "The transmitted data is\n";
	for (int i = 0; i < data.size(); i++)
		cout << data[i];
	cout << endl;

	srand(time(0));

	int introduce_error = rand() % 20;
	if (introduce_error%2 != 0)
	{
		
		data[0] = ~data[0];
	}

	//checking for error at transmitter side
	cout << "\nTransmitter Side\n";
	remainder = mod2Division(data, generator);
	cout << "The remainder is\n";
	int correct = 0;
	for (int i = 0; i < remainder.size(); i++)
	{
		cout << remainder[i];
		if (remainder[i])
		{
			correct = 1;
		}
	}
	cout << endl;
	if (correct == 0)
		cout << "No error\n";
	else
		cout << "Error\n";
	system("pause");
	return 0;
}
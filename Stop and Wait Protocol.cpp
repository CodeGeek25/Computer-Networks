#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
// c++ program to simulate stop and wait
int main()
{   
	srand(time(0));
	int no_of_frames = rand() % 10 + 1;
	cout << "The number of frames is " << no_of_frames << endl;
	int i = 0;
	int again = 0;
	while (no_of_frames > 0)
	{   
		
		cout << "Sending frame " << i << endl;
		cout << "Waiting for 5 seconds\n";
		int wait = rand() % 20;
		
		if (wait % 2 == 0)
		{
			cout << "Acknowledgement for frame " << i << endl;
			i++;
			no_of_frames--;
		}
		else
		{
			int count = 0;
			again = 1;
			cout << "Acknowledgement not received\n";
			cout << "Sending frame " << i << " again" << endl;
			wait = rand() % 20;
		    //cout << "Sending frame " << i << " again" << endl;
				if (wait % 2 == 0)
				{
					cout << "Acknowledgement for frame " << i <<endl;
					i++;
					no_of_frames--;
				
				}
		}
    }
	system("pause");
	return 0;
}
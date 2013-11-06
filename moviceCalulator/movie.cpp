// justin foster
// Movie calculator. this program will ask for movies and quantities and a membership status
// will do all math calculations and display as correct dollars and cents
// 9/24/2013


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int memberShipStatus(int memberStatus);

int main(){
	//all my variables.
	string firstName, lastName;
	int numberDownloaded =0, memberStatus =0;
	double costPer =0, serviceCharge = 0, finalService = 0, subTotal = 0, tax = .07, total =0, baseCharge = 0, discount = 0, productCharge = 0;




	cout << "Please enter your first name: ";
	cin >> firstName;

	cout << "Please enter your last name: ";
	cin >> lastName;

	cout << "Please enter the number of movies you have downloaded: ";
	cin >> numberDownloaded;

	cout << "Please enter the cost per movie: ";
	cin >> costPer;

	// menu function saves time and energy(plus it looks cool)

	memberStatus = memberShipStatus(memberStatus);

	// if statement determines ervice charge based on how many movies are downloaded
	
	if (numberDownloaded < 8)
		serviceCharge = .07;
	else if (numberDownloaded < 15)
		serviceCharge = .04;
	else if (numberDownloaded < 20)
		serviceCharge = .02;
	else 
		serviceCharge = 0.0;


	//switch case decides which membership status is correct
	switch (memberStatus){
		case 3:
			discount = .15;
			break;
	
		case 2:
			discount = .10;
			break;
		case 1:
			discount = .05;
			break;
		default:
			discount = 0;
	}

	// this is where all my math was done to find the prices and charges

	baseCharge = numberDownloaded * costPer;
	finalService = baseCharge * serviceCharge;
	productCharge = finalService + baseCharge;

	subTotal =  productCharge - (productCharge * discount);
	total = (subTotal * tax) + subTotal;



	//output for all the information the user inputs.
	cout << fixed << setprecision(2)<< "Full name: " << firstName << " " << lastName << "\n"
		 << "Number of movies downloaded: " << numberDownloaded << "\n"
		 << "Price per movie: $" << costPer << "\n"
		 << "Service charge: $" << finalService << "\n"
		 << "Subtotal: $" << subTotal << "\n"
		 << "Tax : $" << (tax * subTotal) << "\n"
		 << "Total Charge: $" << total << "\n";
		 
	system("pause");
	return 0;
}


int memberShipStatus(int memberStatus){

int status = 4;
while (status >3 || status < 0){
cout << "\nPlease enter the status of your membership as follows\n"
	 << "3 represents Gold member\n"
	 << "2 represents Silver member\n"
	 << "1 represents bronze member\n"
	 << "0 represents nonmember       : ";
cin >> status;
}
cout << endl;
return status;

}
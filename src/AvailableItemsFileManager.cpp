#include <String>
#include <string.h>
#include "User.cpp"
#include "CurrentUserAccountsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Manages and updates data in the Available Items File
//Contains the transaction lines for all items in the system
static class AvailableItemsFileManager{
	string itemData;
	
public:
	//Adds item to Available Items file
	static void addItem(string name, double startingBid, time_t endDate, User seller){
		std::ofstream outfile;
 
    outfile.open("AvailableItemsFile", std::ios_base::app);
    outfile << "\n" << name << "_" << startingBid;
    outfile.close();
    //todo: add endDate and seller to file
  }
 
 
	static void bid(string name, string seller, double bid){
		Item item = findItem(name, seller);
		if(bid < item.currentBid){
			cout << "Bid is less than current bid." << endl;
			return;
		}
		updateBid(item, bid);
  }
}
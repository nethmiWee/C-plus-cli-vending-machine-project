

//This code was composed in Code::Blocks IDE
//#include "pch.h" has been added for it to run in Visual Studio

/*******************
 VENDING MACHINE CODE
 BY NETHMI WEERAMAN
 *******************/

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//Global variables
int inputItemCode;
int totalPrice = 0;
int CartIndex =0;
int addedItemsTracker = 0;
int lastItem;
int totalSales;



//Prototyping
 void deleteItem(int);
 void deleteMore(int);
 void changeDetails(int);
 void changeMore(int);
 void buyMore();
 void itemAdd();
 void changeWhichDetails();
 void exitProgram();
 void deleteType();
 int menu();
 int getQuantity();
 int getValue(int);
 int getTotal();
 int getUser(int);
 void welcome();
 void menuSelectItem();
 void buy();
 void cartItems();
 void changeMenu();
 void updateMenu();
 void showStats();
 void cashInsert(int);
 void buyMenu();
 void operatorMenu();


 //structure for added items
typedef struct itemAddList{
     string Name;
     string Category;
     int Code;
     int Price;
     int Quantity;
 } Item;

//Arrays
string items[30] = {"Juice", "Water", "Chips", "Candy", "Soda", "Jerky", "Coffee", "Tea", "Fruit"};
string itemCategory[30] = {"Drink", "Drink" , "Snack", "Snack" , "Drink" , "Snack", "Drink", "Drink" , "Snack"};
int itemCode[30] = {0, 1, 2, 3 , 4, 5, 6, 7, 8};
int itemPrice[30] = {2, 2, 3, 3 , 3, 3, 3, 2, 3};
int itemQuantity[30] = {5, 5, 5, 5 , 5, 5, 5, 5, 5};
string itemsInCart[30];
int noOfItemsInCart[30];
int priceOfItemsInCart[30];

int main(){
    welcome();
    system("CLS");
    return 0;
}


void welcome(){
    int buyOrUpdate;
    cout << "welcome to the vending machine system!\n";
    cout << "\nDo you wish to buy or update item(s)?\n" << "Press 1 to buy:" << endl << "Press 2 to update:" << endl;
    cout << "Enter: ";
    cin >> buyOrUpdate;

    getUser(buyOrUpdate);

}

int getUser( int pass){
    int password;

    if( pass == 1)
      {buyMenu();
      }

    else if( pass == 2)
      {cout << "\nEnter the password: ";
       cin >> password;
         if(password == 123)
         {operatorMenu();
         }

         else
         {cout << "*Invalid password, you will be redirected to the main menu*\n\n";
          main();
         }
    }

    else
    {cout << endl << "*Invalid number entered, try again!*" << endl;
    welcome();
    }
    //User is brought back to the same question of customer or developer,
    //till valid answer is entered

      return pass;
}

void menuSelectItem(){

    cout << "\n\n\tTo exit to main menu press any,\n\tvalid code and incorrect,\n\tquantity and select relevant option.\n";
    cout << "\n Press an item code to select an item: ";
    cin >> inputItemCode;

    if((inputItemCode >= (lastItem) || (inputItemCode < 0)) || (items[inputItemCode] == "N/A"))
       {cout << "\n*Invalid code entered, try again!*";
        menuSelectItem();
       }
    //Makes sure code entered is valid
}

int menu(){
    int totalValue = 0;

    cout << endl << "\t********************************" << endl;
    cout << "\tVending Machine Items: \n";
    cout << "\t********************************" << endl;

    for(int x= 0 ; x<=(9+ addedItemsTracker)  ; x++){
    if( x == 0){cout << "\tItem:\tCategory:\tCode:\tPrice:\tQuantity:\n";}

    if(items[x].empty())
        {lastItem = x;
         break;
         }

    cout << "\t" << items[x] << " ";
    cout << "\t" << itemCategory[x] << " ";
    cout << "\t\t(" << itemCode[x] << ") ";
    cout << "\t[" << itemPrice[x] << "$] ";
    cout << "\t [Q:" << itemQuantity[x] << "]\n ";
}
   return totalValue;

}

int getQuantity(){
  int totalQuantity = 0;

  for(int z= 0; z<=30 ; z++)
      {totalQuantity = itemQuantity[z] + totalQuantity;
      }
      //All items in stock calculation

      return totalQuantity;
}

int getValue(int itemIndex){
    return (itemQuantity[itemIndex] * itemPrice[itemIndex]);
}

int getTotal(){
    int total = 0;
    for(int x = 0 ; x <=(9+ addedItemsTracker)  ; x++){

        if(items[x].empty()){
                lastItem = x;
                    break;
        }
        total += getValue(x);
   //Total value calculation

    }
    return total;
}

void buy(){
   int price = 0;
   int emptyStockGoBack;
   int newQuantity;
   int quantity;
   cout << "\nYou have selected " << items[inputItemCode] << ".\n";

   cout << "\nHow much do you wish to purchase? ";
   cin >> quantity;

    if(quantity < 0){
        cout << "\nRe-enter quantity";
        buy();}

      newQuantity = itemQuantity[inputItemCode] - quantity;        //Reduces item's stock by quantity bought

      if(newQuantity >=0){
           itemQuantity[inputItemCode] = newQuantity;               //Sets new reduced quantity
           price = itemPrice[inputItemCode] * quantity;             //Calculates price for items

           itemsInCart[CartIndex] = items[inputItemCode];           //Stores item in cart
           noOfItemsInCart[CartIndex] = quantity;                   //Stores quantity bought of item in cart
           priceOfItemsInCart[CartIndex] = price;                   //Stores price of item in cart

           totalPrice = price + totalPrice;                         //Total sales and total price calculation
           totalSales = price + totalSales;

           CartIndex++;

            buyMore();
         }

    else if(newQuantity <0){
         cout << "\n*This item appears to be out of stock for quantity required.*\nDo you wish to select another quantity, another item or exit and go back?\n\n";
         cout << "Press 1 to change quantity\n" <<"Press 2 to go to menu\n" << "Press 3 to exit to main menu\n" << "Enter: ";
         cin >> emptyStockGoBack;

             switch(emptyStockGoBack){
               case 1:
                   system("CLS");
                    buy();                      //Redirects back to the when quantity is entered
                    break;
               case 2:
                    system("CLS");
                    menu();                    //Displays menu and lets user select from menu, then goes to buy function
                    menuSelectItem();
                    buy();
                    break;
               case 3:
                    system("CLS");
                    main();                    //Goes to start screen(main menu)
                    break;
               default:
                    cout << "*Invalid number entered: You will be redirected to main menu exit.*";
                    system("CLS");
                     main();
              }
       }
}

void cashInsert(int remainder){
    int insertCash;

    cout << "\n\tInsert: ";
    cin >> insertCash;

    remainder = insertCash + remainder;

    if(remainder < totalPrice)
        {cout << "\n\t[Your balance is insufficient,\n\t Enter "
         << (totalPrice - remainder) << "$ ];";
        cashInsert(remainder);
        }

    else if(remainder == totalPrice)
        {cout << "\n\n\tThank you for your purchase(s)!\n";
        remainder = 0;                                          //Balance is reset
        }

    else{cout << "\n\n\tThank you for your purchase(s)!";
          remainder = remainder - totalPrice;
         cout << "\n\tBalance: " << remainder << "$\n";
         remainder = 0;                                       //balance is reset
         }


}

void cartItems(){
    int mainOrExit;
    int balance = 0;
    cout << "\nYour cart item(s) are: \n";

            for(int a=0 ; a<10 ; a++)
                { if(noOfItemsInCart[a] == 0)
                  {break;}
                  cout << itemsInCart[a] << "\t[" << noOfItemsInCart[a] << "][" << priceOfItemsInCart[a] << "$]" << endl;
                }

                cout << "Your total: " << totalPrice << "$" << "\n\n\tPlease insert " << totalPrice << "$ into the machine;";

                cashInsert(balance);


                for(int a=0 ; a<10 ; a++)
                { noOfItemsInCart[a] = 0;
                  priceOfItemsInCart[a] = 0;
                } //Resets the cart values to null

                     CartIndex = 0;    //Cart item elements,
                     totalPrice = 0;   //Price of products purchased is reset after exiting to main menu for new customer


                cout << "\nWould you like to exit and go to main menu or exit program?\nPress 1 to go exit:\nPress any other number for main menu:\n";
                cin >> mainOrExit;

                if(mainOrExit == 1)
                    {exitProgram();
                    }

                else{system("CLS");
                     main();
                     }


}

void buyMore(){
        system("CLS");
        int buyMoreOrNot;
        cout << "\n\nDo you wish to order more?\n" << "Press 1 to order more\n" << "Press 2 to finish order\n" << "Enter:";
        cin >> buyMoreOrNot;

       if(buyMoreOrNot == 1)
        {system("CLS");     //Goes back to menu screen, selection then buy function
         menu();
         menuSelectItem();
         system("CLS");
         buy();
         }

       else if(buyMoreOrNot == 2)
        {cartItems();
        }

        else
        {cout << "*\nInvalid number entered, try again!*";
         system("CLS");
         buyMore();
         }

}

void itemAdd(){
    string inputName;
    string inputCategory;
    int inputPrice;
    int inputQuantity;
    int arrayElement;

    if((10+ addedItemsTracker) > 30){
    cout << "\n*Vending machine is at full capacity, you will be redirected back*";
    updateMenu();
   }
   //Does not allow over capacity storage

    system("CLS");
    addedItemsTracker++;

   Item item; //Creates an object of structure

    cout << "\nEnter name of item: ";
    cin >> inputName;

    item.Name = inputName;

    cout << "Enter category of item: ";
    cin >> inputCategory;

    item.Category = inputCategory;

    cout << "Enter price of item: ";
    cin >> inputPrice;

    item.Price = inputPrice;

    cout << "Enter quantity of item: ";
    cin >> inputQuantity;

    item.Quantity = inputQuantity;

    cout << "\n(Item entered successfully!)\n";

    arrayElement = lastItem;


items[arrayElement] = inputName;
itemCategory[arrayElement] = inputCategory;
itemCode[arrayElement] = arrayElement;
itemPrice[arrayElement] = inputPrice;
itemQuantity[arrayElement] = inputQuantity;


}

void changeMore(int update){
             int updateMoreOrNot;
             cout << "\nDo you wish to update more items?\nEnter 1 for no:\nEnter 2 for yes:\nEnter:";
             cin >> updateMoreOrNot;

             if(updateMoreOrNot == 2)
                  {changeDetails(update);}

             else if(updateMoreOrNot == 1)
                  {system("CLS");
                  changeMenu();}

             else {cout << "\nInvalid entry, try again!\n";
                  changeMore(update);}
}

void changeWhichDetails(){
         int updateWhich;
         system("CLS");
         menu();

         cout << "\nDo you wish to update stock of an item, or all details?"
         <<"\nPress 1 for stock update:\nPress 2 for all detail update:\nEnter:";
         cin >> updateWhich;

         changeDetails(updateWhich);
}

void changeDetails(int update){
         system("CLS");
         menu();

         string changeName;
         int changePrice;
         int changeQuantity;
         string changeCategory;
         int updateWhichItem;

         switch(update){
           case 1:
              cout << "\nEnter the code of the item you wish to update stock on;\nEnter: ";
              cin >> updateWhichItem;

              if(updateWhichItem >= (lastItem)  || items[updateWhichItem] == "N/A" )  //Cannot update details for deleted items
              {cout << "\n*Invalid, you will be redirected back*";
                system("CLS");
               changeDetails(update);
              }

             cout << "\nSelected item: [" << items[updateWhichItem] << "]\n";
             cout << "Current stock: " << itemQuantity[updateWhichItem];
             cout << "\nEnter stock:";
             cin >> changeQuantity;

             itemQuantity[updateWhichItem] = changeQuantity;

             changeMore(update);

           break;

           case 2:
             cout << "\nEnter the code of the item you wish to update details on;\nEnter: ";
             cin >> updateWhichItem;


         if(updateWhichItem >= (lastItem))
            {cout << "*Invalid, you will be redirected back to enter*";
             system("CLS");
             changeDetails(update);
             }

             system("CLS");

             cout << "\nEnter updated information in the following fields of the item [" << items[updateWhichItem] << "];\n";
             cout << "Name: ";
             cin >> changeName;
             items[updateWhichItem] = changeName;

             cout << "Category: ";
             cin >> changeCategory;
             itemCategory[updateWhichItem] = changeCategory;

             cout << "Price: ";
             cin >> changePrice;
             itemPrice[updateWhichItem] = changePrice;

             cout << "Quantity: ";
             cin >> changeQuantity;
             itemQuantity[updateWhichItem] = changeQuantity;

            changeMore(update);
           break;

           default:
            cout << "\n*Invalid, try again!*";
            changeWhichDetails();
         }


}

void deleteMore(int delet){
    int deleteMoreOrNot;
  cout << "\nDo you wish to delete more items?\nEnter 1 for yes:\nEnter 2 for no:\nEnter:";
  cin >> deleteMoreOrNot;

  if(deleteMoreOrNot == 1)
    {deleteItem(delet);}

  else if(deleteMoreOrNot == 2)
    {system("CLS");
     changeMenu();}

  else
    {cout << "*Invalid entry, try again!*";
    deleteMore(delet);}

}

void deleteType(){
       int deleteWhich;
        cout << "\nDo you wish to delete all items that are out of stock, or any other?\n"
        << "\nPress 1 for empty stock deletion:\n"
        << "Press 2 for other item deletion:\nEnter:";
        cin >> deleteWhich;

        deleteItem(deleteWhich);
}

void deleteItem(int delet){
        int deleteWhichItem;

        switch(delet){
           case 1:
                for(int x= 0 ; x<(lastItem); x++)
                    { if(itemQuantity[x]== 0){items[x] = "N/A";
			                                  itemCategory[x] = "N/A";
			                                  itemPrice[x]= 0;}
                    }
                system("CLS");
                changeMenu();
           break;

           case 2:
                system("CLS");
                menu();

                cout << "\nEnter the code of the item you wish to delete;\nEnter: ";
                cin >> deleteWhichItem;

                if(deleteWhichItem >= (lastItem))
               {cout << "\n*Invalid, you will be redirected back to entering code*";
                deleteItem(delet);
                }

			items[deleteWhichItem] = "N/A";
			itemCategory[deleteWhichItem] = "N/A";
			itemPrice[deleteWhichItem]= 0;
			itemQuantity[deleteWhichItem]= 0;


			deleteMore(delet);
          break;

           default:
            cout << "\n*Invalid, try again!*";
            deleteType();
    }


}

void showStats(){
     cout << "\n\tSTATS\nTotal sales: " << totalSales << "$";
     cout << "\nTotal stock: " << getQuantity();
     cout << "\nTotal value: " << getTotal() << "$\n";

}

void updateMenu(){
int updateBuyOrDelete;
    cout << "\nDo you wish to add items, update existing items, delete items or view stats?";
    cout << "\nPress 1 to add:\nPress 2 to update:\nPress 3 to delete:\nPress 4 to view stats:\nPress any other number to be redirected to main menu:\n";
    cout << "Enter:";
    cin >> updateBuyOrDelete;

    if(updateBuyOrDelete == 1)
        {itemAdd();
        }

    else if(updateBuyOrDelete == 2)
        {changeWhichDetails();
        }

    else if(updateBuyOrDelete == 3)
        {deleteType();
        }

    else if(updateBuyOrDelete == 4)
        {showStats();
        }

    else{system("CLS");
          main();
        }
}

void changeMenu(){

        cout << "\n\nYour update/check has been successful!\n\nWould you like to be redirected to the operator menu, main menu or the exit?\nPress 1 for main menu:\nPress 2 for operator menu:\n";
        cout << "Press any other number to exit:\nEnter:";
        int exitOrNot;
        cin >> exitOrNot;

        switch(exitOrNot){
         case 1:
         system("CLS");
         main();
         break;

         case 2:
         system("CLS");
         operatorMenu();
         break;

         default:
         cout << endl;
         exitProgram();
      }

}

void buyMenu(){
        menu();
        menuSelectItem();
        buy();
}

void operatorMenu(){
        cout << "\n\tCURRENT MENU:";
        menu();
        updateMenu();
        changeMenu();
    }

void exitProgram(){
cout << "\nThank you for using the vending machine!\n";
exit (1);
}

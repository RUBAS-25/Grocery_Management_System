#include <iostream>
#include <cstdlib>
#include<sstream>


using namespace std;

void authorization(string c[2][2],int sizeOfArray,string userRole);
void showOptionsBasedOnRoles(string userRole);

void adminPortal();
void employeePortal();
string loggedInEmployeeName;

												// Managing Product
void addProduct();
void viewProduct();
void deleteProduct();
void updateProduct();
void searchProductByType();

string searchProduct[20][6];

void orderProduct();
void generateReceipt();



string orderNumber = "1";

void viewProductDesign(string products[20][6],int size);
string products[50][6]={ 
       
	      {"1","shirt","clothes","500","600","50"},
	      {"2","bat  ","sports","410","620","20"},
		  {"3","egg  ","food", "20","30","40"},
		  {"4","milk  ","food", "100","200","40"},
		  {"5","salt  ","food", "400","330","40"},
		  {"6","noodle","food", "100","150","30"},
		  {"7","pent  ","clothes", "1500","3000","38"},
		  {"8","juice  ","food", "210","250","50"},
		  {"9","Bag","food", "500","600","20"},
		  {"10","books ","books", "190","360","40"},
		  {"11","cfoods","food", "2000","3000","44"},
		  {"12","fish  ","food", "300","320","89"},
		  {"13","meat ","food", "1000","1500","40"},
		  {"14","fauji","food", "350","400","90"},
		  {"15","dolls ","toy", "700","750","45"},
		  {"16","soup ","food", "200","250","60"},
		  {"18","apple ","food", "100","200","30"},
		  {"19","db cake ","food", "150","180","90"},
		  {"20","bottle ","food", "150","200","40"}
		  
		  };



int inStockProductSize = 20;

											// Managing Sales
void addSale(int profit);
void viewSales(string sales[50][3] , int totalSales);
string sales[50][3];
int totalSales = 0; 
											// Managing Cart
string cart[50][6];
int cartSize = 0;
void viewCart();

void gap(int num);
void printLine();

											// payment method
											
void paymentMethod(int totalAmount);



void userSelection(){
	int option;
	char tryAgain = 't';
	
	string admin[2][2]= {
		{"faiza@gmail.com","faiza123"},
		{"burhan@gmail.com","burhan123"}
	};
	
	string employee[2][2]= {
		{"faiza@gmail.com","faiza123"},
		{"hannan@gmail.com","hannan1"}
	};
	
	do{
		system("cls");
		cout<< "__________________________________________________________________________"<<endl;
		cout<< "-------------- Welcome TO GROCERY CALORE BILLING System -----------------"<<endl;
		cout<< "__________________________________________________________________________"<<endl;
		cout<<endl;
		cout<<"Select Please : "<<endl;
		cout<<"1. LOGIN AS ADMINISTRATOR "<<endl;
		cout<<"2. LOGIN AS CASHIER "<<endl;
		cout<<"3. EXIT "<<endl;
		cout<<"Enter a number------> : ";
		cin>>option;
		
		if(option == 1){
			int n = sizeof(admin)/sizeof(admin[0]);
			authorization(admin,n,"ADMINISTRATOR");
		}
		else if(option == 2){
			int n = sizeof(employee)/sizeof(employee[0]);
			authorization(employee,n,"CASHIER");
		}
		else if(option == 3){
			exit(0);
		}
		else{
			cout<<"Invalid Option press (t) to tryAgain , press (e) to exit ";
			cin>>tryAgain;
		}
	
	}while(tryAgain == 't');
}

void authorization(string c[2][2],int sizeOfArray,string userRole){
	
	string username,password;
	bool notAuth = true;
	char tryAgain = 't';


	while(tryAgain == 't'){
	system("cls");
	fflush(stdin);
	
	cout<<"      "<<userRole<<" PORTAL     "<<endl;
	
	cout<<"ENTER EMAIL : ";
	getline(cin,username);
	
	cout<<"ENTER PASSWORD : ";
	getline(cin,password);
	
	for(int i = 0 ; i < sizeOfArray ; ++i){
			
			if(c[i][0] == username && c[i][1] == password){
				system("cls");
				tryAgain = 'e';
				notAuth = false;
				loggedInEmployeeName = username;
				showOptionsBasedOnRoles(userRole);
				
				break;
			}
				
	}
	
	if(notAuth){
		cout<<"Invalid Credentials Please try Again , to try again press(t), to exit press(e) : ";
		cin>>tryAgain;
		fflush(stdin);
		cout<<endl;
	}

	}	

}

void showOptionsBasedOnRoles(string userRole){
	if(userRole == "ADMINISTRATOR"){
		adminPortal();
	}
	else{
		employeePortal();
	}
}

void adminPortal(){
	char tryAgain = 't';
	do{
	tryAgain = 't';
	
	system("cls");
	int selection;
	cout<< "__________________________________________________________________________"<<endl;
	cout<< "-------------------- GROCERY CALORE BILLING System -----------------------"<<endl;
	cout<< "__________________________________________________________________________"<<endl;
	cout<<"------------------------------- ADMINISTRATOR PORTAL ----------------------"<<endl;
	cout<<" WELCOME GROCERY GALORE "<<loggedInEmployeeName<<" ! "<<endl;
	cout<<"1. ADD Product"<<endl;
	cout<<"2. DELETE Product"<<endl;
	cout<<"3. UPDATE Product"<<endl;
	cout<<"4. VIEW Product"<<endl;
	cout<<"5. VIEW SALES"<<endl;
	cout<<"6. Exit "<<endl;
	cout<<"choose : ";
	cin>>selection;
	
	switch(selection){
		case 1:
			addProduct();
			break;
		case 2:
			deleteProduct();
			break;
		case 3:
			updateProduct();
			break;
		case 4:
			viewProduct();
			cout<<"Press e to exit : ";cin>>tryAgain;
			tryAgain = 't';
			break;
		case 5:
			viewSales(sales,totalSales);
			cout<<"Press e to exit : ";cin>>tryAgain;
			tryAgain = 't';
			break;
		case 6:
			tryAgain = 'e';
			break;
		default:
			cout<<"Invalid Selection Please select from above given "<<endl;
			cout<<"Press t to perform another task , press e to exit : ";cin>>tryAgain;
			
		}
	} while(tryAgain == 't');

	
}


void addProduct(){
	
	
	string productId,quantity;
	string productName,varient;
	string costPrice,salePrice;
	char tryAgain = 't';
	
	do{
	system("cls");
	cout<< "__________________________________________________________________________"<<endl;
	cout<< "----------------------- GROCERY CALORE BILLING System --------------------"<<endl;
	cout<< "__________________________________________________________________________"<<endl;
	cout<<"------------------------------- ADD PRODUCT -------------------------------"<<endl;
	int n = sizeof(products)/sizeof(products[0]);
     
	cout<<"Enter Product Id : ";cin>>productId;
	cout<<"Enter Product Name : ";cin>>productName;
	cout<<"Enter Product type (eg food,sports etc) : ";
	cin>>varient;
	cout<<"Enter Product Cost Price : ";cin>>costPrice;
	cout<<"Enter Product Sale Price : ";cin>>salePrice;
	cout<<"Enter Product Quantity : ";cin>>quantity;
	
	for(int i = inStockProductSize ; i < n ; ++i){
		for(int j = 0 ; j < 1 ; j++){
			
			products[i][0] = productId;
			products[i][1] = productName; 
			products[i][2] = varient; 
			products[i][3] = costPrice; 
			products[i][4] = salePrice; 
			products[i][5] = quantity; 
		}
		inStockProductSize++;
		break;
	}
		cout<<"Product SuccessFully Added press t to add another product , press e to exit : ";cin>>tryAgain;
	}while(tryAgain == 't');
	
}

void updateProduct(){
	
	string productId,quantity,p_id;
	string productName,varient;
	string costPrice,salePrice;
	char tryAgain = 't';
	bool productNotFound;
	int productIndex;
	
	
	do{
	system("cls");
	productNotFound = true;
	cout<< "__________________________________________________________________________"<<endl;
	cout<< "------------------------ GROCERY CALORE BILLING System -------------------"<<endl;
	cout<< "__________________________________________________________________________"<<endl;
	cout<<"------------------------------- UPDATE PRODUCT ----------------------------"<<endl;
	cout<<"Enter Product id to update the data : ";cin>>p_id;
	
	string productbyId [1][6];
	
	for(int i = 0 ; i < inStockProductSize; ++i){
		for(int j = 0 ; j < 6 ; j++){
			if(products[i][0] == p_id){
				productIndex = i;
				productbyId[0][j] = products[i][j];
				productNotFound = false;
			}
		}
	}
	
	if(productNotFound){
		cout<<"Invalid product id , No product Exist having id : "<<p_id<<" press t to try Again , press e to exit : ";cin>>tryAgain;
	}
	else{
				viewProductDesign(productbyId,1); 
				
				cout<<"Enter Product Id (n to not change): ";cin>>productId;
				cout<<"Enter Product Name (n to not change) : ";cin>>productName;
				cout<<"Enter Product Type  (n to not change) : ";cin>>varient;
				cout<<"Enter Product Cost Price (n to not change) : ";cin>>costPrice;
				cout<<"Enter Product Sale Price (n to not change) : ";cin>>salePrice;
				cout<<"Enter Product Quantity (n to not change) : ";cin>>quantity;
			
				if(productId != "n"){
					products[productIndex][0] = productId;
				}
				if(productName != "n"){
					products[productIndex][1] = productName;
				}
				if(varient != "n"){
					products[productIndex][2] = varient;
				}
				if(costPrice != "n"){
					products[productIndex][3] = costPrice; 
				}
				if(salePrice != "n"){
					products[productIndex][4] = salePrice;
				}
				if(quantity != "n"){
					products[productIndex][5] = quantity; 
				}
				
				cout<<"Product SuccessFully UPDATED press t to add Update another product , press e to exit : ";cin>>tryAgain;
		}
	
	}while(tryAgain == 't');
}

void deleteProduct(){
	
	
	string p_id;
	char tryAgain = 't';
	
	do{
	system("cls");
	
	bool productNotDeleted = true;
	cout<< "__________________________________________________________________________"<<endl;
	cout<< "----------------------- GROCERY CALORE BILLING System --------------------"<<endl;
	cout<< "__________________________________________________________________________"<<endl;
	cout<<"------------------------------- DELETE PRODUCT ----------------------------"<<endl;
	cout<<"Enter product id to delete product : ";cin>>p_id;
	
	for(int i = 0 ; i < inStockProductSize;++i){
			if(products[i][0] == p_id){
				
				products[i][0] = "0";
				products[i][1] = "0";
				products[i][2] = "0";
				products[i][3] = "0";
				products[i][4] = "0";
				products[i][5] = "0";
				
				productNotDeleted = false;
				break;
			}
	}
	
		if(productNotDeleted){
			cout<<"Invalid product id , No product Exist having id : "<<p_id<<" press t to try Again , press e to exit : ";
		}
		else{
			cout<<"Product Deleted Successfully , press t to delete another product , press e to exit : ";
		}
		cin>>tryAgain;
	}while(tryAgain == 't');
	
}

void viewProduct(){
	system("cls");
	cout<< "__________________________________________________________________________"<<endl;
	cout<< "------------------------ GROCERY CALORE BILLING System -------------------"<<endl;
	cout<< "__________________________________________________________________________"<<endl;
	cout<<"------------------------------- PRODUCT LISTING ----------------------------"<<endl;
	viewProductDesign(products,inStockProductSize);
}



void employeePortal(){
	int selection;
	char tryAgain = 't';
	
	do{
		system("cls");
		cout<< "___________________________________________________________________________"<<endl;
		cout<< "---------------------- GROCERY CALORE BILLING System ----------------------"<<endl;
		cout<< "___________________________________________________________________________"<<endl;
		cout<<"------------------------------- CASHIER PORTAL -----------------------------"<<endl ;
		cout<<loggedInEmployeeName<<" ! "<<endl;
		cout<<"1. VIEW PRODUCTS"<<endl;
		cout<<"2. ORDER PRODUCTS "<<endl;
		cout<<"3. SEARCH PRODUCTS BY TYPE "<<endl;
		cout<<"4. EXIT "<<endl;
		cout<<"choose : ";
		cin>>selection;
		
		switch(selection){
			case 1:
				viewProduct();
				cout<<"Press e to exit : ";cin>>tryAgain;
				tryAgain = 't';
				break;
			case 2:
				orderProduct();
				break;
			case 3:
				searchProductByType();
				cout<<"Press e to exit : ";cin>>tryAgain;
				tryAgain = 't';
				break;
			case 4:
				tryAgain = 'e';
				break;
			default:
				cout<<"Invalid selection press (t) to try again , press e to exit : ";cin>>tryAgain;
		}
		
	}while(tryAgain == 't');
}

void searchProductByType(){
	string type;
	
	cout<<"------------------------------- PRODUCT BY TYPE -------------------------------"<<endl;
	cout<<"Enter prodcuct type to filter : ";cin>>type;
	int size = 0;
	bool notExist = true;
	
	for(int i =0 ; i < inStockProductSize ; i++){
		if(products[i][2] == type){
			searchProduct[size][0] = products[i][0];
			searchProduct[size][1] = products[i][1];
			searchProduct[size][2] = products[i][2];
			searchProduct[size][3] = products[i][3];
			searchProduct[size][4] = products[i][4];
			searchProduct[size][5] = products[i][5];
			
			size++;
			notExist = false;
		}
	}
	
	if(!notExist){
		system("cls");
	cout<< "_____________________________________________________________________________________"<<endl;
	cout<< "---------------------------  GROCERY CALORE BILLING System  -------------------------"<<endl;
	cout<< "_____________________________________________________________________________________"<<endl;
	cout<<"------------------------------- PRODUCTS BY "<<type<<" -------------------------------"<<endl;
	viewProductDesign(searchProduct,size);
	}
	else{
		cout<<"Filtered Product Does not Exist "<<endl;
	}
	
	
	

}

void viewProductDesign(string  products[50][6],int size){
	cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"|  Product Id |  ProductName   |    Product Type    |  Product Cost Price |  Product Sale Price |  Product Quantity |"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
	for(int i = 0 ; i < size ; ++i){
		if(products[i][0] != "0" && products[i][5] != "0"){
			cout<<"| "<<products[i][0]<<"\t\t   "<<products[i][1]<<"  \t\t"<<products[i][2]<<"\t\t\t "<<products[i][3]<<"\t\t "<<products[i][4]<<"\t\t   \t "<<products[i][5]<<"\t"<<endl;	
		}
	}
	
	if(inStockProductSize == 0){
		gap(5); cout<<"NO PRODUCT EXIST "<<endl;
	}
	cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------"<<endl;
}

void orderProduct(){
	char tryAgain = 'o';
	string p_id;
	bool productNotFound,invalidQuantity;
	int p_quantity;
	
	while(tryAgain == 'o'){
		productNotFound = true;
		invalidQuantity = false;
		
		ostringstream outputStream,convertQuantity;
		
		system("cls");
	cout<< "________________________________________________________________________________"<<endl;
	cout<< "-------------------------  GROCERY CALORE BILLING System  ----------------------"<<endl;
	cout<< "________________________________________________________________________________"<<endl;
		cout<<"------------------------------- ORDER PRODUCT -------------------------------"<<endl;
		viewProduct();
		cout<<"Select Product id to add it in the cart : ";cin>>p_id;
		
			
			for(int i = 0 ; i < inStockProductSize; ++i){
					if(products[i][0] == p_id){
						
						cout<<"How much quantity you want : ";cin>>p_quantity;
						if(p_quantity > 0 && p_quantity <= atoi(products[i][5].c_str())){
							
							cart[cartSize][0] = products[i][0] ;
							cart[cartSize][1] = products[i][1] ;
							cart[cartSize][2] = products[i][2] ;
							cart[cartSize][3] = products[i][3] ;
							cart[cartSize][4] = products[i][4] ;
							
							convertQuantity << p_quantity;
						
							cart[cartSize][5] =  convertQuantity.str();
							productNotFound = false;
							
																						// converted string into int then subtracted value
							int value =  atoi(products[i][5].c_str());
							value -= p_quantity;
							outputStream << value;
							products[i][5] = outputStream.str();
						
						}
						else{
							productNotFound = false;
							invalidQuantity = true;
							cout<<" Invalid Quantity press (o) to order again :";cin>>tryAgain;
						}
					}
			}
			
			
		if(productNotFound && cartSize == 0){
			cout<<"Invalid product id , No product Exist having id : "<<p_id<<" press (o) to order Again , press e to exit : ";
			cin>>tryAgain;
		}
		else if(productNotFound){
			cout<<"Invalid product id , No product Exist having id : "<<p_id<<" press (o) to order Again , press (c) to confirm : ";
			cin>>tryAgain;
		}
		else if(!invalidQuantity){		
			cartSize++;
			viewCart();
			cout<<endl;
			cout<<"Product Successfully added in cart , press (o) to order another product , press (c) to confirm order ";cin>>tryAgain;
		}
		
		if(tryAgain == 'e'){
			cartSize = 0;
			string cart[50][6] = {};
		}
		
		if(tryAgain == 'c'){
			system("cls");
			generateReceipt();
			cout<<endl;
//			cout<<"Press e to exit ";cin>>tryAgain;
		}
			
	}
	
}

void viewCart(){
	system("cls");
	cout<<" VIEW CART "<<endl;
	viewProductDesign(cart,cartSize);
}

void printHeader() {
	printLine();
    gap(10);
	cout<< "GROCERY GALORE Billing System " << endl;
    gap(8); 
	cout<< "Iqra University, Karachi" << endl;
    gap(10);
	cout<< "www.grocery_galore.com" << endl;
    printLine();
}

void generateReceipt(){
	system("cls");
	
	float totalAmount = 0.0;
	float totalCostPrice = 0.0;
	float subTotal;
	int tax = 5;
	
	printHeader();
    

    gap(2); cout << " Item  "; 
    gap(3); cout << "|  Product";
    gap(6); cout << "| Quantity ";
    gap(6); cout << "|  Price";
    gap(6); cout << "|  Subtotal "<<endl;
    
    printLine();
    
    for(int i = 0 ; i < cartSize ; i++){
    	subTotal = 0.0;
    	int quantity  = atoi(cart[i][5].c_str());
    	int price = atoi(cart[i][4].c_str());
    	totalCostPrice += atoi(cart[i][3].c_str()) * quantity;
    	int sum = quantity*price;
    	gap(2); cout << "Item "<<i+1;
    	gap(6); cout <<  cart[i][1] <<"\t \t"; 
    	gap(3); cout <<  cart[i][5]; 
    	gap(11); cout <<  cart[i][4]; 
    	gap(13); cout <<  sum; 
    	
    	totalAmount += sum;
    	cout<<endl;
	}
    
    printLine();
    
    
    gap(15); cout<< "Amount :  " << totalAmount << endl;
    gap(15); cout<< "Tax Included : "<<tax<<"%"<<endl;
    gap(15); cout<<	"Total Amount : "<<totalAmount+((totalAmount*tax)/100)<<endl;
    addSale(totalAmount-totalCostPrice);
    
    paymentMethod(totalAmount);
}

void printLine() {
    cout << "-----------------------------------------------------------------------" << endl;
}

void gap(int num){
	for(int i = 0 ; i < num ; ++i){
		cout<<" ";
	}
}

void addSale(int profit){
	// get totalAmount , totalCostPrice ,  totalProducts , date
	stringstream convertor; 
	string priceInString; 
	
	convertor<<profit;  
	convertor>>priceInString;  
  	

	if(cartSize > 0){
		for(int i = totalSales ; i < totalSales+1 ; i++){
			sales[i][0] = orderNumber;
			sales[i][1] = loggedInEmployeeName;
			sales[i][2] = priceInString;
		}
		
		totalSales++;
		cartSize = 0;
		string cart[50][6] = {};	
		
	}
	// id , employee name , profit , total products , date
}


void viewSales(string sales[50][3] , int totalSales){
	cout<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<"| Order Id\t | Employee Name\t\t\t | Profit\t  |"<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
	for(int i = 0 ; i < totalSales ; ++i){
		if(sales[i][0] != "0"){
			cout<<"| "<<sales[i][0]<<"\t\t\t"<<sales[i][1]<<"\t\t\t"<<sales[i][2]<<endl;	
		}
	}
	if(totalSales == 0){
		gap(4); cout<<" No SALES TODAY :( "<<endl;
		
	}
	cout<<endl;
	cout<<"------------------------------------------------------------------"<<endl;
}

void paymentMethod(int totalAmount){
	int option;
	char tryAgain;
	string cardNumber,pin;
	char pinNumber;
	string bankList[5] = {"Meezan","Allied","HBL","Bank Islamic","Al Habib"};
	
	do{
	tryAgain = 't';

	cout<<endl;
	cout<<endl;
	cout<<endl;
	
	printLine();
	gap(10);cout<<" PAYMENT METHOD "<<endl;
	printLine();
	cout<<"Choose Payment Method : "<<endl;
	cout<<"1. Card"<<endl;
	cout<<"2. Cash"<<endl;
	cout<<"Choose : ";cin>>option;
	
	if(option == 1){
			int selectedBank;
			cout<<"Given Bank Cards are allowed Please Select for further process : "<<endl;
			int n = sizeof(bankList)/sizeof(bankList[0]);
			for(int i = 0 ; i < n ; i++ ){
				cout<<i+1<<" )   "<<bankList[i]<<" Bank "<<endl;
			}
			cout<<endl;
			cout<<"Choose : ";cin>>selectedBank;
			if(selectedBank > 0 && selectedBank < n){
				
				cout<<"Enter Card Number : ";
				cin>>cardNumber;
				cout<<endl;
				cout<<"Enter pin number : ";
				cin>>pin;
				
				cout<<endl;
				gap(5); cout<<" Processing Please Wait ";
				for(int i = 0 ; i < 10 ; i++){
					cout<<".";
				}
				cout<<endl;
				printLine();
				cout<<"  	Payment Successfully	 "<<endl;
				printLine();	
				cout<<endl;
				cout<<"Press e to exit : ";cin>>tryAgain;
			}
			else{
				cout<<"Invalid Payment Method press t to tryAgin or e to exit ";cin>>tryAgain;
			}
	}
	else if(option == 2){
		printLine();
		cout<<endl;
		int givenAmount;
		gap(5);cout<<"  Payment Method "" Cash ""         "<<endl;
		printLine();
		cout<<endl;
		cout<<"Total Amount : "<<totalAmount<<endl;
		cout<<"Given Amount : ";cin>>givenAmount;
		cout<<"Amount Return : "<<givenAmount - totalAmount<<endl;
		cout<<endl;
		printLine();
		cout<<"  	Payment Successfully	 "<<endl;
		printLine();	
		cout<<"Press e to exit : ";cin>>tryAgain;
	}
	else{
			cout<<" Invalid Payment Method press t to tryAgin or e to exit : ";cin>>tryAgain;
	}
	
	}while(tryAgain == 't');
	
	 
}

int main(){
	userSelection();
	return 0;
}







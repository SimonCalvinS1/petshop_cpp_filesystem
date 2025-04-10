#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Pet {
	private:
	    int petId, price, age;
	    string* petName;
	    string* breed;
	    bool ifavailable;
	public:
	    Pet(){
	        petId = 0;
	        petName = new string;
	        breed = new string;
	        price = 0;
	        age = 0;
	        ifavailable = false;
	    }
	    virtual ~Pet(){
	        delete petName;
	        delete breed;
	    }
	    static int makePetId(){
	        static int nextId = 101;
	        return nextId++;
	    }
	    void setPets(string petName,string breed,int price,int age){
	        petId = makePetId();
	        *this->petName = petName;
	        *this->breed = breed;
	        this->price = price;
	        this->age = age;
	        ifavailable = true;
	    }
	    
	    int getPrice() { return price; }
	    bool available() { return ifavailable; }
	    Pet& operator++() { ++price; return *this; }
	    void operator!() { ifavailable = !ifavailable; }
	    
	    virtual void display(){
	        cout << "Pet ID : " << petId << endl;
	        cout << "Pet Name : " << *petName << endl;
	        cout << "Pet Breed : " << *breed << endl;
	        cout << "Pet Price : " << price << endl;
	        cout << "Pet Age : " << age << endl;
	        cout << "Pet Availability : " << (ifavailable ? "Available" : "Not Available") << endl << endl;
	    }
};

class Birds : public Pet { //single inheritance
	private:
	    int cagelength, cagebreadth, cageprice;
	public:
	    Birds(){
	        cagelength = 0;
	        cagebreadth = 0;
	        cageprice = 0;
	    }
	    void setBirdCage(int length,int breadth,int cageprice){
	        cagelength = length;
	        cagebreadth = breadth;
	        this->cageprice = cageprice;
	    }
	    void display() override{
	        cout << "\n----------Bird details----------\n" << endl;
	        Pet::display();
	        cout << "Bird cage size : " << cagelength << "*" << cagebreadth << endl;
	        cout << "Bird cage price : " << cageprice << endl;
	    }
	    
	    int getCagePrice() { return cageprice; }
};

class Dogs : public Pet { //single inheritance
	private:
	    int doghouselen, doghousewid, doghousepri;
	public:
	    Dogs(){
	        doghouselen = 0;
	        doghousewid = 0;
	        doghousepri = 0;
	    }
	    void setHouse(int len, int wid, int h_pri){
	        doghouselen = len;
	        doghousewid = wid;
	        doghousepri = h_pri;
	    }
	    void display() override{
	        cout << "\n----------Dog details----------\n" << endl;
	        Pet::display();
	        cout << "Dog house size : " << doghouselen << "*" << doghousewid << endl;
	        cout << "Dog house price : " << doghousepri << endl;
	    }
	    
	    int getHousePri() { return doghousepri; }
};

class Fishes : public Pet { //single inheritance
	private:
	    int tanklength, tankbreadth;
	    string* watertype;
	public:
	    Fishes() { watertype = new string; }
	    ~Fishes() { delete watertype; watertype = NULL; }
	    
	    void setFish(int t_length,int t_breadth,string w_type){
	        tanklength = t_length;
	        tankbreadth = t_breadth;
	        *watertype = w_type;
	    }
	    void display() override{
	        cout << "\n----------Fish details----------\n" << endl;
	        Pet::display();
	        cout << "Tank size suitable : " << tanklength << "*" << tankbreadth << endl;
	        cout << "Water type : " << *watertype << endl << endl;
	    }
};

//Birds, Dogs and Fishes inherit/extend from Pet class demonstrating Hierarchical inheritance

class Aquarium : public Fishes { //multilevel inheritance as Fishes already is inheriting/extending Pet class
	private:
	    string* tankName;
	    int no_of_litres, tankprice;
	public:
	    Aquarium() { tankName = new string; }
	    ~Aquarium() { delete tankName; tankName = NULL; }
	    
	    void setAqua(string nametank, int capacity){
	        *tankName = nametank;
	        no_of_litres = capacity;
	        tankprice = capacity * 10;
	    }
	    void displayAqua(){
	        cout << "Tank Name : " << *tankName << endl;
	        cout << "Litre Capacity : " << no_of_litres << "litres" << endl;
	        cout << "Tank Price : " << tankprice << endl;
	    }
	    
	    int getAquaPrice() { return tankprice; }
};

class Employee {
	private:
	    int e_id[10];
	    string e_name[10];
	    int empCount;
	public:
	    Employee() { empCount = 0; }
	    
	    void start(){
			cout << "\n---------------------------Simon Aquarium and Pet Shop---------------------------\n\n";
		}
	    void endProgram(){
	        cout << "\n\nThanks for visiting, visit us again" << endl;
	        cout << "Reminder : Meet any one of our employees to proceed with your payment" << endl;
	    }
	    
	    static int makeEmpId(){
	        static int nextEmp = 1;
	        return nextEmp++;
	    }
	    void setEmp(string e_name){
	        if(empCount<10){
	            e_id[empCount] = makeEmpId();
	            this->e_name[empCount] = e_name;
	            empCount++;
	        }
			else { cout << "Maximum employee limit reached" << endl; }
	    }
	    void printEmp(){
	        cout << "---------Employee details---------\n" << endl;
	        for(int i=0; i<empCount; ++i){
	            cout << "Employee ID : " << e_id[i] << endl;
	            cout << "Employee Name : " << e_name[i] << endl;
	        }
	    }
};

class OrderDetails {
	public:
	    int o_id;
	    string o_date;
	    OrderDetails() { o_id = 0; o_date = ""; }
	    ~OrderDetails() {}
	    
	    static int makeOrderId(){
	        static int nextOrder = 201;
	        return nextOrder++;
	    }
	    void setOrderDet(){
    		o_id = makeOrderId();
    		time_t now = time(0);
    		char* dt = ctime(&now);
    		o_date = dt;
		}
};

class CustomerOrders : public Employee, public OrderDetails { //multiple inheritance
	private:
	    int custId;
	    string custName;
	    int totalPrice;
	public:
	    CustomerOrders(){
	        custId = 0;
	        custName = "";
	        totalPrice = 0;
	    }
	    string getCustName() { return custName; }
	    int getTotal() { return totalPrice; }
	    
	    static int makeCustID(){
	        static int nextCust = 1001;
	        return nextCust++;
	    }
	    void setCustomer(string c_name){
	        custId = makeCustID();
	        custName = c_name;
	        totalPrice = 0;
	    }
	    
	    void yourorder(Birds& bird, Dogs& dog, Aquarium& aqua);
	    void printOrderDet();
	    
	    friend int getorderid(CustomerOrders& order);
	    friend string getorderdate(CustomerOrders& order);
};
//friend functions:
int getorderid(CustomerOrders& order) { return order.o_id; } //defining a function outside class using a friend function
string getorderdate(CustomerOrders& order) { return order.o_date; } //defining a function outside class using a friend function

//functions declared inside CustomerOrders class which have no body are defined below :
void CustomerOrders::yourorder(Birds& bird, Dogs& dog, Aquarium& aqua) { //defining a function outside class without using a friend function
    int choice;
    while (true) {
        cout << "\n--------Select the product to buy--------\n" << endl;
        cout << "1. Buy Bird\n2. Buy Dog\n3. Buy Fish\n4. Exit\nEnter your choice (1,2,3 or 4): ";
        cin >> choice;
        if(cin.fail()){
            cin.clear(); cin.ignore(1000, '\n');
            cout << "Invalid input, please enter a number between 1 and 4" << endl;
            continue;
        }
        switch(choice){
            case 1:
                if(bird.available()){
                    cout << "\nBird price added to purchase amount" << endl;
                    bird.display();
                    totalPrice += bird.getPrice();
                    int cagechoice;
                    cout << "Do you want to buy a cage? (1.Yes 2.No): ";
                    cin >> cagechoice;
                    if (cagechoice == 1) { totalPrice += bird.getCagePrice(); }
                }
				else { cout << "Not available for sale" << endl; }
                break;
            case 2:
                if(dog.available()){
                    cout << "\nDog price added to purchase amount" << endl;
                    dog.display();
                    totalPrice += dog.getPrice();
                    int housechoice;
                    cout << "Do you want to buy a dog house? (1.Yes 2.No): ";
                    cin >> housechoice;
                    if (housechoice == 1) { totalPrice += dog.getHousePri(); }
                }
				else { cout << "Not available for sale" << endl; }
                break;
            case 3:
                if(aqua.available()){
                    cout << "\nFish price added to purchase amount" << endl;
                    aqua.display();
                    totalPrice += aqua.getPrice();
                    aqua.displayAqua();
                    int tankchoice;
                    cout << "Do you want to buy a fish tank? (1.Yes 2.No): ";
                    cin >> tankchoice;
                    if (tankchoice == 1) { totalPrice += aqua.getAquaPrice(); }
                }
				else { cout << "Not available for sale" << endl; }
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice, please try again" << endl;
        }
    }
}
void CustomerOrders::printOrderDet() { //defining a function outside class without using a friend function
    cout << "\n----------Order Details----------\n" << endl;
    cout << "Order ID : " << getorderid(*this) << endl;
    cout << "Order Date : " << getorderdate(*this) << endl;
    cout << "Customer ID : " << custId << endl;
    cout << "Customer Name : " << custName << endl;
    cout << "Total Purchase Amount : Rs. " << totalPrice << endl;
}

int main(){
    Employee e;
    e.start();
    Pet* petobj;
    Birds bird;
    bird.setPets("Parrot", "Macaw", 8000, 3);
    bird.setBirdCage(6, 6, 300);
    ++bird;
    petobj = &bird; //runtime polymorphism
    petobj->display();
    Dogs dog;
    dog.setPets("Bulldog", "English Bulldog", 2000, 5);
    dog.setHouse(6, 6, 200);
    !dog; //dog not available for sale
    Aquarium aqua;
    aqua.setPets("Goldfish", "Fancy Goldfish", 100, 1);
    aqua.setFish(2, 3, "Freshwater");
    aqua.setAqua("D_Tank", 20);
    petobj = &aqua; //runtime polymorphism
    petobj->display();
    CustomerOrders order;
    string name;
    cout << "Enter your name to place your order : ";
    getline(cin, name);
    order.setCustomer(name);
    order.setEmp("Peter");
    order.setEmp("John");
    order.setOrderDet();
    order.yourorder(bird, dog, aqua);
    order.printOrderDet();

    ofstream fout("orders.txt", ios::app); //file system to store details
    fout << "Customer: " << order.getCustName() << ", Total: Rs." << order.getTotal() << endl;
    fout.close();
    e.endProgram();
    return 0;
}

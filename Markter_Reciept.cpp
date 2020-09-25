#include<iostream>
#include <vector>
#include<fstream>
using namespace std;

template <class T>
class Receipt{
protected:
    string name;
    string new_item;
    vector <string> vec1;
    T price_of_items[10];
    T price;
    T discount=15;
    T elements;
    T age;
public: 
    void set(T aeg, string nae, T element){
        name=nae;
        age=aeg;
        elements=element;            
    }
    

    void displayitems(vector <string> &vec){
        cout<<"\nItems: \n";
        for (int i = 0; i < vec.size(); i++)
        {
           
            cout<<"Item "<<i<<" : "<<vec[i]<<"\n";
                       
        }
        cout<<"\n";

    }
    void placePrice(){
        for (int i = 0; i < elements; i++)
        {
            cout<<"Enter the price of item "<<i+1<<" : ";
            cin>>price_of_items[i];
        }

        price=0;

        for (int i = 0; i < elements; i++)
        {
            price+=price_of_items[i];            
        }

    }
    void setitem(){
        string item;

        for (int i = 0; i < elements+1; i++)
        {
            
            cout<<"\nEnter the "<<i<<" element: ";
            getline(cin,item);
            vec1.push_back(item);            
            
        }


        displayitems(vec1);  

        char choice;

        cout << "\nIs this the final choice ? (y/n) : ";
        cin >> choice;
        for (; choice !='y';)
        {
            T choice_in_num;
            cout << "\nEnter 1 to add and 2 to remove: ";
            cin >> choice_in_num;

            
            if (choice_in_num == 1)
            {
                cout << "\nEnter the item you want to add: ";
                cin>>new_item;
                vector<string>::iterator iter = vec1.end();
                vec1.insert(iter,new_item);
                displayitems(vec1);
                elements+=1;

            }
            else
            {
                int index;
                cout << "\nEnter the element number to remove: ";
                cin >> index;
                vec1.erase(vec1.begin()+(index));
                displayitems(vec1);
                elements-=1;
            }
            cout << "\nIs this the final choice (y/n) ?";
            cin >> choice;
        }      
        
        
    }
    void print(){

        ofstream fptr("Market_Program.txt");
        fptr<<"--------------------------------------------------------";
        fptr<<"\n\t\tName: "<<name;
        fptr<<"\n\n\t\tAge: "<<age;
        fptr<<"\n\n\t\tQuantity: "<<elements;
        for (int i = 1; i < elements+1; i++)
        {
            fptr<<"\n\n\t\tItem "<<i<<" : "<<vec1[i]<< " | Price : "<<price_of_items[i-1];
        }

        fptr<<"\n\n\t\tPrice : "<<price;
        fptr<<"\n\n\t\tPrice (With TAX, GST(5%)): "<<(float)((float)price+((float)price*0.05));
        fptr<<"\n\n\t\tDiscounted Price (15% off): "<<(float)(((float)((float)price+((float)price*0.05)))-(((float)((float)price+((float)price*0.05)))*0.15));
        
        
        fptr<<"\n\n\t\tThank you for Visiting Big Bazzar. Hope to see you soon!\n";
        fptr<<"----------------------------------------------------------";        
    
    }

};

int main()
{
    string name;
    int age,quan,elem;
    cout<<"\nEnter your name: ";
    getline(cin,name);
    cout<<"\nEnter your Age: ";
    cin>>age;
    Receipt <int>rec;
    cout<<"\nEnter the quantity of items: ";
    cin>>elem;
    rec.set(age,name,elem);
    rec.setitem();
    rec.placePrice();
    rec.print();
    
    return 0;
}

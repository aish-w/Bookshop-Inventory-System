#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Bookshop{
    public:
        void control_panel();
        void add_book();
        void display_book();
};
void Bookshop::control_panel(){
    system("cls");
    cout<<"Welcome to Bookshop"<<endl;
    cout<<endl;
    cout<<"\t 1.Add book"<<endl;
    cout<<"\t 2.Display book"<<endl;
    cout<<"\t 3.Check Individual book"<<endl;
    cout<<"\t 4.Update book"<<endl;
    cout<<"\t 5.Delete book"<<endl;
    cout<<"\t 6.Exit"<<endl;
}
void Bookshop::add_book(){
    system("cls");
    fstream file;
    int nocopy;
    string book_name,author_name,book_id;
    cout<<"\t Add Book";
    cout<<"Enter Book ID:";
    cin>>book_id;
    cout<<"Enter Book Name:";
    cin>>book_name;
    cout<<"Enter Author Name:";
    cin>>author_name;
    file.open("Book.txt",ios::out|ios::app);//ios::out for write and ios::out for append
    file<<book_id<<" "<<book_name<<" "<<author_name<<" "<<nocopy<<endl;//write data in file
    file.close();//close file
}
void Bookshop::display_book(){
    system("cls");
    fstream file;
    int no_copy;
    string book_name,author_name,book_id;
    cout<<"\t All Books"<<endl;
    //open file in read mode
    file.open("Book.txt",ios::in); //ios::in for read
    if(!file){
        cout<<"File not found"<<endl;
        return;
    }
    else{
        cout<<"\t Book Id\t Book Name\t Author Name\t No. of copy"<<endl;
        file>>book_id>>book_name>>author_name>>no_copy;
        while (!file.eof()){
            cout<<"\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<no_copy<<endl;
            file>>book_id>>book_name>>author_name>>no_copy;

        }
        file.close();
    }
}
void BookshopRecord(){
    int choice;
    char x;
    Bookshop book;
    while (1)
    {
        book.control_panel();
        cout<<"\t Enter Your Choice: ";
        cin>>choice;
        switch (choice){
            case 1:
                do{
                    book.add_book();
                    cout<<"Do you want to add more book?(y/n)";
                    cin>>x;
                }while (x=='y' || x=='Y');
                break;
            case 2:
                book.display_book();
                break;
                

        
        }
    }
}
int main(){
    BookshopRecord();
    return 0;
}

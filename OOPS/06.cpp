#include<iostream>
#include<string.h>
using namespace std;

class Book{
    
    int bookId;
    char author[20];

    public:

    int getBookId() { return bookId; }
    char * getAuthor() { return author; }

    Book(){
        bookId = 0;
        strcpy(author,"");
    }

    void setBook(){
        cout<<"Enter book id = ";
        cin>>bookId;
        cout<<"Enter author = ";
        cin>>author;
    }

    void getBook(){
        cout<<"Book Id = "<<bookId<<endl;
        cout<<"Author = "<<author<<endl;

    }

} B;


int main(){
    B.setBook();
    B.getBook();

    Book C;
    C=B;
    C.getBook();


}

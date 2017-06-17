/**
 * Binlei Wang
 * CIS 22C, Lab 7
 */

#include "Book.h"
#include "BST.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){

    Book bk;
    BST<Book> bt;
    string book1,book2;
    book1="books1.txt";
    book2="books2.txt";
    string input;
    string temp;
    string ttl;
    string auth;
    unsigned ISBN;
    double pr;
    ifstream fin;

    cout<<"Welcome to the Best Reads App!"<<endl<<endl;

    cout<<"Enter the name of the file for your book collection: ";
    getline(cin,input);
    while(input!="books1.txt"&&input!="books2.txt")
    {
        cout<<"Invalid file name!"<<endl<<endl;
        cout<<"Please enter the name of your file: ";
        cin>>input;
    }
    if(input=="books1.txt"){
    	fin.open(book1);
        while(!fin.fail())
            {
                getline(fin,ttl);
                bk.set_title(ttl);

                getline(fin,auth);
                bk.set_author(auth);

                getline(fin,temp);
                pr=atof(temp.c_str());
                bk.set_price(pr);

                getline(fin,temp);
                ISBN=atoi(temp.c_str());
                bk.set_isbn(ISBN);

                bt.insertData(bk);

                getline(fin,temp);
            }
        fin.close();
        }
    else{
    	fin.open(book2);
        while(!fin.fail())
            {
                getline(fin,ttl);
                bk.set_title(ttl);

                getline(fin,auth);
                bk.set_author(auth);

                getline(fin,temp);
                pr=atof(temp.c_str());
                bk.set_price(pr);

                getline(fin,temp);
                ISBN=atoi(temp.c_str());
                bk.set_isbn(ISBN);

                bt.insertData(bk);

                getline(fin,temp);
            }
        fin.close();
        }
    cout<<"What genre of literature is this: ";
    string genre;
    getline(cin,genre);

    cout<<endl<<"The number of books in the "<<genre<<" book tree is: "<<bt.size()<<endl;
    cout<<"The height of the "<<genre<<" book tree is: "<<bt.height()<<endl<<endl;
    cout<<"The first book in this collection is: "<<endl;
    cout<<bt.minimum()<<endl<<endl;
    cout<<"The last book in this collection is: "<<endl;
    cout<<bt.maximum()<<endl;

    Book remv;
    cout<<"Enter the information about the book you wish to remove."<<endl;
    cout<<"Title: ";
    getline(cin,ttl);
    remv.set_title(ttl);
    cout<<"Author: ";
    getline(cin,auth);
    remv.set_author(auth);

    while(!bt.search(remv))
    {
    	cout<<"Sorry, The "<<remv.get_title()<<" is not in this collection!"<<endl<<endl;
    	cout<<"Enter the title of a book you wish to remove: ";
    	getline(cin,ttl);
    	remv.set_title(ttl);
    	cout<<"Author: ";
    	getline(cin,auth);
    	remv.set_author(auth);
    	cout<<endl;
    }
	bt.removeData(remv);
	cout<<ttl<<" has been removed!"<<endl<<endl;
    cout<<"The number of books in the "<<genre<<" book tree is now: "<<bt.size()<<endl<<endl;
    cout<<"The books contained in this tree are now:"<<endl<<endl;
    bt.inOrderPrint(cout);

    Book adbk(ttl,auth,pr,ISBN);
    cout<<"Enter the title of a book you wish to insert: ";
    getline(cin,ttl);
    adbk.set_title(ttl);
    cout<<"Enter the author of the book: ";
    getline(cin,auth);
    adbk.set_author(auth);
    cout<<"Enter the price of the book: ";
    getline(cin,temp);
    pr=atof(temp.c_str());
    adbk.set_price(pr);
    cout<<"Enter the isbn number of the book: ";
    getline(cin,temp);
    ISBN=atoi(temp.c_str());
    adbk.set_isbn(ISBN);
    bt.insertData(adbk);
    cout<<endl;
    cout<<"The number of books in the "<<genre<<" book tree is now: "<<bt.size()<<endl<<endl;
    cout<<"The books contained in this tree are now: "<<endl<<endl;
    bt.inOrderPrint(cout);
    cout<<endl;

    cout<<"Would you like to write this collection to a file? (yes/no): ";
    string yn;
    getline(cin,yn);
    if(yn=="yes"||yn=="Yes"||yn=="y"||yn=="Y")
    {
    	cout<<"Enter the file name: ";
    	getline(cin,temp);
    	ofstream fout(temp);
    	bt.preOrderPrint(fout);
    	fout.close();
    	cout<<"The data is now written to the fime "<<temp;
    }

    cout<<endl;
    cout<<"Thank you! Goodbye!";

}

/**************************************************Book1.txt Console Out:

Welcome to the Best Reads App!

Enter the name of the file for your book collection: books1.txt
What genre of literature is this: 19th Century British

The number of books in the 19th Century British book tree is: 9
The height of the 19th Century British book tree is: 4

The first book in this collection is:
A Room with a View by E.M. Forster
7.5
1177889



The last book in this collection is:
Vanity Fair by William Thackery
11.99
3456839


Enter the information about the book you wish to remove.
Title: The Castle of Otranto
Author: Horace Walpole
Sorry, The The Castle of Otranto is not in this collection!

Enter the title of a book you wish to remove: Gulliver's Travels
Author: Jonathan Swift

Gulliver's Travels has been removed!

The number of books in the 19th Century British book tree is now: 8

The books contained in this tree are now:

A Room with a View by E.M. Forster
7.5
1177889

Bleak House by Charles Dickens
8.99
3567897

Jane Eyre by Charlotte Bronte
7.9
2345674

Lady Audley's Secret by Mary Elizabeth Braddon
5.5
1212134

Middlemarch by George Elliot
12.5
1256743

Pride and Prejudice  by Jane Austen
10.95
2345678

The Woman in White by Wilkie Collins
10.75
3256789

Vanity Fair by William Thackery
11.99
3456839

Enter the title of a book you wish to insert: The Castle of Otranto
Enter the author of the book: Horace Walpole
Enter the price of the book: 6.99
Enter the isbn number of the book: 3434562

The number of books in the 19th Century British book tree is now: 9

The books contained in this tree are now:

A Room with a View by E.M. Forster
7.5
1177889

Bleak House by Charles Dickens
8.99
3567897

Jane Eyre by Charlotte Bronte
7.9
2345674

Lady Audley's Secret by Mary Elizabeth Braddon
5.5
1212134

Middlemarch by George Elliot
12.5
1256743

Pride and Prejudice  by Jane Austen
10.95
2345678

The Castle of Otranto by Horace Walpole
6.99
3434562

The Woman in White by Wilkie Collins
10.75
3256789

Vanity Fair by William Thackery
11.99
3456839


Would you like to write this collection to a file? (yes/no): y
Enter the file name: output.txt
The data is now written to the file output.txt

Thank you! Goodbye!
*/



/***********************************************books2.txt Console Out:


Welcome to the Best Reads App!

Enter the name of the file for your book collection: books2.txt
What genre of literature is this: Latin-American

The number of books in the Latin-American book tree is: 9
The height of the Latin-American book tree is: 4

The first book in this collection is:
Cajas de carton by Francisco Jimenez
10.99
2256839



The last book in this collection is:
Pedro Paramo  by Juan Rulfo
8.95
1123456


Enter the information about the book you wish to remove.
Title: Cien anos de soledad
Author: Gabriel Garcia Marquez
Cien anos de soledad has been removed!

The number of books in the Latin-American book tree is now: 8

The books contained in this tree are now:

Cajas de carton by Francisco Jimenez
10.99
2256839

Como agua para chocolate by Laura Esquivel
6.9
2375689

El alquimista by Paulo Coelho
8.5
3212132

El beso de la mujer arana by Manuel Puig
7.75
3456743

La casa de los espiritus by Isabel Allende
7.5
2117889

La casa en Mango Street by Sandra Cisneros
6.8
1134231

Los diarios de motocicleta by Ernesto Che Guevara
10.99
2241174

Pedro Paramo  by Juan Rulfo
8.95
1123456

Enter the title of a book you wish to insert: Oficio de tinieblas
Enter the author of the book: Rosario Castellanos
Enter the price of the book: 9.95
Enter the isbn number of the book: 1234567

The number of books in the Latin-American book tree is now: 9

The books contained in this tree are now:

Cajas de carton by Francisco Jimenez
10.99
2256839

Como agua para chocolate by Laura Esquivel
6.9
2375689

El alquimista by Paulo Coelho
8.5
3212132

El beso de la mujer arana by Manuel Puig
7.75
3456743

La casa de los espiritus by Isabel Allende
7.5
2117889

La casa en Mango Street by Sandra Cisneros
6.8
1134231

Los diarios de motocicleta by Ernesto Che Guevara
10.99
2241174

Oficio de tinieblas by Rosario Castellanos
9.95
1234567

Pedro Paramo  by Juan Rulfo
8.95
1123456


Would you like to write this collection to a file? (yes/no): y
Enter the file name: output.txt
The data is now written to the file output.txt

Thank you! Goodbye!

*/

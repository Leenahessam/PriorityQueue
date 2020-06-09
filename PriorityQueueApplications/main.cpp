#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
/*--------------------------------------------------------------------*/
struct node {
   string data;
   int priority;
   struct node *next;
};
/*---------------------------------------------------------------------*/
node *front = NULL;
/*--------------------------------------------------------------------*/
void insertPQ(string data, int priority) {
   node *temp, *ptr;
   temp = new node;
   temp->data = data;
   temp->priority = priority;
   if (front == NULL || priority < front->priority) {
      temp->next = front;
      front = temp;
   } else {
      ptr = front;
      while (ptr->next != NULL && ptr->next->priority <= priority)
      ptr=ptr->next;
      temp->next = ptr->next;
      ptr->next = temp;
   }
}
/*-----------------------------------------------------------------------*/
void deletePQ() {
   node *temp;
   if(front == NULL)
   cout<<"Error" << endl;
   else {
      temp = front;
      front = front->next;
      free(temp);
   }
}
/*-----------------------------------------------------------------------*/
void displayPQ() {
   node *ptr;
   ptr = front;
   if (front == NULL)
   {
        cout<<"Empty Queue" << endl;
   }
   else {
      cout<<"Queue elements in decreasing priority are: \n";
      while(ptr != NULL) {
         cout<<ptr->data<<" ";
         ptr = ptr->next;
      }
      cout<<endl;
   }
}
/*---------------------------------------------------------------------------*/
int main() {
    string data;
    int ch, priority;
   cout<<"1.Insert" << endl;
   cout<<"2.Delete" << endl;
   cout<<"3.Display" << endl;
   cout<<"4.Exit" << endl;

   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
            cout<<"Enter Word : "<<endl;
            cin>>data;
            cout<<"Enter Word Priority : "<<endl;
            cin>>priority;
            insertPQ(data, priority);
            break;

         case 2:
            deletePQ();
            break;

         case 3:
            displayPQ();
            break;

         case 4:
            cout<<"Exit"<<endl;
            break;

         default :
            cout<<"Wrong choice\n";
      }
   }while(ch != 4);
      return 0;
}

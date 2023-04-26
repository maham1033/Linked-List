#include<iostream>
#include<stdio.h>
using namespace::std;

class node
{
public:
    int data;
    node* link;
};

class Linklist
{
    node* head;
    
public:
    Linklist()
    {
        head=NULL;
    }
    
    // insert at the start of the list
    void insertH(int data)
    {
       node *newNode=new node();
       newNode->data=data;
       newNode->link=NULL;
       newNode->link=head;
       head=newNode;	
        
    }
    // insert at the end of the list
    void insertT(int data)
    {
    	node* newptr=new node();
    	newptr->data=data;
    	newptr->link=NULL;
    	if(head!=NULL){
    		node* e=head;
    		while (e->link!=NULL){
    			e=e->link;
			}
			e->link=newptr;
		}
		else{
			head=newptr;
		}
        
        
    }
    
    // position starting from 0
    void insertAfter(int data,int pos)
    {
        node* newptr = new node();
	newptr->data = data;
	newptr->link = NULL;
	 if(pos < 0) {
        cout<<"\n Invalid Postion.try next!!";
      } 
	  else if (pos == 0) {
        newptr->link = head;
        head = newptr;
      } else {
        
        node* hd = head;
        for(int i = 1; i < pos; i++) {
          if(hd!= NULL) {
            hd = hd->link;
          }
        }
     
        if(hd != NULL) {
          newptr->link = hd->link;
          hd->link = newptr;  
        } else {
          cout<<"\nPrevious is NULL!!";
        }       
      }
	
        
        
        
    }
    // delete from the head/start of the list
    void deleteH()
    {
    	if(head!=NULL){
    		node* hd=head;
    		head=head->link;
    		delete hd;
		}
 
        
    }
    
    // delete from the tail of the list and return the deleted value
    void deleteT()
    {
    	if(head!=NULL){
    		if(head->link==NULL){
    			head=NULL;
    		
			}
			else{
				node *hd=head;
				while(hd->link->link!=NULL){
					hd=hd->link;
				}
				node* lnode=hd->link;
				hd->link=NULL;
				delete lnode;
			}
		}
        
        
        
       
    }
    
    
    //returns the no of node  being searched
    int search(int data)
    { node* hd = head;
      int count = 0;
      int i = -1;   // index

      if(hd != NULL) {
        while(hd != NULL) {
          i++;
          if(hd ->data == data) {
            count++;
            break;
          }
          hd = hd->link;
        }
        if (count == 1) {
          cout<<endl<<data<<" is  at index "<<i<<".\n";
        } 
		else{
          cout<<endl<<data<<" is not  in the list.\n";
        }
      } else {
        cout<<endl<<"Empty list\n";
      }
    } 

    
    void display()
    {
        node * tptr=head;
        while(tptr!=NULL)
        {
            cout<<tptr->data<<" -> ";
            tptr=tptr->link;
            
        }
        cout<<"NULL\n"    ;
    }
    
   
    int isEmpty()
    {
        if(head==NULL)
            return 1;  // for true
        else return 0;  // for false
    }
};




    
int main()
{
   
    
	Linklist lis;
	cout<<"Insertion at the beginning of list i.e Head";
	lis.insertH(3);
	lis.insertH(4);
	lis.insertH(5);	 
	lis.insertH(6);
	cout<<endl<<"linklist is: ";
	lis.display();
	cout<<endl<<"Insertion at last of list i.e Tail";
	lis.insertT(2);
	cout<<endl<<"linklist is: ";
	lis.display();
	cout<<endl<<"Head Deletion";
	lis.deleteH();
	cout<<endl<<"linklist is: ";
	lis.display();
	cout<<endl<<"Tail Deletion:";
	lis.deleteT();
	cout<<endl<<"linklist is: ";
	lis.display();
	lis.search(4);
	cout<<endl<<"At Specific Postion Insertion will be:";
	lis.insertAfter(2,1);
	cout<<endl<<"linklist is: ";
	lis.display();
    
    
}


//Stack Using Array 
#include <iostream> 
using namespace std; 
class stack 
{ 
    public: 
    int size; 
    int *arr; 
    int top; 
     stack(int s) 
     { 
         this->size=s; 
         this->top=-1; 
         arr=new int [size]; 
     } 
  bool isEmpty(){ 
      return top==-1?true:false; 
  } 
  bool isFull(){ 
      return top==size-1?true:false; 
  } 
   void pop() 
   { 
       if(!isEmpty()){ 
       cout<<arr[top]<<endl; 
        top--;        
       } 
       else 
       cout<<"*Stack is Empty*"<<endl; 
       return; 
   } 
   void push(int data) 
   { 
       if(!isFull()) 
       { 
           top++; 
           arr[top]=data; 
       } 
       else 
       cout<<"*Stack is Full*"<<endl; 
       return; 
   } 
   void peak() 
   { 
       if(!isEmpty()) 
       cout<<arr[top]; 
       else 
       cout<<"*Stack is Empty*"<<endl; 
   } 
}; 
void stkopr() 
{ 
    cout<<"Enter the size of the Stack: "<<endl; 
    int s; 
    cin>>s; 
    stack st(s); 
     while(1){ 
    cout<<"Enter the Operation to perform: "<<endl; 
    cout<<"1. Push"<<endl; 
    cout<<"2. Pop"<<endl; 
    cout<<"3. Peak"<<endl; 
    cout<<"4. Is Full"<<endl; 
    cout<<"5. Is Empty"<<endl; 
    cout<<"6. Exit"<<endl; 
      int opt; 
      cin>>opt; 
      if (opt==6)return; 
      switch (opt){ 
      case 1:{ cout<<"Enter the data to Push: "<<endl; 
      int d; 
      cin>>d; 
      st.push(d); 
       break; 
      } 
      case 2: st.pop(); break; 
      case 3: st.peak(); break; 
      case 4: st.isFull()?cout<<"True"<<endl:cout<<"False"<<endl; break; 
      case 5: st.isEmpty()?cout<<"True"<<endl:cout<<"False"<<endl; break; 
      } 
    } 
} 
int main() { 
     while(1) 
     { 
          
         int opt; 
         cout<<"Enter the Operation to perform: "<<endl; 
         cout<<"1. Create a new stack"<<endl; 
         cout<<"2. Exit"<<endl; 
         cin>>opt; 
         if (opt==2)break; 
         switch(opt) 
         { 
             case 1:stkopr();break; 
             default : cout<<"Invalid Option";break; 
         } 
     } 
    return 0; 
}



//Stack Using LinkedList 
#include <iostream> 
using namespace std; 
class node 
{ 
    public: 
    int data; 
    node* next; 
    node(int d) 
    { 
        this->data=d; 
        this->next=NULL; 
    } 
}; 
class stack 
{ 
    public: 
    node* head; 
     stack() 
     { 
         this->head=NULL; 
     } 
  bool isEmpty(){ 
      return head==NULL?true:false; 
  } 
   void pop() 
   { 
       if(!isEmpty()){ 
        node* temp=head; 
        head=head->next; 
        temp->next=NULL; 
          delete temp; 
       } 
       else 
       cout<<"*Stack is Empty*"<<endl; 
       return; 
   } 
   void push(int data) 
   { 
       if(isEmpty()) 
       { 
           head=new node(data); 
       } 
       else{ 
           node* temp=new node( data); 
           temp->next=head; 
           head=temp; 
           temp->next=NULL; 
           delete temp; 
       } 
   } 
   void peak() 
   { 
       if(!isEmpty()) 
       cout<<head->data<<endl; 
       else 
       cout<<"*Stack is Empty*"<<endl; 
   } 
}; 
void stkopr() 
{ 
    stack st; 
     while(1){ 
    cout<<"Enter the Operation to perform: "<<endl; 
    cout<<"1. Push"<<endl; 
    cout<<"2. Pop"<<endl; 
    cout<<"3. Peak"<<endl; 
    cout<<"4. Is Empty"<<endl; 
    cout<<"5. Exit"<<endl; 
      int opt; 
      cin>>opt; 
      if (opt==5)return; 
      switch (opt){ 
      case 1:{  
         cout<<"Enter the data to Push: "<<endl; 
         int d; 
         cin>>d; 
         st.push(d); 
         break; 
      } 
      case 2: st.pop(); break; 
      case 3: st.peak(); break; 
      case 4: st.isEmpty()?cout<<"True"<<endl:cout<<"False"<<endl; break; 
      } 
    } 
} 
int main() { 
     while(1) 
     { 
          
         int opt; 
         cout<<"Enter the Operation to perform: "<<endl; 
         cout<<"1. Create a new stack"<<endl; 
         cout<<"2. Exit"<<endl; 
         cin>>opt; 
         if (opt==2)break; 
         switch(opt) 
         { 
             case 1:stkopr();break; 
             default : cout<<"Invalid Option"<<endl;break; 
         } 
     } 
    return 0; 
}




//Tower of Hanoi 
#include <iostream> 
using namespace std; 
void toh ( int n , char s , char h , char d) 
{ 
    if(n==1){ 
    cout<<"Move Disk "<<n<<" from "<<s<<" to "<<d<<endl; 
    return; 
    } 
    toh(n-1,s,d,h); 
    cout<<"Move Disk "<<n<<" from "<<s<<" to "<<d<<endl; 
    toh(n-1,h,s,d); 
} 
int main() { 
     int n; 
     cout<<"Enter the Number of rings present in Source Disk: "<<endl; 
     cin>>n; 
     cout<<"Total Steps: "<<endl; 
     cout<< (1<<n)-1<<endl<<endl<<"Steps: "<<endl; 
     toh(n,'S','H','D'); 
    return 0; 
}




//Circular Queue
#include<iostream> 
using namespace std; 
 
struct Node 
{ 
    int data; 
    struct Node *next; 
}; 
 
 
Node *front = NULL; 
Node *rear = NULL; 
 
void enqueue(int val) 
{ 
    if(front==NULL || rear==NULL) 
    { 
        Node *newNode; 
        newNode = new Node; 
 
        newNode->data = val; 
        newNode->next = NULL; 
        front = newNode; 
        rear = newNode; 
    } 
    else 
    { 
        Node *newNode; 
        newNode = new Node; 
        newNode->data = val; 
        rear->next = newNode; 
        newNode->next = front; 
        rear = newNode; 
    } 
} 
void dequeue() 
{ 
    Node *n; 
    n = front; 
    front = front->next; 
    delete(n); 
} 
void display() 
{ 
    Node *ptr; 
    ptr = front; 
    do 
    { 
        cout<< ptr->data <<" "; 
        ptr = ptr->next; 
    }while(ptr != rear->next); 
 
    cout<<endl; 
    cout<<endl; 
 
} 
void qfront () 
{ 
    if(front) 
    cout<<front->data<<endl; 
    else 
    cout<<"Queue is empty "<<endl; 
} 
 
int main(void) 
{ 
    int ch; 
    do{ 
    cout<<"Enter the Operaton to Perform : "<<endl; 
    cout<<"1. Enqueue"<<endl; 
    cout<<"2. Dequeue"<<endl; 
    cout<<"3. Display"<<endl; 
    cout<<"4. Front"<<endl; 
    cout<<"5. Exit"<<endl; 
    cin>>ch; 
    switch(ch) 
    { 
        case 1: cout<<"Enter the data to insert"<<endl; 
        int d; 
        cin>>d; 
        enqueue(d); 
        break; 
        case 2:dequeue();break; 
        case 3: display();break; 
        case 4: qfront(); break; 
    } 
    }while(ch!=5); 
     
    return 0; 
}




//PolyNomial Sum
#include <iostream> 
#include <iomanip.h> 
using namespace std; 
 
struct poly { 
    int coeff; 
    int pow_val; 
    poly* next; 
}; 
 
class add { 
    poly *poly1, *poly2, *poly3; 
 
public: 
    add() { poly1 = poly2 = poly3 = NULL; } 
    void addpoly(); 
    void display(); 
}; 
 
void add::addpoly() 
{ 
    int i, p; 
    poly *newl = NULL, *end = NULL; 
    cout << "Enter highest power for x\n"; cin >> p; 
    //Read first poly 
    cout << "\nFirst Polynomial\n"; for (i = p; i >= 0; i--) { 
        newl = new poly; 
        newl->pow_val = p; 
        cout << "Enter Co-efficient for degree" << i << ":: "; cin >> newl->coeff; 
        newl->next = NULL; 
        if (poly1 == NULL) 
            poly1 = newl; 
        else 
            end->next = newl; 
        end = newl; 
    } 
 
    //Read Second poly 
    cout << "\n\nSecond Polynomial\n"; end = NULL; for (i = p; i >= 0; i--) { 
        newl = new poly; 
        newl->pow_val = p; 
        cout << "Enter Co-efficient for degree" << i << ":: "; cin >> newl->coeff; 
        newl->next = NULL; 
        if (poly2 == NULL) 
            poly2 = newl; 
        else 
            end->next = newl; 
        end = newl; 
    } 
 
    //Addition Logic 
    poly *p1 = poly1, *p2 = poly2; 
    end = NULL; 
    while (p1 != NULL && p2 != NULL) { 
        if (p1->pow_val == p2->pow_val) { 
            newl = new poly; 
            newl->pow_val = p--; 
            newl->coeff = p1->coeff + p2->coeff; 
            newl->next = NULL; 
            if (poly3 == NULL) 
                poly3 = newl; 
            else 
                end->next = newl; 
            end = newl; 
        } 
        p1 = p1->next; 
        p2 = p2->next; 
    } 
} 
 
void add::display() 
{ 
    poly* t = poly3; 
    cout << "\n\nAnswer after addition is : "; 
    while (t != NULL) { 
        cout.setf(ios::showpos); 
        cout << t->coeff; 
        cout.unsetf(ios::showpos); 
        cout << "X" << t->pow_val; 
        t = t->next; 
    } 
} 
int main() 
{ 
    add obj; 
    obj.addpoly(); 
    obj.display(); 
}




//Priority Queue  
 
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
using namespace std; 
struct node 
{ 
 int priority; 
 int data; 
 struct node *next; 
}; 
class Priority_Queue 
{ 
    private: 
        node *front; 
    public: 
        Priority_Queue() 
        { 
            front = NULL; 
        } 
        void insert(int item, int priority) 
        { 
            node *tmp, *q; 
            tmp = new node; 
            tmp->data = item; 
            tmp->priority = priority; 
            if (front == NULL || priority < front->priority) 
            { 
                tmp->next = front; 
                front = tmp; 
            } 
            else 
            { 
                q = front; 
                while (q->next != NULL && q->next->priority <= priority) 
                    q=q->next; 
                tmp->next = q->next; 
                q->next = tmp; 
            } 
        } 
        void del() 
        { 
            node *tmp; 
            if(front == NULL) 
                cout<<"Queue Underflow\n"; 
            else 
            { 
                tmp = front; 
                cout<<"Deleted item is: "<<tmp->data<<endl; 
                front = front->next; 
                free(tmp); 
            } 
        } 
        void display() 
        { 
            node *ptr; 
            ptr = front; 
            if (front == NULL) 
                cout<<"Queue is empty\n"; 
            else 
            { cout<<"Queue is :\n"; 
                cout<<"Priority       Item\n"; 
                while(ptr != NULL) 
                { 
                    cout<<ptr->priority<<"                 "<<ptr->data<<endl; 
                    ptr = ptr->next; 
                } 
            } 
        } 
}; 
int main() 
{ 
    int choice, item, priority; 
    Priority_Queue pq;  
    do 
    { 
        cout<<"1.Insert\n"; 
        cout<<"2.Delete\n"; 
        cout<<"3.Display\n"; 
        cout<<"4.Quit\n"; 
        cout<<"Enter your choice : ";  
        cin>>choice; 
        switch(choice) 
        { 
        case 1: 
            cout<<"Input the item value to be added in the queue : "; 
            cin>>item; 
            cout<<"Enter its priority : "; 
            cin>>priority; 
            pq.insert(item, priority); 
            break; 
        case 2: 
            pq.del(); 
            break; 
        case 3: 
            pq.display(); 
            break; 
        case 4: 
            break; 
        default : 
            cout<<"Wrong choice\n"; 
        } 
    } 
    while(choice != 4); 
    return 0; 
}





//Bubble Sort
#include<bits/stdc++.h>
using namespace std;
void bubblesort(int *arr, int n)
{
    for(int i=0;i<n;i++)
     for ( int j=0;j<n-1-i;j++)
     if(arr[j+1]<arr[j])
     swap(arr[j+1],arr[j]);
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Before"<<endl;
    display(arr,n);
    bubblesort(arr,n);
    cout<<"After"<<endl;
    display(arr,n);
    return 0;
}




//Insertion Sort
#include<bits/stdc++.h>
using namespace std;
void Insertionsort(int *arr, int n)
{
    int i, key,j;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Before"<<endl;
    display(arr,n);
    Insertionsort(arr,n);
    cout<<"After"<<endl;
    display(arr,n);
    return 0;
}




//Selection Sort
#include<bits/stdc++.h>
using namespace std;
void SelectionSort(int *arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
        if(min_idx!=i)
            swap(arr[min_idx], arr[i]);
    }
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Before"<<endl;
    display(arr,n);
    SelectionSort(arr,n);
    cout<<"After"<<endl;
    display(arr,n);
    return 0;
}



//Quick Sort
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int l,int h)
{
  int pivot=arr[h];
  int i=l-1;
  for(int j=l;j<h;j++)
    {
      if(arr[j]<pivot)
      {
        i++;
        swap(arr[i],arr[j]);
      }
    }
  swap(arr[i+1],arr[h]);
  return i+1;
}
void quicksort(int arr[],int l,int h)
{
  if(l<h){
  int p= partition(arr,l,h);
  quicksort(arr,l,p-1);
  quicksort(arr,p+1,h);
    }
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Before"<<endl;
    display(arr,n);
    quicksort(arr,0,n-1);
    cout<<"After"<<endl;
    display(arr,n);
    return 0;
}



//Merge Sort
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int h) {
  
  int n1 = m - l + 1;
  int n2 = h - m;
  
  int a[n1], b[n2];
  
  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  
  for (int i = 0; i < n2; i++)
    b[i] = arr[m + i + 1];
  
  int i = 0, j = 0, k = l;
  
  while (i < n1 && j < n2) {
    if (a[i] <= b[j]) {
      arr[k] = a[i];
      i++;
    } else {
      arr[k] = b[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    arr[k] = a[i];
    i++;
    k++;
  }
  
  while (j < n2) {
    arr[k] = b[j];
    j++;
    k++;
  }
}
void mergesort(int arr[], int l, int h) {
  if (l < h) {
    int m = (l + h) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, h);
    merge(arr, l, m, h);
  }
}
void display(int *arr,int n)
{
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Before"<<endl;
    display(arr,n);
    mergesort(arr,0,n-1);
    cout<<"After"<<endl;
    display(arr,n);
    return 0;
}




//BST Creation Deletion
#include <iostream>
using namespace std;
class treenode
{
	public:
	treenode*left;
	treenode*right;
	int data;
	treenode(int d)
	{
		this->data= d;
		this->left=NULL;
		this->right=NULL;
	}
};
treenode* bstcreation(treenode *root,int d)
{
   if(root==NULL)
   	return new treenode(d);
   if(d>root->data)
   	root->right=bstcreation(root->right,d);
   if(d<root->data)
   	root->left=bstcreation(root->left,d);
   return root;
}
int minin(treenode* root)
{
    treenode *temp = root;
    while(temp->left != NULL)temp = temp->left;
    return temp->data;
}
treenode* deletenode(treenode* root, int d)
{
    if(root == NULL)
        return NULL;
    if(root->data < d)
        root->right = deletenode(root->right,d);
    else if(root->data > d)
        root->left = deletenode(root->left,d);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            treenode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            treenode *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightMin = minin(root->right);
            root->data = rightMin;
            root->right = deletenode(root->right,rightMin);
        }

    }
    return root;
}
void inordertravesal(treenode*root)
{
	if(!root)return;
        inordertravesal(root->left);
        cout<<root->data<<" ";
        inordertravesal(root->right);
}
void preordertravesal(treenode*root)
{
	if(!root)return;
        cout<<root->data<<" ";
        preordertravesal(root->left);
        preordertravesal(root->right);
}
void postordertravesal(treenode*root)
{
	if(!root)return;
        postordertravesal(root->left);
        postordertravesal(root->right);
        cout<<root->data<<" ";
}
int main()
{
	treenode* root=NULL;
	int ch;
	do{
	    cout<<"Enter the choice to perform in BST:"<<endl;
	    cout<<"1. Insert the node"<<endl;
	    cout<<"2. Delete a node"<<endl;
	    cout<<"3. Print in Inorder Traversal"<<endl;
	    cout<<"4. Print in Preorder Traversal"<<endl;
	    cout<<"5. Print in Postorder Traversal"<<endl;
	    cout<<"6. Exit"<<endl;
	    cin>>ch;
	    switch(ch)
	    {
	        case 1 : cout<<endl<<"Enter the data to insert"<<endl;
	        int d;
	        cin>>d;
	        root = bstcreation(root,d);break;
	        case 2 : cout<<endl<<"Enter the node to delete "<<endl;
	        int a;
	        cin>>a;
	        root = deletenode(root,a);break;
	        case 3 : cout<<"Inorder Traversal"<<endl;
            inordertravesal(root);break;
	        case 4 :cout<<endl<<"Preorder Traversal"<<endl;
            preordertravesal(root);break;
	        case 5 :cout<<endl<<"Postorder Traversal"<<endl;
            postordertravesal(root);break;
	        case 6 :break;
	        default : cout<<endl<<"*Indid Input*"<<endl;
	        
	    }
	}while(ch!=6);
}

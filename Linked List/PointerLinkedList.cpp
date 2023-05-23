# include <iostream>
using namespace std;
template  <class objectType>
class List;

template  <class objectType>
class Component
{
    objectType item;
    Component *nextItem;
    friend class List <objectType>;

    template <class T>
    friend ostream& operator << (ostream& stream, Component <T>& node);

    template <class T>
    friend ostream& operator << (ostream& stream, List<T>&lst);
    public:
    Component(): nextItem(NULL){};
    Component(const objectType& dataItem): item(dataItem), nextItem(NULL){};

};

template  <class objectType>
class List{
Component <objectType> *first;

template <class T>
friend ostream& operator << (ostream& stream, List<T>&lst);
public:

List(){
first = NULL;
}
List(objectType listItems[], int N){
if (N<1)return;
first = new Component <objectType> (listItems[0]);
int i=1;
for (Component<objectType> *ptr = first; i<N; i++,ptr=ptr->nextItem)
    ptr->nextItem = new Component<objectType>(listItems[i]);
}


List (const List& lst){
Component<objectType> *ptr, *LstPtr;
if (lst.first == NULL) ptr= first =NULL;
else {
    ptr = first = new Component <objectType> ((lst.first)->item);
    for (LstPtr = lst.first->nextItem; LstPtr!=NULL; LstPtr=LstPtr->nextItem)
    {
        ptr->nextItem = new Component<objectType>(LstPtr->item);
        ptr = ptr->nextItem;
    }
}
}

~List(){
initialize();
}

void initialize(){
Component<objectType> *pre, *ptr=first;
while (ptr!=NULL)
{
    pre=ptr;
    ptr=ptr->nextItem;
    delete pre;
}
first = NULL;
}

int Empty()
{
    return first=NULL;
}


int AppendItem(const objectType& obj){
Component <objectType> *ptr, *p;
ptr = new Component<objectType>(obj);
if (ptr == NULL) return 0;
if (first == NULL) first = ptr;
else {
    for (p=first; p->next!=NULL; p=p->nextItem);
    p->nextItem = ptr;
}
return 1;
}

int deleteItem(const int& PositionOfItem)
{
    Component <objectType> *ptr, *dptr;
    if (first == NULL || PositionOfItem<1)return 0;
    if (PositionOfItem == 1)
    {
        ptr = first;
        first = first ->nextItem;
        delete ptr;
        return 1;
    }
    int i = 2;
    for (ptr = first; ptr->nextItem!=NULL && i<PositionOfItem; ptr=ptr->nextItem)
        i++;
    if(ptr->nextItem!=NULL)
    {
        dptr=ptr->nextItem;
        ptr->nextItem=ptr->nextItem->nextItem;
        delete dptr;
        return 1;
    }
    return 0;
}

Component <objectType> *LocateItem (const objectType& obj, int& PositionOfItem)
{
    Component <objectType> *ptr;
    PositionOfItem =1;
    for (ptr = first; ptr!=NULL && (!((ptr->item==obj))););
    ptr=ptr->nextItem;
    PositionOfItem++;
    if (ptr==NULL){
        PositionOfItem = 0;
        return NULL;
    }
    return ptr;
}

Component <objectType> *LastObject (objectType& obj){
Component<objectType> *ptr;
if (first==NULL) return NULL;
for (ptr=first; ptr->nextItem!=NULL;ptr=ptr->nextItem);
obj=ptr->item;
return ptr;
}


Component <objectType> *FirstObject (objectType& obj){
if (first!=NULL) obj=first->item;
return first;
}

int Length(){
Component<objectType> *ptr;
int len = 0;
for (ptr=first; ptr!=NULL; ptr=ptr->nextItem)
    len++;
return len;

}
List <objectType> operator= (const List& lst){
Component <objectType> *ptr, *LstPtr, *dptr;
if(lst.first==NULL)
    first = new Component <objectType> ((lst.first)->item);
else first ->item = (lst.first)->item;
ptr = first;
LstPtr = first;
while (ptr->nextItem!=NULL && LstPtr->nextItem!=NULL)
{
    ptr=ptr->nextItem;
    LstPtr = LstPtr->nextItem;
    ptr->item=LstPtr->item;
}

while(LstPtr->nextItem!=NULL)
{
    LstPtr= LstPtr->nextItem;
    ptr->nextItem= new Component <objectType>(LstPtr->item);
    ptr=ptr->nextItem;
}

while (ptr->nextItem!=NULL)
{
    dptr = ptr->nextItem;
    ptr=dptr->nextItem;
    delete dptr;
}



}

};

int main()
{
    int items[]={10,20,30,40,50};
    List <int> LIST(items, 5), list1;




};



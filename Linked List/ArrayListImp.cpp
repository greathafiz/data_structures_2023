# include <iostream>
using namespace std;
# define MAX_Size 30
template  <class objectType>

class List{
objectType *item;
int last_item,Size;

template <class T>
friend ostream& operator << (ostream& stream, const List<T>&lst);
public:
    List()  // A No-argument constructor
    {
        last_item = -1;
        Size = MAX_Size;
        item = new objectType[Size];

    }
    List (int Length) // One parameter constructor
    {
        last_item = -1;
        Size = Length;
        item = new objectType[Size];
    }

    int Empty() // To check if List is empty
    {
     return last_item<0;
    }

    int full() // To check if List is full
    {
        return last_item == (Size - 1);
    }

    int Length()  // To check if size or length of List
    {
        return last_item+1;
    }

    void initialize (int ListSize)  // To re-initialize (empty) the list
    {
        last_item = -1;

    }

    int AddItems (const objectType& obj, int PositionOfItem)  // Add items into the List to a particular position
    {
        --PositionOfItem; // Indexing starts from 0 in c++. Element in Position N will be in index --N
        if (PositionOfItem>(-1) && PositionOfItem <= last_item + 1 && last_item + 1 <Size)
        {
            for (int i = ++last_item; i> PositionOfItem; i--)
                item[i] = item [i-1];
            item[PositionOfItem] = obj;
            return 1;
        }
    }

    int append (const objectType &obj) // Add item to the tail of the list
    {
        if (last_item >= Size -1)
            return 0;
        item[++last_item] = obj;
        return 1;
    }

    void deleteItem(int PositionOfItem)  // delete an item from the list
    {
        --PositionOfItem; // Indexing starts from 0 in c++. Element in Position N will be in index --N
        if(!(PositionOfItem>=0 && PositionOfItem <=last_item))
            return;
        for (int j = PositionOfItem; j<=last_item; j++)
            item[j]=item[j+1];
        --last_item;
    }

     int retrieveItem( int PositionOfItem)  // Retrieve an item at a specified position
    {
        --PositionOfItem; // Indexing starts from 0 in c++. Element in Position N will be in index --N
        if((PositionOfItem<0 || PositionOfItem > Size -1 || PositionOfItem>last_item))
            return 0;
        //objectType *objPtr = item[PositionOfItem];
        return item[PositionOfItem];
    }


};

int main()
{
    List<int> l(5);
    l.append(0);
    l.append(1);
    l.append(2);
    l.append(3);


//It is advisable to execute (uncomment) the codes below one at a time
   cout<<l.retrieveItem(4);
//    cout<<l.Length()<<"\n";
//    cout<<l.full()<<"\n";
//    cout<<l.Empty()<<"\n";
//    l.AddItems (3,4);
//    l.initialize(5);
//    cout<<l.Length()<<"\n";
//    l.deleteItem(2);
//    cout<<l.Length()<<"\n";


// You can create other ADTs of List using this code as template
    return 0;
}

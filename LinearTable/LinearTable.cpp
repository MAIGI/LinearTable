#include <iostream>
using namespace std;
/*
    顺序表
*/

#define MAX_SIZE 100

typedef struct 
{
    int* ElementEntry;
    int Length;
    int Size;
}LinearTable;

bool TableIsFull(LinearTable&InputLinearTable)
{
    if(InputLinearTable.Length==MAX_SIZE)
    {
        return true;
    }
        return false;
}

bool TableIsEmpty(LinearTable&InputLinearTable)
{
    if(InputLinearTable.Length==0)
    {
        return true;
    }
        return false;
}

bool InitTable(LinearTable&InputLinearTable)
{
    if(TableIsFull(InputLinearTable))
    {
        cout<<"线性表已满"<<endl;
    }
    InputLinearTable.ElementEntry=new int[MAX_SIZE];
    if(!InputLinearTable.ElementEntry)
    {
    return false;
    }
    InputLinearTable.Length=0;
    InputLinearTable.Size=MAX_SIZE;
    return true;
}

bool AddElementInTable(LinearTable&InputLinearTable,int Element)
{
    if(TableIsFull(InputLinearTable))
     {
        cout<<"线性表已满"<<endl;
        return false;
     }
    InputLinearTable.ElementEntry[InputLinearTable.Length]=Element;
    InputLinearTable.Length++;
    return true;
}

bool InsertElementInTable(LinearTable&InputLinearTable,int Position,int Element)
{
    if(TableIsFull(InputLinearTable))
    {
        return false;
    }
    if(Position<0||Position>InputLinearTable.Length)
    {
        return false;
    }
    if(Position==InputLinearTable.Length)
    {
        InputLinearTable.ElementEntry[Position] = Element;
        InputLinearTable.Length++;
        return true;
    }
    for(int i=InputLinearTable.Length-1;i>=Position;i--)
    {
        InputLinearTable.ElementEntry[i+1]=
        InputLinearTable.ElementEntry[i];
    }
    InputLinearTable.ElementEntry[Position]=Element;
    InputLinearTable.Length++;
    return true;
}

bool RemoveElementInTable(LinearTable&InputLinearTable,int Position)
{
    if(TableIsEmpty(InputLinearTable))
    {
        return false;
    }
    if(Position<0||Position>InputLinearTable.Length)
    {
        return false;
    }
    for(int i=Position;i<InputLinearTable.Length;i++)
    {
        InputLinearTable.ElementEntry[i-1]=InputLinearTable.ElementEntry[i];
    }
    InputLinearTable.Length--;
    return true;
}

void DestroyTable(LinearTable&InputLinearTable)
{
    if(InputLinearTable.ElementEntry)
    {
        delete []InputLinearTable.ElementEntry;
        InputLinearTable.Length=0;
        InputLinearTable.Size=0;
        cout<<"线性表已销毁"<<endl;
    }
}

void PrintTable(LinearTable&InputLinearTable)
{
    for(int i=0;i<InputLinearTable.Length;i++)
    {
        cout<<InputLinearTable.ElementEntry[i]<<" ";
    }
        cout<<endl;
}

int main()
{
   LinearTable _LinearTable; 
   InitTable(_LinearTable); //初始化线性表
 
   for (int i=0;i<5;i++)
   {
      cout<<"请输入你想放入到线性表中的数据"<<endl;
      int InputElement;
      cin>>InputElement;
      if(!AddElementInTable(_LinearTable,InputElement))
      {
        cout<<"添加元素失败"<<endl;
      }
   }
   
   PrintTable(_LinearTable); //打印线性表
   
   cout<<"请输入你想插入到线性表中的数据"<<endl;
   int InsertElement;
   cin>>InsertElement;
   if(!InsertElementInTable(_LinearTable,5,InsertElement))
   {
    cout<<"插入元素失败"<<endl;
   }
   
   PrintTable(_LinearTable); //打印线性表
   
   cout<<"请输入你想从线性表中的数据位置"<<endl;
      int RemoveElementPosition;
      cin>>RemoveElementPosition;
      if(!RemoveElementInTable(_LinearTable,RemoveElementPosition))
      {
       cout<<"删除元素失败"<<endl;
      }
      
      PrintTable(_LinearTable); //打印线性表
      
      DestroyTable(_LinearTable);   //销毁线性表
   
   system("pause");
   return 0;
}




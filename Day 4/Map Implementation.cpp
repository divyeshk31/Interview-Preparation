#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define f(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rf(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define s(n)                        scanf("%d",&n)
#define p(n)			    printf("%d\n",n)
#define sl(n)                       scanf("%lld",&n)
#define pl(n)			    printf("%lld\n",n)
#define ll long long int
class MapImp
{
private :
    map<int, string> mymap;
public:
    MapImp();
    ~MapImp();
    void insert_element();
    void delete_element();
    bool find(int);
    bool isEmpty();
    int mapsize();
    void display();
    void revdisplay();
    void clear();
};
unsigned int getInt(const char *prompt)
{
    int input,
        bad_count=0; 
    do
    {
      cout << prompt;
       cin >> input; 
    }
    while (input == 0 && bad_count < 3);
    return input;
}
 MapImp :: MapImp()
{
    cout<<"New Map created"<<endl;
}
 
MapImp :: ~MapImp()
{
    cout<<"Map destroyed..."<<endl;
}
 
void MapImp :: insert_element()
{
    int key;
    string value;
 
     key = getInt("\nEnter Key : ");
     
    if(find(key))
      cout<<"Warning : Duplicate Key!"<<endl;
 
    cout<<"\nEnter Value : ";
    cin>>value;
     
    mymap.insert(pair<int,string>(key, value));
}
 
void MapImp :: delete_element()
{
  int key;
    if(!isEmpty())
    {
         key = getInt("\nEnter Key of the value to be deleted: ");
        if(find(key))
          mymap.erase(key);
        else
          cout<<"Key not Found"<<endl;
    }
}
 
bool MapImp :: find(int key)
{
    if(!mymap.empty())
    {
        if(mymap.find(key)->first != key )
        {
          return false;
        }
        else
          return true;
    }
    return false;
}
 
bool MapImp :: isEmpty()
{
    if(mymap.empty())
    {
        cout<<"Map is empty ! ! !"<<endl;
        return true;
    }
    else
        return false;
}
 
int MapImp:: mapsize()
{
    return mymap.size();
}
 
void MapImp :: display()
{
    map <int, string>::iterator itr;
 
    for(itr = mymap.begin(); itr != mymap.end(); itr++)
    {
        cout << (*itr).first <<" = "<<(*itr).second<<endl;
    }
 
}
 
void MapImp :: clear()
{
    mymap.clear();
}
 
int main()
{
    MapImp m1, m2;
 
    m1.insert_element();
    m1.insert_element();
    m1.insert_element();
    m1.delete_element();
    m1.display();
    m2.insert_element();
    m2.insert_element();
    m2.insert_element();
    m2.display();
    m2.clear();
    m2.delete_element();
 
 getch();
 return 0;
}
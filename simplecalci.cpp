#include<iostream> 
using namespace std ;

class simple_calculator 
{  
    public :
     double a , b;
    public :
     void get_data ()
     {
        cout <<"Enter the first number : "<<endl;
        cin>>a;
        cout <<"Enter the second number : "<<endl;
        cin>>b;
     }

     double addition ()
     {
          return a+b;
     }

     double substraction ()
     {
          return a-b;
     }

     double multiplication ()
     {
          return a*b;
     }

     double division ()
     {
          if (b!= 0)
          {
            return a/b;
          }
          else 
          {
            cout<<"Division by zero error occured . Enter the value of second number other than zero. "<<endl;
            return 0;
          }
     }
};

int main()
{
    simple_calculator calc ;
    char ch ;
    char  continue_ch;
do{
    cout << "Basic Calculator" << endl;
    cout << "Choose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
   
   calc.get_data();

  cout<<"Enter your choice to perform operations(+,-,*,/) : "<<endl;
  cin>>ch;

  switch (ch)
  {
    case '+' :
    cout<<"Result is :"<<calc.addition()<<endl;
    break ;

    case '-' :
    cout<<"Result is :"<<calc.substraction()<<endl;
    break ;

    case '*' :
    cout<<"Result is :"<<calc.multiplication()<<endl;
    break ;

    case '/' :
    cout<<"Result is :"<<calc.division()<<endl;
    break ;

    default:
            cout << "Error: Invalid operation." << endl;
            break;
  } 

  cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continue_ch;
}while(continue_ch == 'y' || continue_ch == 'Y');

cout << "Thank you for using the calculator!" << endl;
  return 0;
}



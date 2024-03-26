#include<iostream>
#include<fstream>   //because we have to work on file so this library allows us to do so for file operations 
#include<sstream>   //this file provides template&types that enables interoperation btw stream buffers n string obbj
#include<string>

using namespace std;

int main()
{
    int a , i=0;
    string text,old, password1, password2, pass,name, password0, age, user, word, word1;
    string creds[2], cp[2];  
    
    cout<<"                  _________________            "<<endl;
    cout<<"                   SECURITY SYSTEM             "<<endl;
    cout<<"                  _________________            "<<endl;

    cout<<"________________________________________________"<<endl;
    cout<<"|                 1. Register                  |"<<endl;
    cout<<"|                 2. Login                     |"<<endl;
    cout<<"|                 3. Change password           |"<<endl;
    cout<<"|_________________4. End Program_______________|"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:-";
        cin>>a;
        switch (a)
        {
        case 1:{
            cout<<"_________________________________________"<<endl<<endl;
            cout<<"|---------------Register----------------|"<<endl;
            cout<<"|_______________________________________|"<<endl<<endl;
            cout<<"Please enter username:-";
            cin>>name;
            cout<<"Please enter the password:-";
            cin>>password0;
            cout<<"Please enter your age:-";
            cin>>age;
            //to store this info in file we are using-

            ofstream of1;
            of1.open("file.txt");
           if (of1.is_open()){
            of1<<name<<"\n";
            of1<<password0;
            cout<<"Registration successful"<<endl;
           }
            break;
        }
          case 2:{
                i=0;
             
            cout<<"_________________________________________"<<endl<<endl;
            cout<<"|------------------Login----------------|"<<endl;
            cout<<"|_______________________________________|"<<endl<<endl;
            
            ofstream of2;
            of2.open("file.txt");                 //opend the file
            cout<<"Please enter username:-";      //check whether same person entered
            cin>>user;
            cout<<"Please enter the password:-";
            cin>>pass;
            
            if (of2.is_open())   //of1 of2 are objts
            {
                while (!of2.eof()) //eof end of file funct - can detect when endo file reached it returns non zero when endoffile has been reached otherwise it will return zero
                {
                    while(getline(of2, text)) {  //getline to read file line by line
                        istringstream iss(text); //istringstream obj used to stream the string & store it using extraction operator
                        iss>>word;
                        creds[i]=word;
                        i++;
                    }
                    if (user==creds[0] && pass==creds[1]) //check if reg usernm pass is correct or not
                    {
                        cout<<"------Login Successful-----";
                        cout<<endl<<endl;
                        cout<<"Details : "<<endl;

                        cout<<"Username: "+ name<<endl;
                        cout<<"Password: "+ pass<<endl;
                        cout<<"Age: "+ age<<endl;

                    }
                    else{
                        cout<<endl<<endl;
                        cout<<"Incorrect Credentials"<<endl;
                        cout<<"|          1.Press 2 to Login               |"<<endl;
                        cout<<"|          2.Press 3 to change password     |"<<endl;
                       break;
                    }
                    
                }
                
            }
           break;
            

          }
           case 3:{
             i=0;

             cout<<"-------------------------Change Password-----------------------"<<endl;

             ifstream of0;
             of0.open("file.txt");
             cout<<"Enter the old password: -";
             cin>>old;
             if (of0.is_open())
             {
                while (of0.eof())
                {
                    while(getline(of0, text)){
                        istringstream iss(text);
                        iss>>word1;
                        cp[i]=word1;
                        i++;
                    }
                    if (old==cp[1])
                    {
                        of0.close();   //close the file

                        ofstream of1;        //write or close
                        if (of1.is_open())
                        {
                            cout<<"Enter your new password: -";
                            cin>>password1;
                            cout<<"Enter your password again: -";
                            cin>>password2;


                            if (password1==password2)
                            {
                                of1<<cp[0]<<"\n";
                                of1<<password1;
                                cout<<"Password changed successfully"<<endl;
                                }
                             else
                             {
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"Password do not match"<<endl;
                             }
                              
                        }
                        
                     } 
                    else
                    {
                        cout<<"Please enter a valid password"<<endl;
                        break;
                    }
                    
                }

                
             }
             break;
             
           }
           case 4:
           {
            cout<<"______________________________THANK YOU!______________________________";
            break;
           }
           default:
           cout<<"Enter a valid choice";
        }

    } 
    while (a!=4);
return 0;
    
}  
   

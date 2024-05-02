#include <iostream>
#include "PushButton.hpp"
#include "RadioButton.hpp"
#include "RedButton.hpp"

using std::cout, std::cin, std::endl;

int main()
{
    string inp_str;
    string butt_type;
    string butt_msg;
    Button* instance0 = nullptr;

    cout << "Enter a button you want to press (PushButton | RadioButton | RedButton) >: ";
    cin >> inp_str;

    if (inp_str == "PushButton")
    {
        cout << "Enter button type (RadioButton | RedButton) >: ";
        cin >> butt_type;
        if (butt_type == "PushButton")
        {
            instance0 = new PushButton(inp_str, butt_type);
        }
        else if (butt_type == "RadioButton")
        {
            cout << "Enter radio message >: ";
            cin >> butt_msg;
            instance0 = new RadioButton(inp_str, butt_msg);
        }
        else if (butt_type == "RedButton") instance0 = new RedButton(inp_str);
        else cout << "Error: Check your inputs!";
    } 

    else if (inp_str == "PushButton")
        {
            instance0 = new PushButton(inp_str, butt_type);
        }
    else if (inp_str == "RadioButton")
    {
        cout << "Enter radio message >: ";
        cin >> butt_msg;
        instance0 = new RadioButton(inp_str, butt_msg);
    }
    else if (inp_str == "RedButton") instance0 = new RedButton(inp_str);
    else cout << "Error: Check your inputs!";
    
    
    cout << instance0->click() << endl;
    delete instance0;
}

//   g++ main.cpp PushButton.cpp RadioButton.cpp RedButton.cpp -o button.exe
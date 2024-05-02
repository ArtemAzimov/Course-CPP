#include <iostream>
using std::string, std::endl, std::cerr, std::cout, std::cin;

class Button
{
protected:
    string inp_str;
public:
    Button(string inp_str) : inp_str(inp_str)
    { 
        cerr << "DEBUG: call constructor" << inp_str << endl;
    }

    virtual void click()
    {
        cerr << inp_str <<"::click()" << endl;
    }

    virtual ~Button()
    { 
        cerr << "DEBUG: call destructor" << inp_str << endl;
    }
};

class PushButton : public Button
{
public:
    PushButton()
    { 
        cerr << "DEBUG: call constructor PushButton" << endl;
    }

    virtual void click() override
    {
        cerr << "PushButton::click()" << endl;
    }

    ~PushButton()
    { 
        cerr << "DEBUG: call destructor PushButton" << endl;
    }
};

class RadioButton : public Button
{
public:
    RadioButton()
    { 
        cerr << "DEBUG: call constructor RadioButton" << endl;
    }

    virtual void click() override
    {
        cerr << "RadioButton::click()" << endl;
    }

    ~RadioButton()
    { 
        cerr << "DEBUG: call destructor RadioButton" << endl;
    }
};

class RedButton : public Button
{
public:
    RedButton() 
    {
        cerr << "DEBUG: call constructor RedButton" << endl;
    }

    virtual void click() override
    {
        cerr << "RedButton::click()" << endl;
    }

    ~RedButton()
    { 
        cerr << "DEBUG: call destructor RedButton" << endl;
    }
};

int main()
{
    string user_input;
    cout << "Enter desired BUTTON >: "; 
    cin >> user_input;

    Button* pointer = nullptr;
    if (user_input == "Button")
    {
        pointer = new Button;
        pointer->click();
    }
    if (user_input == "PushButton")
    {
        pointer = new PushButton;
        pointer->click();
    }
    if (user_input == "RadioButton")
    {
        pointer = new RadioButton;
        pointer->click();
    }
    if (user_input == "RedButton")
    {
        pointer = new RedButton;
        pointer->click();
    }
    else
        cerr << "Error: check your syntax (Button | PushButton | Button)" << endl;
    delete pointer;
}
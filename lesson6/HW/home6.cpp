#include <iostream>

using namespace std;

class Button
{
protected:
    string* _strButton;
public:
    Button(string strButton)
    { cerr << "DEBUG: call constructor Button" << endl;
        _strButton = new string[strButton.length()];
    }

    virtual void click()
    {
        cerr << "Button::click()" << endl;
    }

    virtual ~Button()
    { cerr << "DEBUG: call destructor Button" << endl;
        delete[] _strButton;
    }
};

class PushButton : public Button
{
protected:
    string* _strPushButton;
public:
    PushButton(string strButton, string strPushButton) : Button(strButton)
    { cerr << "DEBUG: call constructor PushButton" << endl;
        _strPushButton = new string[strPushButton.length()];
    }

    virtual void click() override
    {
        cerr << "PushButton::click()" << endl;
    }

    ~PushButton()
    { cerr << "DEBUG: call destructor PushButton" << endl;
        delete[] _strPushButton;
    }
};

class RadioButton : public Button
{
protected:
    string* _strRadioButton;
public:
    RadioButton(string strButton, string strRadioButton) : Button(strButton)
    { cerr << "DEBUG: call constructor RadioButton" << endl;
        _strRadioButton = new string[strRadioButton.length()];
    }

    virtual void click() override
    {
        cerr << "RadioButton::click()" << endl;
    }

    ~RadioButton()
    { cerr << "DEBUG: call destructor RadioButton" << endl;
        delete[] _strRadioButton;
    }
};

Button* virt(string s)
{
	if (s == "Button")
		return new Button("Button");
	if (s == "PushButton")
		return new PushButton("Button", "PushButton");
    if (s == "RadioButton")
        return new RadioButton("Button", "RadioButton");
    else
    {
        cerr << "Error: check your syntax (Button | PushButton | Button)" << endl;
        return 0; 
    }
}

int main()
{
    string user_input;
    cout << "Enter desired BUTTON >: "; 
    cin >> user_input;

    Button* pointer = nullptr;
    Button* pointer = virt(user_input);
    pointer->click();

    delete pointer;
}

/* Золотое правило — если класс может быть унаследован, деструктор базового класса должен быть виртуальным! */
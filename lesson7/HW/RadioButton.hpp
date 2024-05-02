#pragma once

#include "Button.hpp"

class RadioButton : public Button
{
    string butt_msg;
public:
    RadioButton(string inp_str, string butt_msg) : Button (inp_str), butt_msg(butt_msg) {}

    string click() override;

    ~RadioButton(){std::cout << "...Called destructor ~RadioButton";}
};
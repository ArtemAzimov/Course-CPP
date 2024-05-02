#pragma once

#include "Button.hpp"

class PushButton : public Button
{
    string butt_type;
public:
    PushButton(string inp_str, string butt_type) : Button (inp_str), butt_type(butt_type) {}

    string click() override;

    ~PushButton(){std::cout << "...Called destructor ~PushButton";}
};
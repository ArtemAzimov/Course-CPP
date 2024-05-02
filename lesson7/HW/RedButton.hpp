#pragma once

#include "Button.hpp"

class RedButton : public Button
{
public:
    RedButton(string inp_str) : Button (inp_str) {}

    string click() override;

    ~RedButton(){std::cerr << "...Called destructor ~RadioButton";}
};
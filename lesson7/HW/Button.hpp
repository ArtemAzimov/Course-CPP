#pragma once

#include <iostream>
#include <string>
using std::string;

class Button
{
protected:
    string inp_str;
public:
    Button(string inp_str) : inp_str(inp_str) {}

    virtual string click() = 0;

    virtual ~Button() = default;
};
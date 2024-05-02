#include "PushButton.hpp"

string PushButton::click()
{
    string out_str;
    out_str = "...." + inp_str + "::click() " + butt_type;
    return out_str;
}
//
// Created by snowiemischief on 20/12/22.
//

#include "Stack.h"

Crate *Stack::WhoOnTop()
{
    return &(Stack::_content.front());
}

void Stack::AddOnTop(Crate crate)
{
    std::list<Crate>* content = &(Stack::_content);
    content->push_front(crate);
}

void Stack::AddToBack(Crate crate)
{
    std::list<Crate>* content = &(Stack::_content);
    content->push_back(crate);
}

Crate Stack::PopFromTop()
{
    std::list<Crate>* content = &(Stack::_content);
    if (content->empty()) return *(new Crate());
    Crate crate = content->front();
    content->erase(std::begin(*content));
    return crate;
}

std::list<Crate> Stack::GetContent() { return Stack::_content; }
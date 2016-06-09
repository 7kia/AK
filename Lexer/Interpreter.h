#pragma once
#include <iostream>
#include <memory>

class CInterpreter
{
public:
    CInterpreter(std::ostream &output);
    ~CInterpreter();

    void					EnterLoop(std::istream &input);

private:
    class Impl;
    std::unique_ptr<Impl>	m_pImpl;
};

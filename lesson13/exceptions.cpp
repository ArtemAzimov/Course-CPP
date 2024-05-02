if ()
    throw something;


try
{
    {/* code */}
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
catch(...) // дефолтный кэтч
{
    uknown error
}

// библиотеки <except> и прочие, std::runtime_error

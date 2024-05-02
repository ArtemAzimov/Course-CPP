#pragma once
// Зависимость, которую мы будем имитировать
class Dependency {
public:
    virtual int GetValue(int a) const = 0;
};

class DependencyChild : public Dependency{
public:
    virtual int GetValue(int a) const { return 777; }
};

// Класс, использующий зависимость
class MyClass {
private:
    Dependency* dependency;

public:
    MyClass(Dependency* dep) : dependency(dep) {}

    int PerformOperation() {
        int value = dependency->GetValue(10);
        return value * 2;
    }
};

// Класс мок-объекта (имитации зависимости)
class MockDependency : public Dependency {
public:
    // MOCK_CONST_METHOD(GetValue, int(int));
    MOCK_METHOD(int, GetValue, (int), (const));
};
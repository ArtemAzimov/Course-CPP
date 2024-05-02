template <typename T>
class smartptr
{
private:
    int* count;
    T* value;
public:
    smartptr();
    void reset();
    int count() const;
    ~smartptr();
};


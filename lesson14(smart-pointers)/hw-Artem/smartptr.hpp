template <typename T>
class SmartPointer {
public:
    SmartPointer(T* ptr = nullptr) {
        if (ptr != nullptr) {
            m_ptr = ptr;
            m_refCount = new int(1);
        }
    }

    SmartPointer(const SmartPointer<T>& other) {
        m_ptr = other.m_ptr;
        m_refCount = other.m_refCount;
        (*m_refCount)++;
    }

    ~SmartPointer() {
        (*m_refCount)--;
        if (*m_refCount == 0) {
            delete m_ptr;
            delete m_refCount;
        }
    }

    SmartPointer<T>& operator=(const SmartPointer<T>& other) {
        if (this == &other) {
            return *this;
        }

        (*m_refCount)--;
        if (*m_refCount == 0) {
            delete m_ptr;
            delete m_refCount;
        }

        m_ptr = other.m_ptr;
        m_refCount = other.m_refCount;
        (*m_refCount)++;

        return *this;
    }

    T& operator*() {
        return *m_ptr;
    }

    T* operator->() {
        return m_ptr;
    }

private:
    T* m_ptr = nullptr;
    int* m_refCount = nullptr;
};
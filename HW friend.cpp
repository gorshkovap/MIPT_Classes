#include <iostream>


class Friend;

class Key {
    friend class Friend;
    Key() {};
};

class Alt {
public:
    void protectedMethod(Key) {
        Method();
    }
private:
    int value;
    void Method();
};

class Friend {
    void DoProtectedMethod(Alt& alt) {
        alt.protectedMethod(Key());
    }
};


int main(int argc, const char* argv[]) {
    return 0;
}

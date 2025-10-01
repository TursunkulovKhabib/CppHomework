#include <cassert>

class Entity {
private:
    int private_value;

    int private_function_1(int x) const {
        return x * 2;
    }

    bool private_function_2(int a, int b) const {
        return a > b;
    }

    friend class EntityTest1;
    friend class EntityTest2;

public:
    Entity(int val) : private_value(val) {}
};

class EntityTest1 {
private:
    static int test_private_function_1(const Entity& entity, int x) {
        return entity.private_function_1(x);
    }

    friend class TestRunner1;
};

class EntityTest2 {
private:
    static bool test_private_function_2(const Entity& entity, int a, int b) {
        return entity.private_function_2(a, b);
    }

    friend class TestRunner2;
};

class TestRunner1 {
public:
    static void run_tests() {
        Entity entity(10);
        
        assert(EntityTest1::test_private_function_1(entity, 5) == 10);
        assert(EntityTest1::test_private_function_1(entity, 0) == 0);
        assert(EntityTest1::test_private_function_1(entity, -3) == -6);
    }
};

class TestRunner2 {
public:
    static void run_tests() {
        Entity entity(10);
        
        assert(EntityTest2::test_private_function_2(entity, 5, 3) == true);
        assert(EntityTest2::test_private_function_2(entity, 2, 7) == false);
        assert(EntityTest2::test_private_function_2(entity, 4, 4) == false);
    }
};

int main() {
    TestRunner1::run_tests();
    TestRunner2::run_tests();
    return 0;
}

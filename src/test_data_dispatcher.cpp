
#include "DataDispatcher.hpp"

class Test {
    public:
        void test_int(const int& data) {
            std::cout << "test  int callback, data: " <<data <<std::endl;
        }
};

int main() {
    Test test; 
    util::Subscriber  subscriber = util::DataDispatcher::GetInstance().Subscribe("int_data", &Test::test_int, &test, 5);
    // 1、测试数据容器
    // 证明 typeid() 不区分const 和 & 
    std::type_index type_info(typeid(const float&));  // 数据类型信息 
    std::type_index type_info2(typeid(float));  // 数据类型信息 
    if (type_info == type_info2) {
        std::cout << "type_info == type_info2" << std::endl;
    }

    while(1) {
        util::DataDispatcher::GetInstance().Publish("int_data", 100);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 1; 
}
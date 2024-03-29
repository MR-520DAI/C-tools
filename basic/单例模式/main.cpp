#include <string>
#include <iostream>

using namespace std;

class Constant
{
public:
    static Constant* get_instance(){
        if (const_variables == nullptr){
            const_variables = new Constant();
        }
        return const_variables;
    }

    void print(){
        cout<<"name:"<<name_<<" age:"<<age_<<endl;
        return;
    }
    ~Constant(){
        if (Constant::const_variables){
            cout<<"析构\n";
        } 
    }
    
private:
    int age_;
    string name_;
    Constant(){
        age_ = 29;
        name_ = "DZY";
    }
    static Constant* const_variables;

    // 浅拷贝复制
    Constant(const Constant&) = default;
    Constant& operator=(const Constant&) = default;

    // 自动析构Constant
    class XG
    {
    public:
        ~XG(){
            if (Constant::const_variables){
                delete Constant::const_variables;
            } 
        }
    };
    static XG xg;
};

Constant* Constant::const_variables = nullptr;
Constant::XG Constant::xg;

int main()
{
    auto c = Constant::get_instance();
    c->print();

    auto b = c;

    return 0;
}
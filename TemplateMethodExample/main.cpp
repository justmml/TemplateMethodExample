//
//  main.cpp
//  TemplateMethodExample
//
//  Created by Mac on 18.05.2020.
//  Copyright © 2020 justmml. All rights reserved.
//

#include <iostream>

class AbstractGuy {
  
public:
    void TemplateMethod() const {
        this->BaseStand();
        this->BaseWatch();
        this->RequiredSpeak();
        this->HookStartFight();
    }
    
protected:
    void BaseStand() const {
        std::cout << "I'm standing here like a tree\n";
    }
    
    void BaseWatch() const {
        std::cout << "I'm watching you, stranger\n";
    }
    
    virtual void RequiredSpeak() const = 0;
    
    virtual void HookStartFight() const {};
};

class KindGuy : public AbstractGuy {
protected:
    void RequiredSpeak() const override {
        std::cout << "Hello dear stranger, take care\n";
    }
};

class EvilGuy : public AbstractGuy {
protected:
    void RequiredSpeak() const override {
        std::cout << "Hello motherf**r! Give me your money!'n";
    }
    void HookStartFight() const override {
        std::cout << "You're attacked!\n";
    }
};

void ClientCode(AbstractGuy *class_) {
    class_->TemplateMethod();
}

int main(int argc, const char * argv[]) {
    
    KindGuy *kindGuy = new KindGuy;
    ClientCode(kindGuy);
    std::cout << "\n";
    EvilGuy *evilGuy = new EvilGuy;
    ClientCode(evilGuy);
    
    delete kindGuy;
    delete evilGuy;
    
    return 0;
}

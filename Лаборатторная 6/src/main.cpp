#include <iostream>
#include "list.h"

using namespace std;

int main(){
    Queue queue(1);
    Stack stack(1);
    for(int j = 2; j < 11; j++){
        queue.add(&j);
        stack.add(&j);
    }

    for(int j = 0; j < 11; j++){
        queue.pop();
        stack.pop();
    }
    return 0;
}
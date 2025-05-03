'#include <iostream>

using namespace std;

template<class T>
class UniquePointer {

public:
UniquePointer(T *ptr) : mPtr(ptr) {
    cout<<"UniquePointer Constructor called"<<endl;
}

UniquePointer(const UniquePointer &other) = delete; // Copy constructor is deleted
UniquePointer& operator=(const UniquePointer &other) = delete; // Copy assignment operator is deleted
UniquePointer(UniquePointer &&other) {
    cout<<"UniquePointer Move Constructor called"<<endl;
    mPtr = other.mPtr;
    other.mPtr = nullptr;
}
UniquePointer& operator=(UniquePointer &&other) {
    if(this !=&other){
        delete mPtr;
        mPtr = other.mPtr;
        other.mPtr =nullptr;
    }
    return *this;
}

T *Release(){
    T*temp = mPtr;
    mPtr = nullptr;
    return temp;
}

T* get()const{
    return mPtr;
}
void reset(){
    mPtr = nullptr;
}

void reset(T *ptr){
    if(mPtr != nullptr){
        delete mPtr;
    }
    mPtr = ptr;
}
void swap(T &other){
   
     T*temp = mPtr;
     mPtr = other.mPtr;
     other.mPtr = temp;
}

T& operator*(){
    return *mPtr;
}

T*operator->(){
    return mPtr;
}
~UniquePointer(){
    cout<<"UniquePointer Destructor called"<<endl;
    delete mPtr; // this is Resource Management
}
private:
       T *mPtr;
};

int main(int argc ,char *argv[]){

    cout<<"Samrt Pointers std::unique_ptr Implmentation"<<endl;
    UniquePointer<int> uptr(new int(10));

   
    return 0;
}

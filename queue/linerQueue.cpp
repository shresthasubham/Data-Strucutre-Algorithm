#include <iostream>
#define SIZE 10
using namespace std;
template<class T>
class Queue {
private:
T items[SIZE];
int front, end;
public:
Queue() {
front = 0;
end=-1;
}
bool isEmpty() {
return (front> end);
}
void enqueue(T item) {
  if(isFull())
     throw"queue overflow";
    end++;
   items[end] = item;
}
T dequeue() {
if (isEmpty()) 
  throw "queue Underflow";
return items[front++];
}
bool isFull(){
  return (end>SIZE-1);
}
};
int main() {
Queue<int> q;
try{
for (int i = 0; i < 3; i++){
cout<<"enqueue sucess\n";

q.enqueue(i);}
while (!q.isEmpty())
{
cout << q.dequeue();
}
}
catch (const char* err) {
cout << err;
}
return 0;
}

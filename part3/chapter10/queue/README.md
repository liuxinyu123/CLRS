#NOTE    
利用数组来实现队列     
Queue类中有三个成员变量：    
1. array 动态分配的数组    
2. head  表示队首位置   
3. tail  表示队尾元素下一个位置   

此队列是循环的
空： head == tail
满： head+1 == tail  

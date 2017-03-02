#NOTE   
用指针实现栈   
类Stack有三个成员变量：    
1. capacity  表示容量   
2. bottom  指针表示栈底   
3. first_empty  指针表示栈顶上一位置   

空：  bottom == first_empty   
满： first_empty - bottom == capacity	 

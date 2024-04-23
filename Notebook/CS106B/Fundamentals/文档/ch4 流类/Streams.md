---

感觉需要重新审视，写的并不足够好。

# Defination

"Designing and implementing **a general input/output facility for** a programming language is notoriously difficult C++" - a stream :)

> an abstraction for input/output.Streams convert between data and the string representation of data.

# Model（生产者-消费者）
Stream的模型类似于一个buffer。通过运算符">>","<<"可以改变读写指针的位置。
```cpp
int main(){
    ostringstream oss("Ito En Green Tea ", stringstream::ate);
    cout << oss.str() << endl;
    oss << 16.9 << "Ounce ";
    cout << oss.str() << endl;
    return 0;
}
```
通过可选的参数modes，可以改变流的模式。例如，ate(start at end), bin(read as binary).
>>提取运算符的正确语义是从流中读取一个token。
# 自己实现一个stringToInteger
```cpp
int stringToInteger(const std::string& s){
	std::istringstream iss(s);
	int result = 0;
    iss >> result;
    return result;
}
```
## 如何应对坏的输入？

1. Good bit:ready for read/write. Nothing unusual, on when other bits are off. 
2. Fail bit:previous operation failed, all future operations frozen.  Type mismatch, file can't be opened, seekg failed. 
3. EOF bit:previous operation reached the end of buffer content. Reached the end of the buffer.
4. Bad bit:external error, likely irrecoverable. Could not move characters to buffer from external source. (e.g. the file you are reading from suddenly is deleted) .
```cpp
void showStateBit(std::istream &is){
    cout << is.good() ? "GOOD" : "____";
    cout << is.fail() ? "FAIL" : "____";
    cout << is.eof()  ? "END " : "____";
    cout << is.bad()  ? "BAD " : "____";
}
```
## 一个更加健壮的版本
```cpp
int stringToInteger(const std::string& s){
	std::istringstream iss(s);
	int result = 0;
    iss >> result;
    if (iss.fail())
        throw std::domain_error("no value int at beginning!");
    char remain;
    iss >> remain;
    if (iss.fail()) // 等价写法 if(!iss.eof())
        throw std::domain_error("more than a single valid int");
    return result;
}
```
等价写法，由于流会返回流对象?----> 疑问，返回什么样的流对象？
```cpp
int stringToInteger(const std::string& s){
	std::istringstream iss(s);
	int result = 0;
    if (!(iss >> result))
        throw std::domain_error("no value int at beginning!");
    char remain;
    if (iss >> remain;) 
        throw std::domain_error("more than a single valid int");
    return result;
}
```
# Cout vs Cerr vs Clog 带缓冲的读写
由于flush操作会降低I/O的性能，所以说版本1会比版本2慢一点。RIO包中有类似的实现
```cpp
// Version 1:
for (const auto& x: array){
    cout << x << endl;
}
// Version 2:
for (const auto& x: array){
    cout << x << "\n";
}
cout << endl;
```
[RIO包](https://www.yuque.com/imcjlzc/qqdee2/wq590r?inner=azn97&view=doc_embed)

## 会触发flush的操作
```cpp
std::endl // 插入新一行，并且刷新流
std::ws // 跳过所有的空白，直到一个不是空白的字符。
std::boolalpha // 将bool变量在命令行中打印true，false。
std::hex // 将数字以16进制显示
std::setpercision // 调整打印精度。
```
除此之外，在进行一个读操作前，会保证之前所有的写入会被正确的运行。
# 一些无聊的流定位API
![image.png](https://cdn.nlark.com/yuque/0/2022/png/25607809/1666068953839-075340c4-e3c7-447e-ae3a-4e9764a7d69e.png#averageHue=%232e2e2e&clientId=ucb8b1b22-b469-4&from=paste&height=384&id=ysfi8&originHeight=543&originWidth=976&originalType=binary&ratio=1&rotation=0&showTitle=false&size=187200&status=done&style=none&taskId=u2a7f4cb6-d6a0-4aa4-aeb4-3bdc388f93d&title=&width=690.9734396643606)
